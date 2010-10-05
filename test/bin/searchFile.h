#ifndef SEARCHFILE_H
#define SEARCHFILE_H

#include <string>
#include <vector>

// public search functions

/// ".so" is added....
const std::string searchPluginFile (const std::string &plugin);
const std::string searchDataDir ();

// private
const std::string searchFile (std::vector <std::string> &name_vector);

#endif // SEARCHFILE_H
