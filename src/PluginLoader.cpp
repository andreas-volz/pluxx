#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* Project */
#include "pluxx/PluginLoader.h"
#include "pluxx/Plugin.h"

/* STD */
#include <stdexcept>
#include <iostream>
#include <cassert>

/* Dynamic Loader */
#include <dlfcn.h>

using namespace std;

// the types of the class factories
typedef Plugin* plugin_create_t ();
typedef void plugin_destroy_t (Plugin*);
typedef const char *get_plugin_type_t ();
typedef unsigned int get_plugin_major_version_t ();

Plugin *PluginLoader::loadFactory (const std::string &filename, const std::string& type, unsigned int majorVersion)
{
  void *pluginHandle = dlopen (filename.c_str (), RTLD_LAZY);
  if (!pluginHandle) throw std::runtime_error ("dlopen() failed: " + string (dlerror()));

  // load the symbols
  get_plugin_type_t* get_plugin_type = (get_plugin_type_t*) dlsym (pluginHandle, "get_plugin_type");
  if (!get_plugin_type) throw std::runtime_error ("dlsym(get_plugin_type) failed: " + string (dlerror()));

  get_plugin_major_version_t* get_plugin_major_version = (get_plugin_major_version_t*) dlsym (pluginHandle, "get_plugin_major_version");
  if (!get_plugin_major_version) throw std::runtime_error ("dlsym(get_plugin_major_version) failed: " + string (dlerror()));

  // TODO: define exception with plugin type/version to be checked outside...
  if (type != get_plugin_type ())
  {
    throw PluginTypeMismatchException (type, get_plugin_type ());
  }

  if (majorVersion != get_plugin_major_version ())
  {
    throw PluginMajorVersionMismatchException (majorVersion, get_plugin_major_version ());
  }
 
  plugin_create_t* plugin_create = (plugin_create_t*) dlsym (pluginHandle, "plugin_create");
  if (!plugin_create) throw std::runtime_error ("dlsym(create) failed: " + string (dlerror()));
  
  Plugin *plugin = plugin_create ();
  assert(plugin);
  plugin->setHandle (pluginHandle);
  return plugin;
}

void PluginLoader::destroyFactory (Plugin *plugin)
{
  plugin_destroy_t* plugin_destroy = (plugin_destroy_t*) dlsym (plugin->getHandle (), "plugin_destroy");
  if (!plugin_destroy) throw std::runtime_error ("dlsym(destroy) failed: " + string (dlerror()));
  
  plugin_destroy (plugin);
  if (dlclose (plugin->getHandle ())) throw std::runtime_error ("dlclose() failed"); 
}
