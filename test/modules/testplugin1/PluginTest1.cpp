#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "pluxx/Plugin.h"
#include "../../bin/PluginType1.h"

/* STD */
#include "cstring"
#include <iostream>

using namespace std;

static const char* type = "PluginType1";
static const unsigned int major_version = 1;
static const unsigned int minor_version = 3;

class PluginTest1 : public PluginType1
{
public:
  PluginTest1 () {};
  virtual ~PluginTest1 () {};

  const std::string getType ()
  {
    return type;
  }
  
  const unsigned int getMajorVersion ()
  {
    return major_version;
  }

  const unsigned int getMinorVersion ()
  {
    return minor_version;
  }
  
  void func1 ()
  {
    cout << "I'm a function in PluginTest1" << endl;
  }

private:

};

PLUGIN_EXPORT PluginType1 *plugin_create ()
{
  return new PluginTest1 ();
}

PLUGIN_EXPORT void plugin_destroy (PluginType1 *plugin)
{
  delete plugin;
}

PLUGIN_EXPORT const char *get_plugin_type ()
{
  return type;
}

PLUGIN_EXPORT unsigned int get_plugin_major_version ()
{
  return major_version;
}
