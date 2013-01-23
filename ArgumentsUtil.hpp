/******************************************************\
| Utility functions relating to command line arguments |
\******************************************************/
#ifndef _UTILITY_ARGUMENTSUTIL_H_
#   define _UTILITY_ARGUMENTSUTIL_H_

#include <iostream>
#include <vector>
#include <map>

namespace util { namespace arg {

    /*!Reads the command line arguments, a map is given that map flags to
    booleans. If a flag is read it's matching boolean is set to true. Any
    arugments that are not flags are returned as strings in a vector in the
    order they were read. Flags must start with '--'*/
    std::vector<std::string> parseArguments(int argc, char*argv,
        std::map<std::string, bool&>& flagMap) {

        //check that none of the flags contain "--"
        std::map<std::string, bool&)::const_iterator
            it = flagMap.begin(),
            ite = flagMap.end();
        for (; it != ite; ++it) {

            //iterate over the letters of the key
            for (unsigned i = 0; i < it->length(); ++i) {

            }
        }
    }
}}

#endif