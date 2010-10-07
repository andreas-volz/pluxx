/* local */
#include "CustomPluginLoader.h"

using namespace pluxx;

typedef Plugin* plugin_create_t (const std::string &param1, const std::string &param2);

Plugin *CustomPluginLoader::loadFactory (const std::string &filename, const std::string& type, unsigned int majorVersion,
                                         const std::string &param1, const std::string &param2)
{
  void *pluginHandle = loadFactoryInternal (filename, type, majorVersion);

  plugin_create_t* plugin_create = (plugin_create_t*) loadSymbol (pluginHandle, "plugin_create");
    
  Plugin *plugin = plugin_create (param1, param2);
  registerPlugin (plugin, pluginHandle);
  
  return plugin;
}
