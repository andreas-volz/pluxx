pkglibdir = $(libdir)/pluxx/test/plugins

lib_LTLIBRARIES = \
	testplugin1.la

testplugin1_la_SOURCES = \
	PluginTest1.cpp

testplugin1_la_LDFLAGS = \
	-module \
	-avoid-version \
	-shared

testplugin1_la_CXXFLAGS = \
	-I \
	../../../include

## File created by the gnome-build tools

