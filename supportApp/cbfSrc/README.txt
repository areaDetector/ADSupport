Introduction
------------

This directory contains a reorganized portion of the API source code taken
from CBFlib <http://www.bernstein-plus-sons.com/software/CBF/> by Paul J.
Ellis and Herbert J. Bernstein.  This kit is structured differently from the
official CBFlib releases and from the CBFlib you will find in Debian, Gentoo,
Ubuntu, etc.  The complete upstream source code, documentation, and latest
releases are available at <http://sourceforge.net/projects/cbflib>.

This extract does not include documentation, example programs, etc.; it just
includes the source code for creating a C subset of the cbf library.  The API
source code is licensed under the GPLv2 or LGPLv2.1.  It is included here in
areaDetector under the terms of the LGPLv2.1.  See the files LICENSE-GPL.txt
and LICENSE-LGPL.txt for the full text of the licenses.  See the file
NOTICES.txt for notices related to the CBFlib source code.

Changes
-------

The source code in this directory has been modified to add support for
disabling warning, error, and log messages.  The changes are contained in the
file CBFlib-msgs-onoff.patch in this directory.  These changes have been sent
to Herbert J. Bernstein.

Constructing the Files in This Directory
----------------------------------------

(Commands are for a Bourne Shell, starting with this directory as the current
working directory, on a Unix-like platform.)

1. Fetch, modify, and copy the required files:

   $ originalDir=`pwd`
   $ cp -p CBFlib-msgs-onoff.patch /tmp
   $ cd /tmp
   $ cbflibRepo='https://cbflib.svn.sourceforge.net/svnroot/cbflib'
   $ svn export -r 145 "$cbflibRepo/trunk/CBFlib_bleeding_edge" \
       CBFlib_bleeding_edge-r145
   $ cd CBFlib_bleeding_edge-r145
   $ patch -p0 < ../CBFlib-msgs-onoff.patch
   $ cd "$originalDir"
   $ cp /tmp/CBFlib_bleeding_edge-r145/include/*.h .
   $ rm cbff.h
   $ cp /tmp/CBFlib_bleeding_edge-r145/src/*.c .
   $ rm cbff.c
   $ sh rename-header-files.sh
   $ cp -p /tmp/CBFlib_bleeding_edge-r145/doc/gpl.txt LICENSE-GPL.txt
   $ cp -p /tmp/CBFlib_bleeding_edge-r145/doc/lgpl.txt LICENSE-LGPL.txt
   $ cp -p /tmp/CBFlib_bleeding_edge-r145/doc/CBFlib_NOTICES.txt NOTICES.txt

2. Add "cbfad_SRCS += FILE" lines to Makefile where FILE is each listed by:

   $ ls -1 *.c
