#ifndef PLUGIN_H
#define PLUGIN_H

#include <string>

#define PLUGIN_EXPORT extern "C"

namespace pluxx {

/* forward declarations */
class PluginLoader;

class Plugin
{
public:
  friend class PluginLoader;

  /*!
   * Warning: Never call 'new' direct on Plugin!
   *          Use PluginLoader::loadFactory() instead to create the object!
   */
  Plugin () : mHandle (NULL) {}

  /*!
   * Warning: Never call 'delete' direct on Plugin!
   *          Use PluginLoader::destroyFactory() instead to destroy the object!
   */
  virtual ~Plugin () {}

  virtual const std::string getType () = 0;
  virtual const unsigned int getMajorVersion () = 0;
  virtual const unsigned int getMinorVersion () = 0;
  
private:
  void setHandle (void *handle) {mHandle = handle;}
  void *getHandle () {return mHandle;}

  void *mHandle;
};

} // end namespace pluxx

#endif // PLUGIN_H
