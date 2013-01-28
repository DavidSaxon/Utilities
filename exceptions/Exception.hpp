/*******************************************************\
| Exception Abstract Base class, extends std::exception |
\*******************************************************/
#ifndef _UTILITIES_EXCEPTIONS_EXCEPTION_H_
#   define _UTILITIES_EXCEPTIONS_EXCEPTION_H_

#include <iostream>
#include <sstream>
#include <exception>

namespace util { namespace ex {

class Exception : public std::exception {
public:

    //DESTRUCTOR
    virtual ~Exception() throw() {}

    //METHODS
    /*Return the error message of the exception*/
    const char* what() const throw() {

        return info();
        //return errMsg.c_str();
    }

    /*Returns the exception name joint with the error message*/
    const char* info() const {

        std::stringstream ss;
        ss << name() << ": " << errMsg;

        return ss.str().c_str();
    }

    /*Give the exception name i.e. EXCEPTION*/
    virtual std::string name() const = 0;

protected:

    //VARIABLES
    std::string errMsg;
};
}} //util //ex

#endif