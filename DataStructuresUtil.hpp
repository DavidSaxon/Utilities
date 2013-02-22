/*********************************\
| A set of useful data structures |
|                                 |
| @author David Saxon             |
\*********************************/
#ifndef _UTIL_DATASTRUCTURES_H_
#   define _UTIL_DATASTRUCTURES_H_

#include <iostream>

namespace util { namespace ds {

//STRUCTURES
/*~Contains 2 elements of possibly different types,
values cannot be changed*/
template <typename T, typename U>
struct ConstTuple {

    //VARIABELS
    const T first;
    const U second;

    //CONSTRUCTOR
    /*Creates a new tuple
    ^INL
    @param _t the first value
    @param _u the second value*/
    ConstTuple(T f, U s) :
        first(f),
        second(s) {}
};

/*~Contains 2 elements of possibly different types*/
template <typename T, typename U>
struct Tuple {

    //VARIABELS
    T first;
    U second;

    //CONSTRUCTOR
    /*Creates a new tuple
    ^INL
    @param _t the first value
    @param _u the second value*/
    Tuple(T f, U s) :
        first(f),
        second(s) {}
};


}} //util //ds

#endif