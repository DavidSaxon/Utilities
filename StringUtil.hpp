/*******************************************\
| Utility functions for string manipulation |
\*******************************************/
#ifndef _UTILITIES_STRINGUTILS_H_
#   define _UTILITIES_STRINGUTILS_H_

#include <iostream>
#include <sstream>

namespace util { namespace str {

    //FUNCTIONS
    /*Returns true if the given string is an integer*/
    bool isInt(const std::string& s) {

        //iterate over the string that each char is a digit
        //execpt for the first char which may be a '-'
        for (unsigned i = 0; i < s.length(); ++i) {

            if (i == 0 && s.at(i) != '-' && !isdigit(s.at(i))) {

                return false;
            }
            if (i != 0 && !isdigit(s.at(i))) {

                return false;
            }
        }

        return true;
    }

    /*Returns true if the given string an unsigned integer*/
    bool isUInt(const std::string& s) {

        //iterate over the string and check that each char is a digit
        for(unsigned i = 0; i < s.length(); ++i) {

            if (!isdigit(s.at(i))) {

                return false;
            }
        }

        return true;
    }

    /*appends e to the end of s with a '.' seperating them*/
    std::string appendExtension(const std::string& s, std::string e) {

        //add to string stream
        std::stringstream ss;
        ss << s << "." << e;
        return ss.str();
    }

    /*Generates a random hex string
    WARNING: random number generator should be seeded before calling this*/
    std::string generateHexString() {

        unsigned long num = rand();

        //convert the number to a hex string
        std::stringstream ss;
        ss << std::hex << num;

        return ss.str();
    }
}}

#endif