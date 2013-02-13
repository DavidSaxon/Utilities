/**********************************************\
| Utility functions relating to binary numbers |
|                                              |
| @author David Saxon                          |
\**********************************************/
#ifndef _UTILITIES_BINARYUTIL_H_
#   define _UTILITIES_BINARYUTIL_H_

#include <iostream>

#include "ValuesUtil.hpp"

namespace util { namespace bin {

//FUNCTIONS
//TODO:
/*Converts the given integer to a biary string*/

/*Converts the given floating point number to a binary string*/

/*Converts the given double to a binary string*/

/*Returns the number of significant figure bits the given integer has*/
inline unsigned numSigBits(unsigned n) {

    //search from msb of the number till a 1 is found
    unsigned i = sizeof(n)*val::BITS_IN_BYTE-1;
    for (; i >= 0; --i) {

        if ((1 << i) & n) {

            std::cout << (1 << i) << std::endl;

            break;
        }
    }

    return i+1;
}
}} //util //bin

#endif