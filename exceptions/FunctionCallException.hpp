/****************************************\
| Exceptions relating to function calls. |
|                                        |
| @author David Saxon                    |
\****************************************/

#ifndef UTILITIES_EXCEPTIONS_FUNCTIONCALLEXCEPTION_H_
#   define UTILITIES_EXCEPTIONS_FUNCTIONCALLEXCEPTION_H_

#include <iostream>
#include <sstream>

#include "Exception.hpp"

namespace util { namespace ex {

/*******************************************************\
| Abstract base class for all function call exceptions. |
|                                                       |
| @author David Saxon                                   |
\*******************************************************/
class FunctionCallException : public Exception {
};

/*************************************************************************\
| Exception that warns an illegal argument has been passed to a function. |
|                                                                         |
| @author David Saxon                                                     |
\*************************************************************************/
class IllegalArgumentException : public FunctionCallException {
public:

    //CONSTRUCTOR
    /*!Creates an illegal argument exception
    @_message the message of the exception*/
    IllegalArgumentException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "ILLEGAL ARGUMENT EXCEPTION";
    }
};

/***************************************************************************\
| Exception that warns of a collection being passed as an argument with too |
| many elements in the collection.                                          |
|                                                                           |
| @author David Saxon                                                       |
\***************************************************************************/
class OversizedArgumentException : public FunctionCallException {
public:

    //CONSTRUCTOR
    /*!Creates an over-sized argument exception
    @_message the message of the exception*/
    OversizedArgumentException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "OVERSIZED ARGUMENT EXCEPTION";
    }
};

/***************************************************************************\
| Exception that warns of a collection being passed as an argument with too |
| few elements in the collection.                                           |
|                                                                           |
| @author David Saxon                                                       |
\***************************************************************************/
class UndersizedArgumentException : public FunctionCallException {
public:

    //CONSTRUCTOR
    /*!Creates an under-sized argument exception
    @_message the message of the exception*/
    UndersizedArgumentException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "UNDERSIZED ARGUMENT EXCEPTION";
    }
};
}} //util //ex

#endif