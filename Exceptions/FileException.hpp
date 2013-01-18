/**********************************************\
| Exceptions related to file system operations |
\**********************************************/
#ifndef _UTILITIES_EXCEPTIONS_FILEEXCEPTION_H_
#   define _UTILITIES_EXCEPTIONS_FILEEXCEPTION_H_

#include <iostream>
#include <sstream>

#include "Exception.hpp"

namespace util { namespace ex {

    /*Base class for all file exceptions, should not be directly used*/
    class FileException : public Exception {
    };

    /*Exception warning that a direcoty does not exist*/
    class NoDirExistsException : public FileException {
    public:

        //CONSTRUCTOR
        NoDirExistsException(std::string errorMessage) {

            errMsg = errorMessage;
        }

        //METHODS
        std::string name() const {

            return "NO SUCH DIRECTORY EXCEPTION";
        }

    };

    /*Reinterperted boost file system exception*/
    class BoostFileSystemException : public FileException {
    public:

        //CONSTRUCTOR
        BoostFileSystemException(std::string errorMessage) {

            errMsg = errorMessage;
        }

        //METHODS
        std::string name() const {

            return "BOOST FILE SYSTEM EXCEPTION";
        }
    };

}}

#endif