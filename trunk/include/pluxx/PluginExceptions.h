#ifndef PLUGIN_EXCEPTIONS_H
#define PLUGIN_EXCEPTIONS_H

/* STD */
#include <string>
#include <exception>

namespace pluxx {

class PluginTypeMismatchException : public std::exception
{
public:
  PluginTypeMismatchException (const std::string &loaderType, const std::string &pluginType) : 
    mLoaderType (loaderType),
    mPluginType (pluginType)
  {}
  
  virtual ~PluginTypeMismatchException () throw() {}

  const char* what () const throw ();

  const std::string getLoaderType ();
  const std::string getPluginType ();

private:
  std::string mLoaderType;
  std::string mPluginType;
};

class PluginMajorVersionMismatchException : public std::exception
{
public:
  PluginMajorVersionMismatchException (const unsigned int loaderMajorVersion, const unsigned int pluginMajorVersion) : 
    mLoaderMajorVersion (loaderMajorVersion),
    mPluginMajorVersion (pluginMajorVersion)
  {}
  
  virtual ~PluginMajorVersionMismatchException () throw() {}

  const char* what () const throw ();

  const unsigned int getLoaderMajorVersion ();
  const unsigned int getPluginMajorVersion ();

private:
  unsigned int mLoaderMajorVersion;
  unsigned int mPluginMajorVersion;
};

} // end namespace pluxx

#endif // PLUGIN_EXCEPTIONS_H
