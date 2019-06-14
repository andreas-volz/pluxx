#ifndef CUSTOM_PLUGIN_LOADER_H
#define CUSTOM_PLUGIN_LOADER_H

/* pluxx */
#include "pluxx/PluginLoader.h"

class CustomPluginLoader : public pluxx::PluginLoader
{
public:
  static pluxx::Plugin *loadFactory (const std::string &filename, const std::string& type, unsigned int majorVersion,
                                     const std::string &param1, const std::string &param2);
  

private:
};

#endif // CUSTOM_PLUGIN_LOADER_H
