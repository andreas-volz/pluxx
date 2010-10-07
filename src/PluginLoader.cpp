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

namespace pluxx {

/*!
 * You may 'overwrite' plugin_create_t() in a custom loader.
 * But pay attention that you're responsible for the function signature!
 * dlopen() couldn't check the signature. If you (or buggy plugins) have an
 * invalid signature, your application may crash! Tests have shown that
 * not used arguments in the function signature seem to work. But I wouldn't
 * rely on this fact!
 */
typedef Plugin* plugin_create_t ();

///don't change the types of the class factories  
typedef void plugin_destroy_t (Plugin*);
typedef const char *get_plugin_type_t ();
typedef unsigned int get_plugin_major_version_t ();

void *PluginLoader::loadFactoryInternal (const std::string &filename, const std::string& type, unsigned int majorVersion)
{
  void *pluginHandle = dlopen (filename.c_str (), RTLD_LAZY);
  if (!pluginHandle) throw std::runtime_error ("dlopen() failed: " + string (dlerror()));

  // load the symbols
  get_plugin_type_t* get_plugin_type = (get_plugin_type_t*) dlsym (pluginHandle, "get_plugin_type");
  if (!get_plugin_type) throw std::runtime_error ("dlsym(get_plugin_type) failed: " + string (dlerror()));

  get_plugin_major_version_t* get_plugin_major_version = (get_plugin_major_version_t*) dlsym (pluginHandle, "get_plugin_major_version");
  if (!get_plugin_major_version) throw std::runtime_error ("dlsym(get_plugin_major_version) failed: " + string (dlerror()));

  if (type != get_plugin_type ())
  {
    throw PluginTypeMismatchException (type, get_plugin_type ());
  }

  if (majorVersion != get_plugin_major_version ())
  {
    throw PluginMajorVersionMismatchException (majorVersion, get_plugin_major_version ());
  }
 
  return pluginHandle;
}

void PluginLoader::destroyFactory (Plugin *plugin)
{
  plugin_destroy_t* plugin_destroy = (plugin_destroy_t*) dlsym (plugin->getHandle (), "plugin_destroy");
  if (!plugin_destroy) throw std::runtime_error ("dlsym(destroy) failed: " + string (dlerror()));
  
  plugin_destroy (plugin);
  if (dlclose (plugin->getHandle ())) throw std::runtime_error ("dlclose() failed"); 
}

void *PluginLoader::loadSymbol (void *pluginHandle, const std::string &symbol)
{
  void *sym = dlsym (pluginHandle, symbol.c_str ());
  if (!sym) throw std::runtime_error ("dlsym(create) failed: " + string (dlerror()));
  return sym;
}

void PluginLoader::registerPlugin (Plugin *plugin, void *pluginHandle)
{
  assert(plugin);
  plugin->setHandle (pluginHandle);
}

Plugin *PluginLoader::loadFactory (const std::string &filename, const std::string& type, unsigned int majorVersion)
{
  void *pluginHandle = loadFactoryInternal (filename, type, majorVersion);

  plugin_create_t* plugin_create = (plugin_create_t*) loadSymbol (pluginHandle, "plugin_create");
    
  Plugin *plugin = plugin_create ();
  registerPlugin (plugin, pluginHandle);

  return plugin;
}

} // end namespace pluxx
