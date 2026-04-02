/*
 * This file implements lz4 compression/decompression where the data
 * has a 12-byte header that specified the block size and other information
 * It is different from the lz4 compression in ADSupport that does not have this header
 * This file is needed because Dectris Stream2 sends lz4 data with smaller block size than
 * the default, so the lz4 decompression won't work.
 * 
 * This code is modified from H5Zlz4.c in the HDF5 library.
 */

#include <sys/types.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#if defined(_WIN32)
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif
#include <lz4.h>
#include <epicsExport.h>
#include <lz4hdf5.h>

#define htonll(x) ( ( (uint64_t)(htonl( (uint32_t)((x << 32) >> 32)))<< 32) | htonl( ((uint32_t)(x >> 32)) ))
#define ntohll(x) htonll(x)

#define htobe16t(x) htons(x)
#define htobe32t(x) htonl(x)
#define htobe64t(x) htonll(x)
#define be16toht(x) ntohs(x)
#define be32toht(x) ntohl(x)
#define be64toht(x) ntohll(x)


#define DEFAULT_BLOCK_SIZE 1<<30; /* 1GB. LZ4 needs blocks < 1.9GB. */

epicsShareFunc size_t decompress_lz4hdf5(const char *inbuf, char *outbuf, size_t maxOutputSize)
{
    size_t ret_value;

    uint32_t *i32Buf;
    uint32_t blockSize;
    char *roBuf;   /* pointer to current write position */
    uint64_t decompSize;
    const char* rpos = inbuf; /* pointer to current read position */
    const uint64_t * const i64Buf = (uint64_t *) rpos;
    const uint64_t origSize = (uint64_t)(be64toht(*i64Buf));/* is saved in be format */
    if (origSize > maxOutputSize) {
        printf("maxOutputSize=%d too small, needs to be at least %d\n", (int)maxOutputSize, (int)origSize);
        return 0;
    }
    rpos += 8; /* advance the pointer */

    i32Buf = (uint32_t*)rpos;
    blockSize = (uint32_t)(be32toht(*i32Buf));
    rpos += 4;
    if(blockSize>origSize)
        blockSize = (uint32_t)origSize;

    roBuf = (char*)outbuf;   /* pointer to current write position */
    decompSize     = 0;
    /// start with the first block ///
    while(decompSize < origSize)
    {
        uint32_t compressedBlockSize;  /// is saved in be format

        if(origSize-decompSize < blockSize) /* the last block can be smaller than blockSize. */
            blockSize = (uint32_t)(origSize-decompSize);
        i32Buf = (uint32_t*)rpos;
        compressedBlockSize =  be32toht(*i32Buf);  /// is saved in be format
        rpos += 4;
        if(compressedBlockSize == blockSize) /* there was no compression */
        {
            memcpy(roBuf, rpos, blockSize);
        }
        else /* do the decompression */
        {
#if LZ4_VERSION_NUMBER > 10300
            int compressedBytes = LZ4_decompress_fast(rpos, roBuf, blockSize);
#else
            int compressedBytes = LZ4_uncompress(rpos, roBuf, blockSize);
#endif
            if(compressedBytes != compressedBlockSize)
            {
                printf("decompressed size not the same: %d, != %d\n", compressedBytes, compressedBlockSize);
                return 0;
            }
        }

        rpos += compressedBlockSize;   /* advance the read pointer to the next block */
        roBuf += blockSize;            /* advance the write pointer */
        decompSize += blockSize;
    }
    ret_value = (size_t)origSize;  // should always work, as orig_size cannot be > 2GB (sizeof(size_t) < 4GB)
    return ret_value;
}

epicsShareFunc size_t compress_lz4hdf5(const char *inbuf, char *outbuf, size_t nbytes, size_t maxOutputSize)
{
    size_t blockSize;
    size_t nBlocks;
    size_t outSize; /* size of the output buffer. Header size (12 bytes) is included */
    size_t block;
    uint64_t *i64Buf;
    uint32_t *i32Buf;
    size_t maxDestSize;
    const char *rpos;      /* pointer to current read position */
    char *roBuf;    /* pointer to current write position */

    if (nbytes > INT32_MAX)
    {
        /* can only compress chunks up to 2GB */
        return 0;
    }

    blockSize = DEFAULT_BLOCK_SIZE;
    if(blockSize > nbytes)
    {
        blockSize = nbytes;
    }
    nBlocks = (nbytes-1)/blockSize +1;
    maxDestSize = LZ4_compressBound((int)nbytes) + 4 + 8 + nBlocks*4;
    if (maxDestSize > maxOutputSize) {
        printf("maxOutputSize=%d too small, needs to be at least %d\n", (int)maxOutputSize, (int)maxDestSize);
        return 0;
    }

    rpos  = inbuf;      /* pointer to current read position */
    roBuf = outbuf;    /* pointer to current write position */
    /* header */
    i64Buf = (uint64_t *) (roBuf);
    i64Buf[0] = htobe64t((uint64_t)nbytes); /* Store decompressed size in be format */
    roBuf += 8;

    i32Buf =  (uint32_t *) (roBuf);
    i32Buf[0] = htobe32t((uint32_t)blockSize); /* Store the block size in be format */
    roBuf += 4;

    outSize = 12; /* size of the output buffer. Header size (12 bytes) is included */

    for(block = 0; block < nBlocks; ++block)
    {
        uint32_t compBlockSize; /// reserve space for compBlockSize
        size_t origWritten = block*blockSize;
        if(nbytes - origWritten < blockSize) /* the last block may be < blockSize */
            blockSize = nbytes - origWritten;

#if LZ4_VERSION_NUMBER > 10300
        compBlockSize = LZ4_compress_default(rpos, roBuf+4, (int)blockSize, (int)(maxDestSize-outSize)); /// reserve space for compBlockSize
#else
        compBlockSize = LZ4_compress(rpos, roBuf+4, blockSize); /// reserve space for compBlockSize
#endif
        if(!compBlockSize)
            return 0;
        if(compBlockSize >= blockSize) /* compression did not save any space, do a memcpy instead */
        {
            compBlockSize = (uint32_t)blockSize;
            memcpy(roBuf+4, rpos, blockSize);
        }

        i32Buf =  (uint32_t *) (roBuf);
        i32Buf[0] = htobe32t((uint32_t)compBlockSize);  /* write blocksize */
        roBuf += 4;

        rpos += blockSize;     	/* advance read pointer */
        roBuf += compBlockSize;       /* advance write pointer */
        outSize += compBlockSize + 4;
    }

    return outSize;

}

