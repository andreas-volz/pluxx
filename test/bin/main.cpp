#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* Project */
#include "pluxx/PluginLoader.h"
#include "pluxx/Plugin.h"
#include "PluginType1.h"
#include "searchFile.h"

/* STD */
#include <iostream>

using namespace std;
using namespace pluxx;

int main (int argc, const char** argv)
{
  try
  {
    PluginType1 *plugin1 = (PluginType1*) PluginLoader::loadFactory (searchPluginFile ("testplugin1"), "PluginType1", 1);

    plugin1->func1 ();
    
    cout << "Type: " << plugin1->getType () << endl;
    cout << "Major Version: " << plugin1->getMajorVersion () << endl;
    cout << "Minor Version: " << plugin1->getMinorVersion () << endl;

    PluginLoader::destroyFactory ((Plugin*) plugin1);
  }
  catch (PluginTypeMismatchException typeEx)
  {
    cout << "catched an PluginTypeMismatchException exception..." << endl;
    cout << "Loader Type: " << typeEx.getLoaderType () << endl;
    cout << "Plugin Type: " << typeEx.getPluginType () << endl;
  }
  catch (PluginMajorVersionMismatchException verEx)
  {
    cout << "catched an PluginMajorVersionMismatchException exception..." << endl;
    cout << "Loader Major Version: " << verEx.getLoaderMajorVersion () << endl;
    cout << "Plugin Major Version: " << verEx.getPluginMajorVersion () << endl;
  }
  
  return 0;
}
