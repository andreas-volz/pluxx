#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* STD */
#include <string>

/* Project */
#include "pluxx/PluginExceptions.h"
#include "stringUtil.h"

using namespace std;

namespace pluxx {

const char* PluginTypeMismatchException::what () const throw ()
{
  static string s;
  s = "Loader Type: '" + mLoaderType;
  s += "' != '";
  s += "Plugin Type: '" + mPluginType + "'";

  return static_cast <const char*> (s.c_str ());
}

const std::string PluginTypeMismatchException::getLoaderType ()
{
  return mLoaderType;
}

const std::string PluginTypeMismatchException::getPluginType ()
{
  return mPluginType;
}

const char* PluginMajorVersionMismatchException::what () const throw ()
{
  static string s;
  s = "Loader Major Version: '" + toString <unsigned int> (mLoaderMajorVersion);
  s += "' != '";
  s += "Plugin Major Version: '" + toString <unsigned int> (mPluginMajorVersion) + "'";

  return static_cast <const char*> (s.c_str ());
}

const unsigned int PluginMajorVersionMismatchException::getLoaderMajorVersion ()
{
  return mLoaderMajorVersion;
}

const unsigned int PluginMajorVersionMismatchException::getPluginMajorVersion ()
{
  return mPluginMajorVersion;
}

} // end namespace pluxx
