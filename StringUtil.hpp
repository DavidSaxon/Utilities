/*******************************************\
| Utility functions for string manipulation |
\*******************************************/
#ifndef _UTILITIES_STRINGUTILS_H_
#   define _UTILITIES_STRINGUTILS_H_

#include <iostream>
#include <sstream>

namespace util { namespace str {

//FUNCTIONS
/*!Checks if a string begins with another string
@a the string to check if it beings with b
@b the string to check if is the beginning of a*/
inline bool beginsWith(const std::string& a, const std::string& b) {

    //check that a is longer than or the same length as b
    if (a.length() < b.length()) {

        return false;
    }

    return a.substr(0, b.length()) == b;
}

/*!Checks if a string ends with another string
@a the string if it ends with b
@b the string to check if it is the end of b*/
inline bool endsWith(const std::string& a, const std::string& b) {

    //check that a is longer than or the same length as b
    if (a.length() < b.length()) {

        return false;
    }

    return a.substr(a.length()-b.length(), a.length()) == b;
}

/*!Checks if a string is contained with another string at the given index
@index the index in string a to check if string b is contained
@a the string to check if it has b at index
@b the string to check if it is at index in b*/
inline bool atEquals(unsigned index, const std::string& a, const std::string& b) {

    //check that the index is less than the length of string b
    if (index >= a.length()) {

        return false;
    }

    //check that length from the index to the end of string a is the
    //same length or longer than string b
    if (a.substr(index, a.length()).length() < b.length()) {

        return false;
    }

    return a.substr(index, b.length()) == b;
}

/*!Checks if a string contains another string anywhere within it
@a the string to check if it has b within
@b the string to check if it is within b*/
inline bool contains(const std::string& a, const std::string& b) {

    //check that a is longer than or the same length as b
    if (a.length() < b.length()) {

        return false;
    }

    //check each index
    for (unsigned i = 0; i <= a.length()-b.length(); ++i) {

        if (stringAtEquals(i, a, b)) {

            return true;
        }
    }

    return false;
}

/*Returns true if the given string is an integer*/
inline bool isInt(const std::string& s) {

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
inline bool isUInt(const std::string& s) {

    //iterate over the string and check that each char is a digit
    for(unsigned i = 0; i < s.length(); ++i) {

        if (!isdigit(s.at(i))) {

            return false;
        }
    }

    return true;
}

/*appends e to the end of s with a '.' seperating them*/
inline std::string appendExtension(const std::string& s, std::string e) {

    //add to string stream
    std::stringstream ss;
    ss << s << "." << e;
    return ss.str();
}

/*Generates a random hex string
WARNING: random number generator should be seeded before calling this*/
inline std::string generateHexString() {

    unsigned long num = rand();

    //convert the number to a hex string
    std::stringstream ss;
    ss << std::hex << num;

    return ss.str();
}
}} //util //str

#endif