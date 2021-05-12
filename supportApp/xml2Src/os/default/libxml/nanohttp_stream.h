/*
 * Summary: minimal HTTP implementation
 * Description: minimal HTTP implementation allowing to fetch resources
 *              like external subset.
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __NANO_HTTP_STREAM_H__
#define __NANO_HTTP_STREAM_H__

#include <libxml/xmlversion.h>

#ifdef LIBXML_HTTP_ENABLED

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	Idle, FoundStart, Complete, Error
} xmlNanoFrameStates;

XMLPUBFUN void XMLCALL
	xmlNanoHTTPStreamInit		(void);
XMLPUBFUN void XMLCALL
	xmlNanoHTTPStreamCleanup	(void);
XMLPUBFUN void XMLCALL
	xmlNanoHTTPStreamScanProxy	(const char *URL);
XMLPUBFUN int XMLCALL
	xmlNanoHTTPStreamFetch	(const char *URL,
				 const char *filename,
				 char **contentType);
XMLPUBFUN void * XMLCALL
	xmlNanoHTTPStreamMethod	(const char *URL,
				 const char *method,
				 const char *input,
				 char **contentType,
				 const char *headers,
				 int   ilen);
XMLPUBFUN void * XMLCALL
	xmlNanoHTTPStreamMethodRedir	(const char *URL,
				 const char *method,
				 const char *input,
				 char **contentType,
				 char **redir,
				 const char *headers,
				 int   ilen);
XMLPUBFUN void * XMLCALL
	xmlNanoHTTPStreamOpen		(const char *URL,
				 char **contentType);
XMLPUBFUN void * XMLCALL
	xmlNanoHTTPStreamOpenRedir	(const char *URL,
				 char **contentType,
				 char **redir);
XMLPUBFUN int XMLCALL
	xmlNanoHTTPStreamReturnCode	(void *ctx);
XMLPUBFUN const char * XMLCALL
	xmlNanoHTTPStreamAuthHeader	(void *ctx);
XMLPUBFUN const char * XMLCALL
	xmlNanoHTTPStreamRedir	(void *ctx);
XMLPUBFUN int XMLCALL
	xmlNanoHTTPStreamContentLength( void * ctx );
XMLPUBFUN const char * XMLCALL
	xmlNanoHTTPStreamEncoding	(void *ctx);
XMLPUBFUN const char * XMLCALL
	xmlNanoHTTPStreamMimeType	(void *ctx);
XMLPUBFUN int XMLCALL
	xmlNanoHTTPStreamRead		(void *ctx,
				 void *dest,
				 int len);
XMLPUBFUN xmlNanoFrameStates XMLCALL
	xmlNanoHTTPFrameState	(void *ctx);
XMLPUBFUN int XMLCALL
	xmlNanoHTTPStreaming	(void *ctx);
#ifdef LIBXML_OUTPUT_ENABLED
XMLPUBFUN int XMLCALL
	xmlNanoHTTPStreamSave		(void *ctxt,
				 const char *filename);
#endif /* LIBXML_OUTPUT_ENABLED */
XMLPUBFUN void XMLCALL
	xmlNanoHTTPStreamClose	(void *ctx);
#ifdef __cplusplus
}
#endif

#endif /* LIBXML_HTTP_ENABLED */
#endif /* __NANO_HTTP_H__ */
