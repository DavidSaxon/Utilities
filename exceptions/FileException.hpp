/***********************************************\
| Exceptions related to file system operations. |
|                                               |
| @author David Saxon                           |
\***********************************************/

#ifndef UTILITIES_EXCEPTIONS_FILEEXCEPTION_H_
#   define UTILITIES_EXCEPTIONS_FILEEXCEPTION_H_

#include "Exception.hpp"

namespace util { namespace ex {

/**********************************************\
| Abstract base class for all file exceptions. |
|                                              |
| @author David Saxon                          |
\**********************************************/
class FileException : public Exception {
};

/*********************************************\
| Exception that warns a file does not exist. |
|                                             |
| @author David Saxon                         |
\*********************************************/
class NoFileExistsException : public FileException {
public:

    //CONSTRUCTOR
    /*!Creates a no file exists exception
    @_message the message of the exception*/
    NoFileExistsException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "NO SUCH FILE EXCEPTION";
    }
};

/**************************************************\
| Exception that warns a directory does not exist. |
|                                                  |
| @author David Saxon                              |
\**************************************************/
class NoDirExistsException : public FileException {
public:

    //CONSTRUCTOR
    /*!Creates a no directory exists exception
    @_message the message of the exception*/
    NoDirExistsException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "NO SUCH DIRECTORY EXCEPTION";
    }

};

/********************************************\
| Reinterpreted boost file system exception. |
|                                            |
| @author David Saxon                        |
\********************************************/
class BoostFileSystemException : public FileException {
public:

    //CONSTRUCTOR
    /*!Creates a boost file system exception
    @_message the message of the exception*/
    BoostFileSystemException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "BOOST FILE SYSTEM EXCEPTION";
    }
};
}} //util //ex

#endif