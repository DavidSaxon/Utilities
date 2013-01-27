/*******************************\
| Maths based utility functions |
\*******************************/
#ifndef _UTILITIES_MATHUTILS_H_
#   define _UTILITIES_MATHUTILS_H_

#include <iostream>
#include <math.h>

namespace util { namespace math {

    //FUNCTIONS
    /*Returns true if the 3 shorts are equal*/
    bool equals3(short a, short b, short c) {

        return (a == b) && (b == c);
    }

    /*Returns true if the 3 unsigned shorts are equal*/
    bool equals3(unsigned short a, unsigned short b, unsigned short c) {

        return (a == b) && (b == c);
    }

    /*Returns true if the 3 integers are equal*/
    bool equals3(int a, int b, int c) {

        return (a == b) && (b == c);
    }

    /*Returns true if the 3 unsinged integers are equal*/
    bool equals3(unsigned a, unsigned b, unsigned c) {

        return (a == b) && (b == c);
    }

    /*Returns true if the 3 floating point numbers are equal*/
    bool equals3(float a, float b, float c) {

        return (a == b) && (b == c);
    }

    /*Returns true if the 3 doubles are equal*/
    bool equals3(double a, double b, double c) {

        return (a == b) && (b == c);
    }

    /*Returns true if the 4 shorts are equal*/
    bool equals4(short a, short b, short c, short d) {

        return (a == b) && (b == c) && (c == d);
    }

    /*Returns true if the 4 unsigned shorts are equal*/
    bool equals4(unsigned short a, unsigned short b,
        unsigned short c, unsigned short d) {

        return (a == b) && (b == c) && (c == d);
    }

    /*Returns true if the 4 integers are equal*/
    bool equals4(int a, int b, int c, int d) {

        return (a == b) && (b == c) && (c == d);
    }

    /*Returns true if the 4 unsigned integers are equal*/
    bool equals4(unsigned a, unsigned b, unsigned c, unsigned d) {

        return (a == b) && (b == c) && (c == d);
    }

    /*Returns true if the 4 floating point numbers are equal*/
    bool equals4(float a, float b, float c, float d) {

        return (a == b) && (b == c) && (c == d);
    }

    /*Returns true if the 4 doubles are equal*/
    bool equals4(double a, double b, double c, double d) {

        return (a == b) && (b == c) && (c == d);
    }

    /*!Rounds decimal places, less than 5 rounds down*/
    float halfRoundUp(float a) {

        //get just the decimal point
        unsigned b = static_cast<unsigned>(a);
        a -= b;

        //round up
        if (a >= 0.5) {

            return b+1;
        }

        //round down
        return b;
    }

    /*!Rounds decimal places, less than 6 rounds down*/
    float halfRoundDown(float a) {

        //get just the decimal point
        unsigned b = static_cast<unsigned>(a);
        a -= b;

        //round down
        if (a <= 0.5) {

            return b;
        }

        //round up
        return b+1;
    }

    /*Rounds to the nearest power of 2*/
    unsigned roundPower2(float a) {

        unsigned power2 = static_cast<unsigned>(a);

        //round to the nearest power of 2
        --power2;
        power2 |= power2 >> 1;
        power2 |= power2 >> 2;
        power2 |= power2 >> 4;
        power2 |= power2 >> 8;
        power2 |= power2 >> 16;
        ++power2;

        return power2;
    }

    /*Always rounds down to the nearest power of 2*/
    unsigned roundPower2Down(float a) {

        unsigned power2 = roundPower2(a);

        //if it was rounded up, round again
        if (power2 > static_cast<unsigned>(a)) {

            return roundPower2Down(a-1.0);
        }

        return power2;
    }

    /*Returns true if the given number is a power of 2*/
    bool isPowerOf2(int i) {

        return i > 0 && (i & (i-1)) == 0;
    }

    /*Returns true if the given number is a power of 2*/
    bool isPowerOf2(unsigned i) {

        return (i & (i-1)) == 0;
    }

    /*Returns true if the given number is a power of 2*/
    bool isPowerOf2(long i) {

        return i > 0 && (i & (i-1)) == 0;
    }

    /*Returns true if the given number is a power of 2*/
    bool isPowerOf2(unsigned long i) {

        return (i & (i-1)) == 0;
    }

    /*Returns true if the given number is a power of 2*/
    bool isPowerOf2(long long i) {

        return i > 0 && (i & (i-1)) == 0;
    }

    /*Returns true if the given number is a power of 2*/
    bool isPowerOf2(unsigned long long i) {

        return (i & (i-1)) == 0;
    }

    /*!Calculates and returns the result of n choose r*/
    unsigned choose(unsigned n, unsigned r) {

        if (r == 1) {

            return n;
        }

        if (r == 0) {

            return 1;
        }

        return static_cast<unsigned>((n*(n-1))/r);
    }

    /*Returns a decimal morton code from the two given unsigned integers
    by interleaving their bits*/
    unsigned computeDMC(unsigned a, unsigned b) {

        a = (a | (a << 8)) & 0x00ff00ff;
        a = (a | (a << 4)) & 0x0f0f0f0f;
        a = (a | (a << 2)) & 0x33333333;
        a = (a | (a << 1)) & 0x55555555;

        b = (b | (b << 8)) & 0x00ff00ff;
        b = (b | (b << 4)) & 0x0f0f0f0f;
        b = (b | (b << 2)) & 0x33333333;
        b = (b | (b << 1)) & 0x55555555;

        return a | (b << 1);
    }

    /*Decompose the given decimal morton code and places the 2 indexes
    into variables a and b*/
    void decomposeDMC(unsigned dmc, unsigned& a, unsigned& b) {

        //find the x value
        a = dmc & 0x55555555;
        a = (a ^ (a >> 1)) & 0x33333333;
        a = (a ^ (a >> 2)) & 0x0f0f0f0f;
        a = (a ^ (a >> 4)) & 0x00ff00ff;
        a = (a ^ (a >> 8)) & 0x0000ffff;
        //find the y value
        b = (dmc >> 1) & 0x55555555;
        b = (b ^ (b >> 1)) & 0x33333333;
        b = (b ^ (b >> 2)) & 0x0f0f0f0f;
        b = (b ^ (b >> 4)) & 0x00ff00ff;
        b = (b ^ (b >> 8)) & 0x0000ffff;
    }
}}

//TESTING

#endif