/***********************************\
| Exceptions related to user input. |
|                                   |
| @author David Saxon               |
\***********************************/

#ifndef _UTILITIES_EXCEPTIONS_USERINPUTEXCEPTION_H_
#   define _UTILITIES_EXCEPTIONS_USERINPUTEXCEPTION_H_

#include "Exception.hpp"

namespace util { namespace ex {

/****************************************************\
| Abstract base class for all user input exceptions. |
|                                                    |
| @author David Saxon                                |
\****************************************************/
class UserInputException : public Exception {
};

/**************************************************\
| Exception that warns of an invalid program flag. |
|                                                  |
| @author David Saxon                              |
\**************************************************/
class InvalidProgramFlag : public UserInputException {
public:

    //CONSTRUCTOR
    /*!Creates an invalid program flag exception
    @_message the message of the exception*/
    InvalidProgramFlag(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "INVALID PROGRAM FLAG EXCEPTION";
    }
};

/**********************************************************************\
| Exception that warns too few command line arguments have been given. |
|                                                                      |
| @author David Saxon                                                  |
\**********************************************************************/
class TooFewArgumentsException : public Exception {
public:

    //CONSTRUCTOR
    /*!Creates a too few arguments exception
    @_message the message of the exception*/
    TooFewArgumentsException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "TOO FEW ARGUMENTS EXCEPTION";
    }

};

/***********************************************************************\
| Exception that warns too many command line arguments have been given. |
|                                                                       |
| @author David Saxon                                                   |
\***********************************************************************/
class TooManyArgumentsException : public Exception {
public:

    //CONSTRUCTOR
    /*!Creates a too many arguments exception
    @_message the message of the exception*/
    TooManyArgumentsException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "TOO MANY ARGUMENTS EXCEPTION";
    }
};

/******************************************************\
| Exception that warns of a bad command line argument. |
|                                                      |
| @author David Saxon                                  |
\************************************ *****************/
class BadArgumentException : public Exception {
public:

    //CONSTRUCTOR
    /*!Creates a bad argument exception
    @_message the message of the exception*/
    BadArgumentException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "BAD ARGUMENT EXCEPTION";
    }
};

}} //util //ex

#endif