/**********************************************\
| Utility functions in relation to file system |
\**********************************************/
#ifndef _UTILITIES_FILESYSTEMUTILS_H_
#   define _UTILITIES_FILESYSTEMUTILS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <boost/filesystem.hpp>

#include "exceptions/FileException.hpp"

namespace util { namespace file {

namespace bfs = boost::filesystem;

//FUNCTIONS
/*Checks that the given file exists*/
inline bool fileExists(const std::string& filename) {

    //create a boost path from the file name
    bfs::path p(filename);

    return bfs::exists(p) && bfs::is_regular_file(p);
}

/*Checks that a given directory exists*/
inline bool dirExists(const std::string& dirName) {

    //create a boost path from the directory name
    bfs::path p(dirName);

    return bfs::exists(p) && bfs::is_directory(p);
}

/*Prints the contents of the given file to the given outputstream*/
inline void printFile(const std::string& filename, std::ostream& out) {

    //check that the given directory exists
    if (!fileExists(filename)) {

        std::stringstream ss;
        ss << "\"" << filename << "\" does not exist";
        throw ex::NoFileExistsException(ss.str());
    }

    //open the file
    std::ifstream file(filename.c_str());

    while (file.good()) {

        //create a new line buffer
        char lineBuffer[1000];

        file.getline(lineBuffer, 1000);

        out << lineBuffer << std::endl;
    }

    file.close();
}

/*Prints the directories contents to the given output stream*/
inline void printDirectoryContents(const std::string& dirName, std::ostream& out) {

    //create a boost path from the directory name
    bfs::path p(dirName);

    try {

        //check if the directory actually exists
        if (bfs::exists(p)) {

            //if it is a regular file then print
            if (bfs::is_regular_file(p)) {
                out << "-> " << p << std::endl;
            }
            //else if is a directory then iterator over other paths
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
            throw ex::NoDirExistsException(ss.str());
        }
    }
    catch (const bfs::filesystem_error& fe) {

        //rethrow expection as a file exception
        throw ex::BoostFileSystemException(fe.what());
    }
}

/*Places all of the files within the given directory pathnames
in the given vector as strings*/
inline void getPathsInDir(const std::string& dirName,
    std::vector<std::string>& v) {

    //create a boost path from the directory name
    bfs::path p(dirName);

    try {

        //check if the directory actually exists
        if (bfs::exists(p)) {

            //if it s a regular file then add to the vector
            if (bfs::is_regular_file(p)) {
                v.push_back(p.string());
            }
            //else if it's a directory, so iterator over the paths within
            else if (bfs::is_directory(p)) {

                bfs::directory_iterator ite;
                for (bfs::directory_iterator it(p); it != ite; ++it) {

                    getPathsInDir(it->path().string(), v);
                }
            }
            //do nothing if not a directory or a file
        }
        //the path does not exist, throw an exception
        else {

            std::stringstream ss;
            ss << "directory " << p << " does not exist";
            throw ex::NoDirExistsException(ss.str());
        }
    }
    catch (const bfs::filesystem_error& fe) {

        //rethrow expection as a file exception
        throw ex::BoostFileSystemException(fe.what());
    }
}
}} //util //file

#endif