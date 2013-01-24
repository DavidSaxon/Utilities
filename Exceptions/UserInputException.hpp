/**********************************\
| Exceptions related to user input |
\**********************************/
#ifndef _UTILITIES_EXCEPTIONS_USERINPUTEXCEPTION_H_
#   define _UTILITIES_EXCEPTIONS_USERINPUTEXCEPTION_H_

#include <iostream>
#include <sstream>

#include "Exception.hpp"

namespace util { namespace ex {

    /*Abstract base class for all user input exceptions*/
    class UserInputException : public Exception {
    };

    /*Exception that warns of an invalid program flag given*/
    class InvalidProgramFlag : public UserInputException {
    public:

        //CONSTRUCTOR
        InvalidProgramFlag(std::string errorMessage) {

            errMsg = errorMessage;
        }

    private:

        //METHODS
        std::string name() const {

            return "INVALID PROGRAM FLAG";
        }
    };

}}

#endif