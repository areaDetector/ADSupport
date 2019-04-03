TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# Unset STATIC_BUILD if it was set because we need to create loadable libraries
STATIC_BUILD = NO

ifeq ($(WITH_HDF5),YES)
  ifeq ($(HDF5_EXTERNAL),NO)

    LIBRARY_IOC = hdf5
    PROD_IOC    = H5detect

    USR_CFLAGS += -D NDEBUG
    USR_CFLAGS_Linux += -std=c99
    ifeq ($(SHARED_LIBRARIES), YES)
      USR_CFLAGS_WIN32 += -D H5_BUILT_AS_DYNAMIC_LIB 
      USR_CFLAGS_WIN32 += -D hdf5_shared_EXPORTS
      ifeq (mingw, $(findstring mingw, $(T_A)))
        USR_CFLAGS_WIN32 += -D__MSVCRT_VERSION__=0x800
      else
        # The thread code on mingw needs work, get compiler errors
        USR_CFLAGS_WIN32 += -D H5_HAVE_THREADSAFE
      endif
    endif

    INC += H5ACpublic.h
    INC += H5api_adpt.h
    INC += H5Apublic.h
    INC += H5B2public.h
    INC += H5Bpublic.h
    INC += H5Cpublic.h
    INC += H5Dpublic.h
    INC += H5Epubgen.h
    INC += H5Epublic.h
    INC += H5FDcore.h
    INC += H5FDdirect.h
    INC += H5FDfamily.h
    INC += H5FDlog.h
    INC += H5FDmpi.h
    INC += H5FDmpio.h
    INC += H5FDmulti.h
    INC += H5FDpublic.h
    INC += H5FDsec2.h
    INC += H5FDstdio.h
    INC += H5FDwindows.h
    INC += H5FSpublic.h
    INC += H5Fpublic.h
    INC += H5Gpublic.h
    INC += H5HFpublic.h
    INC += H5HGpublic.h
    INC += H5HLpublic.h
    INC += H5Ipublic.h
    INC += H5Lpublic.h
    INC += H5MMpublic.h
    INC += H5Opublic.h
    INC += H5overflow.h
    INC += H5PLextern.h
    INC += H5PLpublic.h
    INC += H5Ppublic.h
    INC += H5public.h
    INC += H5Rpublic.h
    INC += H5Spublic.h
    INC += H5Tpublic.h
    INC += H5version.h
    INC += H5Zpublic.h
    INC += hdf5.h
    INC += H5pubconf.h
    INC_Linux +=  H5pubconf_32.h
    INC_Linux +=  H5pubconf_64.h

    INC_vxWorks += H5vxWorks.h 

    hdf5_SRCS += H5.c
    hdf5_SRCS += H5checksum.c
    hdf5_SRCS += H5dbg.c
    hdf5_SRCS += H5system.c
    hdf5_SRCS += H5timer.c
    hdf5_SRCS += H5trace.c
    hdf5_SRCS += H5A.c
    hdf5_SRCS += H5Abtree2.c
    hdf5_SRCS += H5Adense.c
    hdf5_SRCS += H5Adeprec.c
    hdf5_SRCS += H5Aint.c
    hdf5_SRCS += H5Atest.c
    hdf5_SRCS += H5AC.c
    hdf5_SRCS += H5AClog.c
    hdf5_SRCS += H5ACdbg.c
    hdf5_SRCS += H5ACproxy_entry.c
    hdf5_SRCS += H5B.c
    hdf5_SRCS += H5Bcache.c
    hdf5_SRCS += H5Bdbg.c
    hdf5_SRCS += H5B2.c
    hdf5_SRCS += H5B2cache.c
    hdf5_SRCS += H5B2dbg.c
    hdf5_SRCS += H5B2hdr.c
    hdf5_SRCS += H5B2int.c
    hdf5_SRCS += H5B2internal.c
    hdf5_SRCS += H5B2leaf.c
    hdf5_SRCS += H5B2stat.c
    hdf5_SRCS += H5B2test.c
    hdf5_SRCS += H5C.c
    hdf5_SRCS += H5Cdbg.c
    hdf5_SRCS += H5Cepoch.c
    hdf5_SRCS += H5Cimage.c
    hdf5_SRCS += H5Clog.c
    hdf5_SRCS += H5Cprefetched.c
    hdf5_SRCS += H5Cquery.c
    hdf5_SRCS += H5Ctag.c
    hdf5_SRCS += H5Ctest.c
    hdf5_SRCS += H5CS.c
    hdf5_SRCS += H5D.c
    hdf5_SRCS += H5Dbtree.c
    hdf5_SRCS += H5Dbtree2.c
    hdf5_SRCS += H5Dchunk.c
    hdf5_SRCS += H5Dcompact.c
    hdf5_SRCS += H5Dcontig.c
    hdf5_SRCS += H5Ddbg.c
    hdf5_SRCS += H5Ddeprec.c
    hdf5_SRCS += H5Dearray.c
    hdf5_SRCS += H5Defl.c
    hdf5_SRCS += H5Dfarray.c
    hdf5_SRCS += H5Dfill.c
    hdf5_SRCS += H5Dint.c
    hdf5_SRCS += H5Dio.c
    hdf5_SRCS += H5Dlayout.c
    hdf5_SRCS += H5Dnone.c
    hdf5_SRCS += H5Doh.c
    hdf5_SRCS += H5Dscatgath.c
    hdf5_SRCS += H5Dselect.c
    hdf5_SRCS += H5Dsingle.c
    hdf5_SRCS += H5Dtest.c
    hdf5_SRCS += H5Dvirtual.c
    hdf5_SRCS += H5E.c
    hdf5_SRCS += H5Edeprec.c
    hdf5_SRCS += H5Eint.c
    hdf5_SRCS += H5EA.c
    hdf5_SRCS += H5EAcache.c
    hdf5_SRCS += H5EAdbg.c
    hdf5_SRCS += H5EAdblkpage.c
    hdf5_SRCS += H5EAdblock.c
    hdf5_SRCS += H5EAhdr.c
    hdf5_SRCS += H5EAiblock.c
    hdf5_SRCS += H5EAint.c
    hdf5_SRCS += H5EAsblock.c
    hdf5_SRCS += H5EAstat.c
    hdf5_SRCS += H5EAtest.c
    hdf5_SRCS += H5F.c
    hdf5_SRCS += H5Faccum.c
    hdf5_SRCS += H5Fcwfs.c
    hdf5_SRCS += H5Fdbg.c
    hdf5_SRCS += H5Fdeprec.c
    hdf5_SRCS += H5Fefc.c
    hdf5_SRCS += H5Ffake.c
    hdf5_SRCS += H5Fint.c
    hdf5_SRCS += H5Fio.c
    hdf5_SRCS += H5Fmount.c
    hdf5_SRCS += H5Fquery.c
    hdf5_SRCS += H5Fsfile.c
    hdf5_SRCS += H5Fspace.c
    hdf5_SRCS += H5Fsuper.c
    hdf5_SRCS += H5Fsuper_cache.c
    hdf5_SRCS += H5Ftest.c
    hdf5_SRCS += H5FA.c
    hdf5_SRCS += H5FAcache.c
    hdf5_SRCS += H5FAdbg.c
    hdf5_SRCS += H5FAdblock.c
    hdf5_SRCS += H5FAdblkpage.c
    hdf5_SRCS += H5FAhdr.c
    hdf5_SRCS += H5FAint.c
    hdf5_SRCS += H5FAstat.c
    hdf5_SRCS += H5FAtest.c
    hdf5_SRCS += H5FD.c
    hdf5_SRCS += H5FDcore.c
    hdf5_SRCS += H5FDfamily.c
    hdf5_SRCS += H5FDint.c
    hdf5_SRCS += H5FDlog.c
    hdf5_SRCS += H5FDmulti.c
    hdf5_SRCS += H5FDsec2.c
    hdf5_SRCS += H5FDspace.c
    hdf5_SRCS += H5FDstdio.c
    hdf5_SRCS += H5FDtest.c
    hdf5_SRCS += H5FL.c
    hdf5_SRCS += H5FO.c
    hdf5_SRCS += H5FS.c
    hdf5_SRCS += H5FScache.c
    hdf5_SRCS += H5FSdbg.c
    hdf5_SRCS += H5FSint.c
    hdf5_SRCS += H5FSsection.c
    hdf5_SRCS += H5FSstat.c
    hdf5_SRCS += H5FStest.c
    hdf5_SRCS += H5G.c
    hdf5_SRCS += H5Gbtree2.c
    hdf5_SRCS += H5Gcache.c
    hdf5_SRCS += H5Gcompact.c
    hdf5_SRCS += H5Gdense.c
    hdf5_SRCS += H5Gdeprec.c
    hdf5_SRCS += H5Gent.c
    hdf5_SRCS += H5Gint.c
    hdf5_SRCS += H5Glink.c
    hdf5_SRCS += H5Gloc.c
    hdf5_SRCS += H5Gname.c
    hdf5_SRCS += H5Gnode.c
    hdf5_SRCS += H5Gobj.c
    hdf5_SRCS += H5Goh.c
    hdf5_SRCS += H5Groot.c
    hdf5_SRCS += H5Gstab.c
    hdf5_SRCS += H5Gtest.c
    hdf5_SRCS += H5Gtraverse.c
    hdf5_SRCS += H5HF.c
    hdf5_SRCS += H5HFbtree2.c
    hdf5_SRCS += H5HFcache.c
    hdf5_SRCS += H5HFdbg.c
    hdf5_SRCS += H5HFdblock.c
    hdf5_SRCS += H5HFdtable.c
    hdf5_SRCS += H5HFhdr.c
    hdf5_SRCS += H5HFhuge.c
    hdf5_SRCS += H5HFiblock.c
    hdf5_SRCS += H5HFiter.c
    hdf5_SRCS += H5HFman.c
    hdf5_SRCS += H5HFsection.c
    hdf5_SRCS += H5HFspace.c
    hdf5_SRCS += H5HFstat.c
    hdf5_SRCS += H5HFtest.c
    hdf5_SRCS += H5HFtiny.c
    hdf5_SRCS += H5HG.c
    hdf5_SRCS += H5HGcache.c
    hdf5_SRCS += H5HGdbg.c
    hdf5_SRCS += H5HGquery.c
    hdf5_SRCS += H5HL.c
    hdf5_SRCS += H5HLcache.c
    hdf5_SRCS += H5HLdbg.c
    hdf5_SRCS += H5HLint.c
    hdf5_SRCS += H5HLprfx.c
    hdf5_SRCS += H5HLdblk.c
    hdf5_SRCS += H5HP.c
    hdf5_SRCS += H5I.c
    hdf5_SRCS += H5Itest.c
    hdf5_SRCS += H5L.c
    hdf5_SRCS += H5Lexternal.c
    hdf5_SRCS += H5MF.c
    hdf5_SRCS += H5MFaggr.c
    hdf5_SRCS += H5MFdbg.c
    hdf5_SRCS += H5MFsection.c
    hdf5_SRCS += H5MM.c
    hdf5_SRCS += H5MP.c
    hdf5_SRCS += H5MPtest.c
    hdf5_SRCS += H5O.c
    hdf5_SRCS += H5Oainfo.c
    hdf5_SRCS += H5Oalloc.c
    hdf5_SRCS += H5Oattr.c
    hdf5_SRCS += H5Oattribute.c
    hdf5_SRCS += H5Obogus.c
    hdf5_SRCS += H5Obtreek.c
    hdf5_SRCS += H5Ocache.c
    hdf5_SRCS += H5Ocache_image.c
    hdf5_SRCS += H5Ochunk.c
    hdf5_SRCS += H5Ocont.c
    hdf5_SRCS += H5Ocopy.c
    hdf5_SRCS += H5Odbg.c
    hdf5_SRCS += H5Odrvinfo.c
    hdf5_SRCS += H5Odtype.c
    hdf5_SRCS += H5Oefl.c
    hdf5_SRCS += H5Ofill.c
    hdf5_SRCS += H5Oflush.c
    hdf5_SRCS += H5Ofsinfo.c
    hdf5_SRCS += H5Oginfo.c
    hdf5_SRCS += H5Olayout.c
    hdf5_SRCS += H5Olinfo.c
    hdf5_SRCS += H5Olink.c
    hdf5_SRCS += H5Omessage.c
    hdf5_SRCS += H5Omtime.c
    hdf5_SRCS += H5Oname.c
    hdf5_SRCS += H5Onull.c
    hdf5_SRCS += H5Opline.c
    hdf5_SRCS += H5Orefcount.c
    hdf5_SRCS += H5Osdspace.c
    hdf5_SRCS += H5Oshared.c
    hdf5_SRCS += H5Oshmesg.c
    hdf5_SRCS += H5Ostab.c
    hdf5_SRCS += H5Otest.c
    hdf5_SRCS += H5Ounknown.c
    hdf5_SRCS += H5P.c
    hdf5_SRCS += H5Pacpl.c
    hdf5_SRCS += H5Pdapl.c
    hdf5_SRCS += H5Pdcpl.c
    hdf5_SRCS += H5Pdeprec.c
    hdf5_SRCS += H5Pdxpl.c
    hdf5_SRCS += H5Pencdec.c
    hdf5_SRCS += H5Pfapl.c
    hdf5_SRCS += H5Pfcpl.c
    hdf5_SRCS += H5Pfmpl.c
    hdf5_SRCS += H5Pgcpl.c
    hdf5_SRCS += H5Pint.c
    hdf5_SRCS += H5Plapl.c
    hdf5_SRCS += H5Plcpl.c
    hdf5_SRCS += H5Pocpl.c
    hdf5_SRCS += H5Pocpypl.c
    hdf5_SRCS += H5Pstrcpl.c
    hdf5_SRCS += H5Ptest.c
    hdf5_SRCS += H5PB.c
    hdf5_SRCS += H5PL.c
    hdf5_SRCS += H5R.c
    hdf5_SRCS += H5Rdeprec.c
    hdf5_SRCS += H5UC.c
    hdf5_SRCS += H5RS.c
    hdf5_SRCS += H5S.c
    hdf5_SRCS += H5Sall.c
    hdf5_SRCS += H5Sdbg.c
    hdf5_SRCS += H5Shyper.c
    hdf5_SRCS += H5Snone.c
    hdf5_SRCS += H5Spoint.c
    hdf5_SRCS += H5Sselect.c
    hdf5_SRCS += H5Stest.c
    hdf5_SRCS += H5SL.c
    hdf5_SRCS += H5SM.c
    hdf5_SRCS += H5SMbtree2.c
    hdf5_SRCS += H5SMcache.c
    hdf5_SRCS += H5SMmessage.c
    hdf5_SRCS += H5SMtest.c
    hdf5_SRCS += H5ST.c
    hdf5_SRCS += H5T.c
    hdf5_SRCS += H5Tarray.c
    hdf5_SRCS += H5Tbit.c
    hdf5_SRCS += H5Tcommit.c
    hdf5_SRCS += H5Tcompound.c
    hdf5_SRCS += H5Tconv.c
    hdf5_SRCS += H5Tcset.c
    hdf5_SRCS += H5Tdbg.c
    hdf5_SRCS += H5Tdeprec.c
    hdf5_SRCS += H5Tenum.c
    hdf5_SRCS += H5Tfields.c
    hdf5_SRCS += H5Tfixed.c
    hdf5_SRCS += H5Tfloat.c
    hdf5_SRCS += H5Tnative.c
    hdf5_SRCS += H5Toffset.c
    hdf5_SRCS += H5Toh.c
    hdf5_SRCS += H5Topaque.c
    hdf5_SRCS += H5Torder.c
    hdf5_SRCS += H5Tpad.c
    hdf5_SRCS += H5Tprecis.c
    hdf5_SRCS += H5Tstrpad.c
    hdf5_SRCS += H5Tvisit.c
    hdf5_SRCS += H5Tvlen.c
    hdf5_SRCS += H5TS.c
    hdf5_SRCS += H5VM.c
    hdf5_SRCS += H5WB.c
    hdf5_SRCS += H5Z.c
    hdf5_SRCS += H5Zdeflate.c
    hdf5_SRCS += H5Zfletcher32.c
    hdf5_SRCS += H5Znbit.c
    hdf5_SRCS += H5Zscaleoffset.c
    hdf5_SRCS += H5Zshuffle.c
    hdf5_SRCS += H5Zszip.c
    hdf5_SRCS += H5Ztrans.c

    # H5Tinit.c is architecture specific
    hdf5_SRCS += H5Tinit.c

    hdf5_SRCS_vxWorks += H5vxWorks.c

    # This file allows printing how the library was configured.
    # It is not yet correct for each system.
    hdf5_SRCS += H5lib_settings.c

    ifeq ($(SZIP_EXTERNAL),YES)
      ifdef SZIP_INCLUDE
        USR_INCLUDES += $(addprefix -I, $(SZIP_INCLUDE))
      endif
      ifdef SZIP_LIB
        sz_DIR       = $(SZIP_LIB)
        hdf5_LIBS     += sz
      else
        hdf5_SYS_LIBS += sz
      endif
    else
      hdf5_LIBS += szip
    endif

    ifeq ($(ZLIB_EXTERNAL),YES)
      ifdef ZLIB_INCLUDE
        USR_INCLUDES += $(addprefix -I, $(ZLIB_INCLUDE))
      endif
      ifdef ZLIB_LIB
        z_DIR        = $(ZLIB_LIB)
        hdf5_LIBS     += z
      else
        hdf5_SYS_LIBS += z
      endif
    else
      hdf5_LIBS += zlib
    endif

    ifeq ($(WITH_BLOSC),YES)
      USR_CFLAGS += -DH5_HAVE_FILTER_BLOSC
      hdf5_SRCS += blosc_filter.c
      ifeq ($(BLOSC_EXTERNAL),YES)
        ifdef BLOSC_INCLUDE
          USR_INCLUDES += $(addprefix -I, $(BLOSC_INCLUDE))
        endif
        ifdef BLOSC_LIB
          blosc_DIR = $(BLOSC_LIB)
          hdf5_LIBS += blosc
        else
          hdf5_SYS_LIBS += blosc
        endif
      else
        hdf5_LIBS += blosc
        LOADABLE_LIBRARY += HDF5_blosc_filter
        HDF5_blosc_filter_SRCS += blosc_filter.c
        HDF5_blosc_filter_SRCS += blosc_plugin.c
        HDF5_blosc_filter_LIBS += blosc
      endif
    endif

    ifeq ($(WITH_BITSHUFFLE),YES)
      # Note: We are getting the lz4 codec from the bitshuffle source
      # So they are combined here.  They could be separated at a later time.
      USR_CFLAGS += -DH5_HAVE_FILTER_BSHUF
      USR_CFLAGS += -DH5_HAVE_FILTER_LZ4
      hdf5_SRCS += bshuf_h5filter.c
      hdf5_SRCS += H5Zlz4.c
      ifeq ($(BITSHUFFLE_EXTERNAL),YES)
        ifdef BITSHUFFLE_INCLUDE
          USR_INCLUDES += $(addprefix -I, $(BITSHUFFLE_INCLUDE))
        endif
        ifdef BITSHUFFLE_LIB
          bshuf_DIR = $(BITSHUFFLE_LIB)
          hdf5_LIBS += bitshuffle
        else
          hdf5_SYS_LIBS += bitshuffle
        endif
      else
        hdf5_LIBS += bitshuffle
        LOADABLE_LIBRARY += HDF5_bshuf_filter
        HDF5_bshuf_filter_SRCS += bshuf_h5filter.c
        HDF5_bshuf_filter_SRCS += bshuf_h5plugin.c
        HDF5_bshuf_filter_LIBS += bitshuffle
        LOADABLE_LIBRARY += HDF5_lz4_filter
        HDF5_lz4_filter_SRCS += H5Zlz4.c
        HDF5_lz4_filter_SRCS += lz4_h5plugin.c
        HDF5_lz4_filter_LIBS += bitshuffle
      endif
    endif

    hdf5_SYS_LIBS_WIN32 += ws2_32

    H5detect_SRCS += H5detect.c
    PROD_SYS_LIBS_WIN32 += ws2_32

  endif # ($(HDF5_EXTERNAL),NO)
endif # ($(WITH_HDF5),YES)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

