/**********************************************\
| Utility functions in relation to file system |
\**********************************************/
#ifndef _UTILITIES_FILESYSTEMUTILS_H_
#   define _UTILITIES_FILESYSTEMUTILS_H_

#include <iostream>
#include <boost/filesystem.hpp>

#include "Exceptions/FileException.hpp"

namespace bfs = boost::filesystem;

namespace util {

    /*Prints the directories contents to the given output stream*/
    void printDirectoryContents(const std::string& dir, std::ostream& out) {

        //create a boost path from the directory name
        bfs::path p(dir);

        try {

            //check if the directory actually exists
            if (bfs::exists(p)) {

                //if it is a regulare file then print
                if (bfs::is_regular_file(p)) {
                    out << "-> " << p << std::endl;
                }
                //else if is a directory then iterator over other directories
                else if (bfs::is_directory(p)) {

                    out << "-v " << p << std::endl;

                    bfs::directory_iterator ite;
                    for (bfs::directory_iterator it(p); it != ite; ++it) {

                        printDirectoryContents(it->path().string(), out);
                    }
                }
            }
            //the path does not exist throw an exception
            else {

                std::stringstream ss;
                ss << "directory " << p << " does not exist";
                throw util::ex::NoDirExistsException(ss.str());
            }
        }
        catch (const bfs::filesystem_error& fe) {

            //rethrow expection as a file exception
            throw util::ex::BoostFileSystemException(fe.what());
        }


    }

}

#endif
