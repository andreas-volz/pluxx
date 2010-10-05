#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "pluxx/Plugin.h"
#include "../../bin/PluginType1.h"

/* STD */
#include "cstring"
#include <iostream>

using namespace std;

const char* type = "PluginType1";
unsigned int major_version = 1;
unsigned int minor_version = 3;

class PluginTest1 : public PluginType1
{
public:
  PluginTest1 () {};
  virtual ~PluginTest1 () {};

  virtual const std::string getType ()
  {
    return type;
  }
  
  virtual const unsigned int getMajorVersion ()
  {
    return major_version;
  }

  virtual const unsigned int getMinorVersion ()
  {
    return minor_version;
  }

  
  virtual void func1 ()
  {
    cout << "I'm a function in PluginTest1" << endl;
  }

private:

};

extern "C" PluginType1 *plugin_create ()
{
  return new PluginTest1 ();
}

extern "C" void plugin_destroy (PluginType1 *plugin)
{
  delete plugin;
}

extern "C" const char *get_plugin_type ()
{
  return type;
}

extern "C" unsigned int get_plugin_major_version ()
{
  return major_version;
}
