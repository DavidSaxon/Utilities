/***************************************\
| Exceptions relating to function calls |
|                                       |
| @author David Saxon                   |
\***************************************/
#ifndef _UTILITIES_EXCEPTIONS_FUNCTIONCALLEXCEPTION_H_
#   define _UTILITIES_EXCEPTIONS_FUNCTIONCALLEXCEPTION_H_

#include <iostream>
#include <sstream>

#include "Exception.hpp"

namespace util { namespace ex {

/*Abstract basee class for all function call exceptions*/
class FunctionCallException : public Exception {
};

/*!Exception that warns of illegal argument provided to a function*/
class IllegalArgumentException : public FunctionCallException {
public:

    //CONSTRUCTOR
    IllegalArgumentException(const std::string& errorMessage) {

        errMsg = errorMessage;
    }

private:

    //METHODS
    std::string name() const {

        return "ILLEGAL ARGUMENT EXCEPTION";
    }
};

/*!Exception that warns of a collection being passed as an argument with too
many elements*/
class OversizedArgumentException : public FunctionCallException {
public:

    //CONSTRUCTOR
    OversizedArgumentException(const std::string& errorMessage) {

        errMsg = errorMessage;
    }

private:

    //METHODS
    std::string name() const {

        return "OVERSIZED ARGUMENT EXCEPTION";
    }
};

/*!Exception that warns of a collection being passed as an argument with too
few elements*/
class UndersizedArgumentException : public FunctionCallException {
public:

    //CONSTRUCTOR
    UndersizedArgumentException(const std::string& errorMessage) {

        errMsg = errorMessage;
    }

private:

    //METHODS
    std::string name() const {

        return "UNDERSIZED ARGUMENT EXCEPTION";
    }
};
}} //util //ex

#endif