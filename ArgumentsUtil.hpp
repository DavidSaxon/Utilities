/*****************************************\
| Utility functions relating to arguments |
|                                         |
| @author David Saxon                     |
\*****************************************/
#ifndef UTILITY_ARGUMENTSUTIL_H_
#   define UTILITY_ARGUMENTSUTIL_H_

#include <iostream>
#include <map>
#include <vector>

#include "exceptions/FunctionCallException.hpp"
#include "exceptions/UserInputException.hpp"
#include "MathUtil.hpp"
#include "ValuesUtil.hpp"

//TYPEDEFS
typedef std::map<std::string, bool*> cmdFlagMap;
typedef std::map<unsigned, bool*> enumFlagMap;

namespace util { namespace arg {

//FUNCTIONS
/*!Reads the command line arguments, a map is given that map flags to
booleans. If a flag is read it's matching boolean is set to true. Any
arugments that are not flags are returned as strings in a vector in the
order they were read. Flags must start with '--'*/
inline std::vector<std::string> parseCmdLineArguments(int argc, char*argv[],
    cmdFlagMap& flagMap) {

    //check that none of the flags contain "--"
    //also find the length of the longest argument
    unsigned longestArg = 0;
    cmdFlagMap::const_iterator
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
                    cmdFlagMap::iterator contains =
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

/*!Reads enumerators that have been stored in an unsigned int. If an
enumerator is found the corresponding boolean in the map is set to true.
@i the unsigned integer containing enumerators
@flags a mapping from enumerators to pointers to booleans
#WARNING: enumerators should only be powers of 2 such as:
1 (1), 2 (10), 4 (100), 8 (1000), 16 (10000), etc.
There should be no more than 32 flags as this can no longer be mapped to
an unsigned integer
$IllegalArgumentException if the map contains an enumerator that is
not a power of 2
$OversizedArgumentException if the map has more than 32 elements*/
inline unsigned readFlags(unsigned i, enumFlagMap& flags) {

    //check the flags are powers of 2
    enumFlagMap::const_iterator
        it = flags.begin(),
        ite = flags.end();
    for (; it != ite; ++it) {

        //if the enum is not a power of 2 throw an exception
        if (!math::isPowerOf2(it->first)) {

            throw ex::IllegalArgumentException(
                "non power of 2 enumertor found in flag map");
        }
    }

    //check that there are no more than 32 flags
    if (flags.size() > val::BITS_IN_INT) {

        throw ex::OversizedArgumentException(
            "flag map has too many elements (limit is 32)");
    }

    //iterate through the flag map and & each element against the int
    it = flags.begin();
    for (; it != ite; ++it) {

        if (it->first & i) {

            *it->second = true;
        }
    }
}
}} //util //arg

#endif