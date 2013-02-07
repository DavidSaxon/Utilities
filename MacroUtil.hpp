/***************\
| Useful marcos |
\***************/
#ifndef _UTILITIES_MACROUTIL_H_
#   define _UTILITIES_MACROUTIL_H_

//!Use this macro in the private section of a class disallow
//!copying and assignment, use the class name as the TypeName
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);             \
    void operator=(const TypeName&)

#endif