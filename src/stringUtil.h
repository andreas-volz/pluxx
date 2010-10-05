#ifndef STRING_UTIL_H
#define STRING_UTIL_H

/* STD */
#include <string> 
#include <sstream>
#include <iomanip>
#include <iostream>

/// create std::string from any number
template <typename T>
std::string toString (const T &thing, int w = 0, int p = 0)
{
  std::ostringstream os;
  os << std::setw(w) << std::setprecision(p) << thing;
  return os.str();
}

#endif	// STRING_UTIL_H

