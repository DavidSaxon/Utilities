/*******************************************************\
| Exception Abstract Base class, extends std::exception |
|                                                       |
| @author David Saxon                                   |
\*******************************************************/
#ifndef UTILITIES_EXCEPTIONS_EXCEPTION_H_
#   define UTILITIES_EXCEPTIONS_EXCEPTION_H_

#include <exception>
#include <iostream>
#include <sstream>

namespace util { namespace ex {

class Exception : public std::exception {
public:

    //DESTRUCTOR
    virtual ~Exception() throw() {}

    //PUBLIC MEMBER FUNCTIONS
    /*Return the error message of the exception and the exception type*/
    const char* what() const throw() {

        std::string message = info();

        char* rMessage = new char[message.length()+1];
        //copy over the message
        for (unsigned i = 0; i < message.length(); ++i) {

            rMessage[i] = message[i];
        }
        //put the terminating character on the end
        rMessage[message.length()] = '\0';

        return rMessage;
    }

    /*Returns thes the error message of the exception*/
    std::string getMessage() const {

        return errMsg;
    }

protected:

    //VARIABLES
    std::string errMsg;

    //PROTECTED MEMBER FUNCTIONS
    /*Give the exception name i.e. EXCEPTION*/
    virtual std::string name() const = 0;

private:

    //PRIVATE MEMBER FUNCTIONS
    /*Returns the exception name joint with the error message*/
    std::string info() const {

        std::stringstream ss;
        ss << name() << ": " << errMsg;

        return ss.str();
    }
};
}} //util //ex

#endif