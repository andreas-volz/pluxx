#ifndef PLUGIN_LOADER_H
#define PLUGIN_LOADER_H

/* Project */
#include "PluginExceptions.h"

/* STD */
#include <string>

namespace pluxx {

/* forward declarations*/
class Plugin;

class PluginLoader
{
public:
  /*!
   * Use this factory function to create an Plugin instead of calling 'new' on it.
   */
  static Plugin *loadFactory (const std::string &filename, const std::string& type, unsigned int majorVersion);

  /*!
   * Use this factory function to delete an Plugin instead of calling 'delete' on it.
   */
  static void destroyFactory (Plugin *plugin);
  
private:  
  PluginLoader (); // don't allow construction
  virtual ~PluginLoader (); // don't allow destruction
};

} // end namespace pluxx

#endif // PLUGIN_LOADER_H
