#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "pluxx/Plugin.h"
#include "../../bin/PluginType2.h"

/* STD */
#include "cstring"
#include <iostream>

using namespace std;

static const char* type = "PluginType2";
static const unsigned int major_version = 1;
static const unsigned int minor_version = 1;

class PluginTest2 : public PluginType2
{
public:
  PluginTest2 (const std::string &param1, const std::string &param2)
  {
    cout << "param1: " << param1 << endl;
    cout << "param2: " << param2 << endl;
  };
  
  virtual ~PluginTest2 () {};

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
  
  void func2 ()
  {
    cout << "I'm a function in PluginTest2" << endl;
  }

private:

};

PLUGIN_EXPORT PluginType2 *plugin_create (const std::string &param1, const std::string &param2)
{
  return new PluginTest2 (param1, param2);
}

PLUGIN_EXPORT void plugin_destroy (PluginType2 *plugin)
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
