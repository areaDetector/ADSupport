#ifndef LZ4HDF5_H
#define LZ4HDF5_H

#include <shareLib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

epicsShareFunc size_t decompress_lz4hdf5(const char *inbuf, char *outbuf, size_t maxOutputSize, size_t *blockSize);
epicsShareFunc size_t compress_lz4hdf5(const char *inbuf, char *outbuf, size_t nbytes, size_t maxOutputSize, size_t blockSize);
epicsShareFunc size_t lz4hdf5_compressBound(size_t nbytes, size_t *blockSize, size_t *nBlocks);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LZ4HDF5_H */