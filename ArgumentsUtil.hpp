/******************************************************\
| Utility functions relating to command line arguments |
\******************************************************/
#ifndef _UTILITY_ARGUMENTSUTIL_H_
#   define _UTILITY_ARGUMENTSUTIL_H_

#include <iostream>
#include <vector>
#include <map>

#include "exceptions/FunctionCallException.hpp"
#include "exceptions/UserInputException.hpp"

//TYPEDEFS
typedef std::map<std::string , bool*> flagMapType;

namespace util { namespace arg {

    /*!Reads the command line arguments, a map is given that map flags to
    booleans. If a flag is read it's matching boolean is set to true. Any
    arugments that are not flags are returned as strings in a vector in the
    order they were read. Flags must start with '--'*/
    std::vector<std::string> parseArguments(int argc, char*argv[],
        flagMapType& flagMap) {

        //check that none of the flags contain "--"
        //also find the length of the longest argument
        unsigned longestArg = 0;
        flagMapType::const_iterator
            it = flagMap.begin(),
            ite = flagMap.end();
        for (; it != ite; ++it) {

            //iterate over the letters of the key
            for (unsigned i = 0; i < it->first.length(); ++i) {

                //if found "--" throw an illegal arument exception
                if (it->first.at(i) == '-' && i < it->first.length()-1 &&
                    it->first.at(i+1) == '-') {

                    throw ex::IllegalArgumentException(
                        "flag contains illegal string \"--\"");
                }
            }

            //check if the new longest argument
            if (it->first.length() > longestArg) {

                longestArg = it->first.length();
            }
        }

        //create a vector to place aruments in
        std::vector<std::string> returnVec;

        //iterate over the arguments and identify if they are a string or a flag
        for (unsigned i = 1; i < argc; ++i) {

            //if a flag
            if (argv[i][0] == '-' && argv[i][1] == '-') {

                unsigned j = 0;
                //process a flags
                while (argv[i][j] != '\0') {

                    //get rid of any extra -
                    for (; argv[i][j] == '-'; ++j);

                    //check against valid flags and find the
                    //longest possible flag
                    std::string bestMatchFlag = "-";
                    for (unsigned k = 0; k < longestArg &&
                        argv[i][k+j] != '\0'; ++k) {

                        std::string checkFlag(argv[i]+j);
                        checkFlag = checkFlag.substr(0, k+1);

                        //now check if the string is in the map
                        flagMapType::iterator contains =
                            flagMap.find(checkFlag);
                        if (contains != flagMap.end()) {

                            //flag has been found
                            bestMatchFlag = checkFlag;
                        }
                    }

                    //no valid flags were found throw an exception
                    if (bestMatchFlag == "-") {

                        std::stringstream ss;
                        ss << argv[i][j] << " in argument " << i
                            << " at character " << j
                            << " is not a recognised program flag";
                        throw ex::InvalidProgramFlag(ss.str());
                    }
                    //flag has been found, set the related boolean to true
                    else {

                        *flagMap[bestMatchFlag] = true;
                    }

                    j += bestMatchFlag.length();
                }
            }
            //else is a string so add to vector
            else {

                returnVec.push_back(std::string(argv[i]));
            }
        }

        return returnVec;
    }
}}

#endif