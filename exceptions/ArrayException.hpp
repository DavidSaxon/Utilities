/****************************************************\
| Exceptions related to array (and list operations). |
|                                                    |
| @author David Saxon                                |
\****************************************************/

#ifndef UTILITIES_EXCEPTIONS_ARRAYEXCEPTION_H_
#   define UTILITIES_EXCEPTIONS_ARRAYEXCEPTION_H_

#include "Exception.hpp"

namespace util { namespace ex {

/***********************************************\
| Abstract base class for all array exceptions. |
|                                               |
| @author David Saxon                           |
\***********************************************/
class ArrayException : public Exception {
};

/**********************************************\
| Warns that the given index is out of bounds. |
|                                              |
| @author David Saxon                          |
\**********************************************/
class IndexOutOfBoundsException : public ArrayException {
public:

    //CONSTRUCTOR
    /*!Creates a new index out of bounds exception
    @_message the error message*/
    IndexOutOfBoundsException(const std::string& _message) {

        errMsg = _message;
    }

private:

    //PRIVATE MEMBER FUNCTIONS
    /*!@return the name of the exception*/
    std::string name() const {

        return "INDEX OUT OF BOUNDS EXCEPTION";
    }
};

} } //util //ex

#endif