#ifndef LZ4HDF5_H
#define LZ4HDF5_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

epicsShareFunc size_t decompress_lz4hdf5(const char *inbuf, char *outbuf, size_t maxOutputSize);
epicsShareFunc size_t compress_lz4hdf5(const char *inbuf, char *outbuf, size_t nbytes, size_t maxOutputSize);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LZ4HDF5_H */