#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* Project */
#include "pluxx/PluginLoader.h"
#include "pluxx/Plugin.h"
#include "PluginType1.h"
#include "PluginType2.h"
#include "searchFile.h"
#include "CustomPluginLoader.h"

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

    ///// -> load second plugin...
      
    PluginType2 *plugin2 = (PluginType2*) CustomPluginLoader::loadFactory (searchPluginFile ("testplugin2"), "PluginType2", 1,
                                                                           "First parameter", "Second parameter");

    plugin2->func2 ();
    
    cout << "Type: " << plugin2->getType () << endl;
    cout << "Major Version: " << plugin2->getMajorVersion () << endl;
    cout << "Minor Version: " << plugin2->getMinorVersion () << endl;

    CustomPluginLoader::destroyFactory ((Plugin*) plugin2);
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
  catch (...)
  {
    cout << "catch all" << endl;
  }
  
  return 0;
}
