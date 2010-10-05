## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src \
	include\
	test

pluxxdocdir = ${prefix}/doc/pluxx
pluxxdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = $(pluxxdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(pluxxdocdir)
