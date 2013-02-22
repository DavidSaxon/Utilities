/*******************************************\
| Functions relating to equality operations |
|                                           |
| @author David Saxon                       |
\*******************************************/
#ifndef UTILITIES_EQUALITYUTIL_H_
#   define UTILITIES_EQUALITYUTIL_H_

#include <iostream>

namespace util { namespace eql {

//FUNCTIONS
/*Tests if the 3 given arguments are equal*/
template<typename T>
inline bool equals3(T a, T b, T c) {

    return (a == b) && (b == c);
}

/*Tests if the 3 floats are equals*/
inline bool equals3(float a, float b, float c) {

    return floatingPointEqual(a, b) && floatingPointEqual(b, c);
}

/*Tests if the 3 doubles are equals*/
inline bool equals3(double a, double b, double c) {

    return floatingPointEqual(a, b) && floatingPointEqual(b, c);
}

/*Tests if the 4 given arguments are equal*/
template<typename T>
inline bool equals4(T a, T b, T c, T d) {

    return (a == b) && (b == c) && (c == d);
}

/*Tests if the 4 floats are equals*/
inline bool equals4(float a, float b, float c, float d) {

    return floatingPointEqual(a, b) && floatingPointEqual(b, c) &&
        floatingPointEqual(c, d);
}

/*Tests if the 4 doubles are equals*/
inline bool equals4(double a, double b, double c) {

    return floatingPointEqual(a, b) && floatingPointEqual(b, c) &&
        floatingPointEqual(c, d);
}

/*Returns true if float a is equal to float b (or very close to equal)*/
inline bool floatingPointEqual(float a, float b) {

    const float epsilion = 0.000001;

    return abs(a - b) <= epsilion * abs(a);
}

/*Returns true if double a is equal to double b (or very close to equal)*/
inline bool floatingPointEqual(double a, double b) {

    const double epsilion = 0.000001;

    return abs(a - b) <= epsilion * abs(a);
}

} } //util //eql

#endif