dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(pluxx, 0.1)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_MAINTAINER_MODE

AC_ISC_POSIX
AC_PROG_CXX
AM_PROG_CC_STDC
AC_HEADER_STDC






AM_PROG_LIBTOOL
            
AC_CHECK_HEADER([dlfcn.h],
    [AC_CHECK_LIB([dl], [dlopen],
        [LIBDL=-ldl], [LIBDL=])],
    [LIBDL=])
AC_SUBST(LIBDL)

#dnl Set PACKAGE SOURCE DIR in config.h.
packagesrcdir=`cd $srcdir && pwd`

#dnl Set PACKAGE PREFIX
if test "x${prefix}" = "xNONE"; then
  packageprefix=${ac_default_prefix}
else
  packageprefix=${prefix}
fi

#dnl Set PACKAGE DIRS in config.h
packagedatadir=share/${PACKAGE}
packagedocdir=doc/${PACKAGE}
packagelibdir=lib/${PACKAGE}
packagepluginsdir=${packagelibdir}/plugins

#dnl Subst PACKAGE_DATA_DIR.
NO_PREFIX_PACKAGE_DATA_DIR="${packagedatadir}"
AC_SUBST(NO_PREFIX_PACKAGE_DATA_DIR)
PACKAGE_DATA_DIR="${packageprefix}/${packagedatadir}"
AC_SUBST(PACKAGE_DATA_DIR)

dnl Subst PACKAGE_DOC_DIR.
NO_PREFIX_PACKAGE_DOC_DIR="${packagedocdir}"
AC_SUBST(NO_PREFIX_PACKAGE_DOC_DIR)
PACKAGE_DOC_DIR="${packageprefix}/${packagedocdir}"
AC_SUBST(PACKAGE_DOC_DIR)

dnl Subst PACKAGE_PLUGINS_DIR.
NO_PREFIX_PACKAGE_PLUGINS_DIR="${packagepluginsdir}"
AC_SUBST(NO_PREFIX_PACKAGE_PLUGINS_DIR)
PACKAGE_PLUGINS_DIR="${packageprefix}/${packagepluginsdir}"
AC_SUBST(PACKAGE_PLUGINS_DIR)

AC_DEFINE_UNQUOTED(PACKAGE_DATA_DIR, "${packageprefix}/${packagedatadir}","")
AC_DEFINE_UNQUOTED(SYSTEM_DATA_DIR, "${packageprefix}/${systemdatadir}","")
AC_DEFINE_UNQUOTED(PACKAGE_DOC_DIR, "${packageprefix}/${packagedocdir}","")
AC_DEFINE_UNQUOTED(PACKAGE_PLUGINS_DIR, "${packageprefix}/${packagepluginsdir}","")
AC_DEFINE_UNQUOTED(SYSTEM_PLUGINS_DIR, "${packageprefix}/${systempluginsdir}","")
AC_DEFINE_UNQUOTED(PACKAGE_SOURCE_DIR, "${packagesrcdir}","")

AC_OUTPUT([
Makefile
include/Makefile
include/pluxx/Makefile
src/Makefile
test/Makefile
test/bin/Makefile
test/modules/Makefile
test/modules/testplugin1/Makefile
test/modules/testplugin2/Makefile
test/modules/testplugin3/Makefile
])
