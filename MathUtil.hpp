/*******************************\
| Maths based utility functions |
|                               |
| @author David Saxon           |
\*******************************/
#ifndef _UTILITIES_MATHUTILS_H_
#   define _UTILITIES_MATHUTILS_H_

#include <iostream>
#include <stdlib.h>
#include <math.h>

namespace util { namespace math {

//FUNCTIONS
/*!Rounds decimal places, less than 5 rounds down*/
inline float halfRoundUp(double a) {

    //get just the decimal point
    unsigned b = static_cast<unsigned>(a);
    a -= b;

    //round up
    if (a >= 0.5) {

        return b + 1;
    }

    //round down
    return b;
}

/*!Rounds decimal places, less than 6 rounds down*/
inline double halfRoundDown(double a) {

    //get just the decimal point
    unsigned b = static_cast<unsigned>(a);
    a -= b;

    //round down
    if (a <= 0.5) {

        return b;
    }

    //round up
    return b + 1;
}

/*Caps the given value at the threshold
#WARNING: type must implement the > operator*/
template <typename T>
inline T cap(T val, T threshold) {

    if (val > threshold) {

        return threshold;
    }

    return val;
}

/*Limits the given number at the threshold, opposite to cap
#WARNING: type must implement the < operator*/
template <typename T>
inline T boost(T val, T threshold) {

    if (val < threshold) {

        return threshold;
    }

    return val;
}

/*Rounds to the nearest power of 2*/
inline unsigned roundPower2(double a) {

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
inline unsigned roundPower2Down(double a) {

    unsigned power2 = roundPower2(a);

    //if it was rounded up, round again
    if (power2 > static_cast<unsigned>(a)) {

        return roundPower2Down(a - 1.0);
    }

    return power2;
}

/*Returns true if the given number is a power2
#WARNING: should only be used for P.O.D. number types*/
template <typename T>
inline bool isPowerOf2(T a) {

    return a > 0 && (a & (a - 1)) == 0;
}

/*!Calculates and returns the result of n choose r*/
inline unsigned choose(unsigned n, unsigned r) {

    if (r == 1) {

        return n;
    }

    if (r == 0) {

        return 1;
    }

    return static_cast<unsigned>((n * (n - 1)) / r);
}

/*Returns a decimal morton code from the two given unsigned integers
by interleaving their bits*/
inline unsigned computeDMC(unsigned a, unsigned b) {

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
inline void decomposeDMC(unsigned dmc, unsigned& a, unsigned& b) {

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
}} //util //math

#endif