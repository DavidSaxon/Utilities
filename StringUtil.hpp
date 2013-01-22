/*******************************************\
| Utility functions for string manipulation |
\*******************************************/
#ifndef _UTILITIES_STRINGUTILS_H_
#   define _UTILITIES_STRINGUTILS_H_

#include <iostream>
#include <sstream>

namespace util { namespace str {

    /*appends e to the end of s with a '.' seperating them*/
    std::string appendExtension(const std::string& s, std::string e) {

        //add to string stream
        std::stringstream ss;
        ss << s << "." << e;
        return ss.str();
    }
}}

#endif