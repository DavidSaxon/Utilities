/*******************************************\
| Utility functions for string manipulation |
|                                           |
| @author David Saxon                       |
\*******************************************/
#ifndef UTILITIES_STRINGUTILS_H_
#   define UTILITIES_STRINGUTILS_H_

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

#include "DataStructuresUtil.hpp"

namespace util { namespace str {

//TYPEDEFS
typedef ds::ConstTuple<std::string, std::string> ConstStringTuple;

//FUNCTIONS
/*Appends string a onto the end of string b*/
inline std::string append(const std::string& a, const std::string& b) {

    std::stringstream ss;
    ss << a << b;
    return ss.str();
}

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

        if (atEquals(i, a, b)) {

            return true;
        }
    }

    return false;
}

/*Finds a the index of the start of string b in string a
returns -1 if the string is not contained within a
NOTE: if the b exits in a in multiple places the index of the first
occurrence of b will be returned*/
inline int find(const std::string& a, const std::string& b) {

    //check that a is longer than or the same length as b
    if (a.length() < b.length()) {

        return -1;
    }

    //check each index
    for (unsigned i = 0; i <= a.length()-b.length(); ++i) {

        if (atEquals(i, a, b)) {

            return i;
        }
    }

    return -1;
}

/*Returns true if the given string is an integer*/
inline bool isInt(const std::string& s) {

    //iterate over the string that each char is a digit
    //except for the first char which may be a '-'
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

/*Trims the white space from the beginning and the end of the string*/
inline std::string trim(const std::string& s) {

    std::string trimed;

    //find where the beginning white space ends
    unsigned index = 0;
    for(; (s[index] == ' ' || s[index] == '\n' || s[index] == '\r') &&
        index < s.length(); ++index);

    //trim the front of the string
    trimed = s.substr(index, s.length());

    //TODO: trim end

    return trimed;
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

/*Splits a string at the given sub string and includes the substring into
the first string
NOTE: if the string is no contained in a then a tuple is returned
with a and an empty string*/
inline ConstStringTuple splitAtStringInc(const std::string& a,
    const std::string& b) {

    //find the index of the string
    int pos = find(a, b);

    //check that b is within a
    if (pos == -1) {

        return ConstStringTuple(a, "");
    }

    unsigned splitIndex = pos+b.length();

    return ConstStringTuple(a.substr(0, splitIndex),
        a.substr(splitIndex, a.length()));
}

/*Splits a string at the given sub string and includes the substring into
the second string
NOTE: if the string is no contained in a then a tuple is returned
with a and an empty string*/
inline ConstStringTuple splitAtStringExc(const std::string& a,
    const std::string& b) {

    //find the index of the string
    int splitIndex = find(a, b);

    //check that b is within a
    if (splitIndex == -1) {

        return ConstStringTuple(a, "");
    }

    return ConstStringTuple(a.substr(0, splitIndex),
        a.substr(splitIndex, a.length()));
}

/*!Splits a string at the given sub string and discards the substring
NOTE: if the string is not contained then a tuple is returned with an and
an empty string*/
inline ConstStringTuple splitAtStringDis(const std::string& a,
    const std::string& b) {

    //find the index of the string
    int splitIndex1 = find(a, b);

    //check that b is within a
    if (splitIndex1 == -1) {

        return ConstStringTuple(a, "");
    }

    unsigned splitIndex2 = splitIndex1 + b.length();

    return ConstStringTuple(a.substr(0, splitIndex1),
        a.substr(splitIndex2, a.length()));
}

/*Replaces all occurrences of character a in string s with character b
NOTE: returns the string with no changes if it does not contain any
occurrences of a*/
inline std::string replaceAll(const std::string& s, char a, char b) {

    //make a copy of the string
    std::string sc(s);

    //iterate through the string and find all occurrences of a
    for (unsigned i = 0; i < s.length(); ++i) {

        //replace the character
        if (s[i] == a) {

            sc[i] = b;
        }
    }

    return sc;
}

/*Replaces the first occurrence of character a in string s with character b
NOTE: returns the string with no changes if it does not contain any
occurrences of a*/
inline std::string replaceFirst(const std::string& s, char a, char b) {

    //make a copy of the string
    std::string sc(s);

    //iterate through the string and find all occurrences of a
    for (unsigned i = 0; i < s.length(); ++i) {

        //replace the character
        if (s[i] == a) {

            sc[i] = b;

            return sc;
        }
    }

    return sc;
}

/*Replaces the last occurrence of character a in string s with character b
NOTE: returns the string with no changes if it does not contain any
occurrences of a*/
inline std::string replaceLast(const std::string& s, char a, char b) {

    //make a copy of the string
    std::string sc(s);

    //iterate through the string and find all occurrences of a
    for (unsigned i = s.length()-1; i >= 0; --i) {

        //replace the character
        if (s[i] == a) {

            sc[i] = b;

            return sc;
        }
    }

    return sc;
}

/*Replaces the character at the given index in string s with character a
NOTE: if the index is greater than the length of the string then a copy
of the string is returned with no changes*/
inline std::string replaceAt(const std::string& s, unsigned i, char a) {

    //make a copy of the string
    std::string sc(s);

    //if the index is out of bounds
    if (i >= s.length()) {

        return sc;
    }

    //replace the string
    sc[i] = a;

    return sc;
}

/*Copies the given string into the given char vector*/
inline void copyToVector(const std::string& s, std::vector<char>& c) {

    //iterate over the string and copy it into the vector
    for (unsigned i = 0; i< s.length(); ++i) {

        c.push_back(s.at(i));
    }
}

/*Checks if the given index in a vector of chars is the tag*/
inline bool vectorAtEquals(unsigned index, const std::vector<char>& v,
    const std::string& tag) {

    //check that the tag is shorter than the rest of the vector
    if (tag.length() >= v.size()-index) {

        return false;
    }

    //iterate over the vector and check
    for (unsigned i = 0; i < tag.length(); ++i) {

        if (tag[i] != v[i+index]) {

            return false;
        }
    }

    return true;
}

}} //util //str

#endif