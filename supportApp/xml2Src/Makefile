TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================


ifeq ($(XML2_EXTERNAL),NO)

  LIBRARY = xml2

  ifeq ($(WITH_ZLIB),YES)
    ifeq ($(ZLIB_EXTERNAL),NO)
      USR_CFLAGS_WIN32 += -DHAVE_ZLIB_H
      LIB_LIBS += zlib
    endif # ($(ZLIB_EXTERNAL),NO)
  endif # ($(WITH_ZLIB),YES)

  USR_CFLAGS_WIN32 += -DWIN32
  ifeq ($(SHARED_LIBRARIES),YES)
    USR_CFLAGS += -DPIC -DNOLIBTOOL
  endif
  xml2_SYS_LIBS_WIN32 += ws2_32

  # Need _REENTRANT flag on Linux for threads to build correctly
  USR_CFLAGS_Linux += -D_REENTRANT
  
  INC_WIN32 += win32config.h
  INC_WIN32 += wsockcompat.h
  INC_Darwin += config.h
  INC_Linux += config_32.h
  INC_Linux += config_64.h
  INC += libxml/DOCBparser.h
  INC += libxml/globals.h 
  INC += libxml/tree.h
  INC += libxml/xmlregexp.h
  INC += libxml/HTMLparser.h
  INC += libxml/HTMLtree.h
  INC += libxml/SAX.h
  INC += libxml/SAX2.h
  INC += libxml/c14n.h
  INC += libxml/catalog.h
  INC += libxml/chvalid.h
  INC += libxml/debugXML.h
  INC += libxml/dict.h
  INC += libxml/encoding.h
  INC += libxml/entities.h
  INC += libxml/hash.h
  INC += libxml/list.h
  INC += libxml/nanoftp.h
  INC += libxml/nanohttp.h
  INC += libxml/parser.h
  INC += libxml/parserInternals.h
  INC += libxml/pattern.h
  INC += libxml/relaxng.h
  INC += libxml/schemasInternals.h
  INC += libxml/schematron.h
  INC += libxml/threads.h
  INC += libxml/uri.h
  INC += libxml/valid.h
  INC += libxml/xinclude.h
  INC += libxml/xlink.h
  INC += libxml/xmlIO.h
  INC += libxml/xmlautomata.h
  INC += libxml/xmlerror.h
  INC += libxml/xmlexports.h
  INC += libxml/xmlmemory.h
  INC += libxml/xmlreader.h
  INC += libxml/xmlsave.h
  INC += libxml/xmlschemas.h
  INC += libxml/xmlschemastypes.h
  INC += libxml/xpointer.h
  INC += libxml/xmlstring.h
  INC += libxml/xmlunicode.h
  INC += libxml/xmlversion.h
  INC += libxml/xmlwriter.h
  INC += libxml/xpath.h
  INC += libxml/xpathInternals.h
  INC += libxml/xmlmodule.h

  LIB_SRCS += buf.c
  LIB_SRCS += c14n.c
  LIB_SRCS += catalog.c
  LIB_SRCS += chvalid.c
  LIB_SRCS += debugXML.c
  LIB_SRCS += dict.c
  LIB_SRCS += DOCBparser.c
  LIB_SRCS += encoding.c
  LIB_SRCS += entities.c
  LIB_SRCS += error.c
  LIB_SRCS += globals.c
  LIB_SRCS += hash.c
  LIB_SRCS += HTMLparser.c
  LIB_SRCS += HTMLtree.c
  LIB_SRCS += legacy.c
  LIB_SRCS += list.c
  LIB_SRCS += nanoftp.c
  LIB_SRCS += nanohttp.c
  LIB_SRCS += parser.c
  LIB_SRCS += parserInternals.c
  LIB_SRCS += pattern.c
  LIB_SRCS += relaxng.c
  LIB_SRCS += SAX2.c
  LIB_SRCS += SAX.c
  LIB_SRCS += schematron.c
  LIB_SRCS += threads.c
  LIB_SRCS += tree.c
  LIB_SRCS += uri.c
  LIB_SRCS += valid.c
  LIB_SRCS += xinclude.c
  LIB_SRCS += xlink.c
  LIB_SRCS += xmlIO.c
  LIB_SRCS += xmlmemory.c
  LIB_SRCS += xmlreader.c
  LIB_SRCS += xmlregexp.c
  LIB_SRCS += xmlmodule.c
  LIB_SRCS += xmlsave.c
  LIB_SRCS += xmlschemas.c
  LIB_SRCS += xmlschemastypes.c
  LIB_SRCS += xmlunicode.c
  LIB_SRCS += xmlwriter.c
  LIB_SRCS += xpath.c
  LIB_SRCS += xpointer.c
  LIB_SRCS += xmlstring.c

endif # ($(XML2_EXTERNAL),NO)


include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

