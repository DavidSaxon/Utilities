/**********************************************\
| Exceptions related to file system operations |
|                                              |
| @author David Saxon                          |
\**********************************************/
#ifndef _UTILITIES_EXCEPTIONS_FILEEXCEPTION_H_
#   define _UTILITIES_EXCEPTIONS_FILEEXCEPTION_H_

#include <iostream>
#include <sstream>

#include "Exception.hpp"

namespace util { namespace ex {

/*Abstract base class for all file exceptions*/
class FileException : public Exception {
};

/*Warns that a file does not exist*/
class NoFileExistsException : public FileException {
public:

    //CONSTRUCTOR
    NoFileExistsException(const std::string& errorMessage) {

        errMsg = errorMessage;
    }

private:

    //METHODS
    std::string name() const {

        return "NO SUCH FILE EXCEPTION";
    }
};

/*Exception warning that a direcoty does not exist*/
class NoDirExistsException : public FileException {
public:

    //CONSTRUCTOR
    NoDirExistsException(const std::string& errorMessage) {

        errMsg = errorMessage;
    }

private:

    //METHODS
    std::string name() const {

        return "NO SUCH DIRECTORY EXCEPTION";
    }

};

/*Reinterperted boost file system exception*/
class BoostFileSystemException : public FileException {
public:

    //CONSTRUCTOR
    BoostFileSystemException(const std::string& errorMessage) {

        errMsg = errorMessage;
    }

private:

    //METHODS
    std::string name() const {

        return "BOOST FILE SYSTEM EXCEPTION";
    }
};
}} //util //ex

#endif