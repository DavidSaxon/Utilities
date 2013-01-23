/*************************************\
| Utility functions relating to bytes |
\*************************************/
#ifndef _UTILITIES_BYTEUTIL_H_
    #define _UTILITIES_BYTEUTIL_H_

#include <stdlib.h>

namespace util { namespace byte {

    typedef unsigned char byte;

    /*Converts an integer into its bytes which are stored in the given array
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    void intToBytes(int i, byte* b) {

        for (unsigned j = 0; j < sizeof(i); ++j) {
            b[j] = (i >> (j*8));
        }
    }

    /*Converts a long into its bytes which are stored in the given array
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    void longToBytes(long i, byte* b) {

        for (unsigned j = 0; j < sizeof(i); ++j) {
            b[j] = (i >> (j*8));
        }
    }

    /*Converts a long long into its bytes which are stored in the given array
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    void longLongToBytes(long long i, byte* b) {

        for (unsigned j = 0; j < sizeof(i); ++j) {
            b[j] = (i >> (j*8));
        }
    }

    /*!Converts the given array bytes to a short
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    short bytesToShort(byte* b) {

        short i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }

    /*!Converts the given array bytes to an unsigned short
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    unsigned short bytesToUShort(byte* b) {

        unsigned short i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }

    /*!Converts the given array bytes to an integer
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    int bytesToInt(byte* b) {

        int i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }

    /*!Converts the given array bytes to an unsigned integer
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    unsigned bytesToUInt(byte* b) {

        unsigned i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }

    /*!Converts the given array bytes to a long
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    long bytesToLong(byte* b) {

        long i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }

    /*!Converts the given array bytes to an unsigned long
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    unsigned long bytesToULong(byte* b) {

        unsigned long i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }

    /*!Converts the given array bytes to a long long
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    long long bytesToLongLong(byte* b) {

        long long i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }

    /*!Converts the given array bytes to an unsigned long long
    #WARNING: byte is assumed to have sizeof(i) elements#*/
    unsigned long long bytesToULongLong(byte* b) {

        unsigned long long i = 0;
        std::memcpy(&i, b, sizeof(i));
        return i;
    }
}}

#endif