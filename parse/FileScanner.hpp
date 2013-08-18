/*********************\
| A file scanner.     |
|                     |
| @author David Saxon |
\*********************/

#ifndef UTILITIES_PARSE_FILESCANNER_H_
#   define UTILITIES_PARSE_FILESCANNER_H_

#include <fstream>
#include <iostream>

namespace util { namespace parse {

class FileScanner {
public:

    //CONSTRUCTOR
    /*!Creates a new file scanner
    @_path the path of the file to open*/
    FileScanner(const std::string& _path) :
        path(_path) {

        //open the file
        file.open(path.c_str());

        //get the next line
        readNextLine();
    }

    /*!Copies this scanner from the other scanner
    #NOTE: this will not keep the position of the scanner
    @other the other scanner to copy from*/
    FileScanner(const FileScanner& other) {

        path = other.path;

        //open the file file
        file.open(path.c_str());

        //get the next line
        readNextLine();
    }

    //DESTRUCTOR
    /*!Destroys the file scanner*/
    ~FileScanner() {

        file.close();
    }

    //OPERATORS
    /*!Copies the file from the other scanner to this scanner
    #NOTE: this will not keep the position of the scanner
    @other the other scanner to copy from*/
    inline const FileScanner& operator=(const FileScanner& other) {

        path = other.path;

        //open the file file
        file.open(path.c_str());

        //get the next line
        readNextLine();

        return *this;
    }

    //PUBLIC MEMBER FUNCTIONS
    /*!Returns the current line with out moving to the next line yet
    @return the current line*/
    inline const std::string& getLine() const {

        return currentLine;
    }

    /*!returns the next string in the file
    @return the next string*/
    inline std::string next() {

        //read until we find a non white space character
        while (file.good()) {

            //read through this line looking for non-white space chars
            for (unsigned i = 0; i < currentLine.length(); ++i) {

                //look for non-white space char
                if (currentLine[i] != ' ' && currentLine[i] != '\t') {

                    //remove the white space
                    currentLine = currentLine.substr(i, currentLine.length());

                    //read the next full string and return
                    return readString();
                }
            }

            //get the next line
            readNextLine();
        }

        return "";
    }

    /*!Gets the next line in the scanner
    @return the next line*/
    inline std::string nextLine() {

        //store the current line
        std::string nextLine = currentLine;
        //get the next line'
        readNextLine();

        return nextLine;
    }

    /*!Closes the file scanner*/
    inline void close() {

        file.close();
    }

    /*!@return if there is a next string in the current line*/
    inline bool hasNextInLine() {

        //search for non-white space chars
        for (unsigned i = 0; i < currentLine.length(); ++i) {

            if (currentLine[i] != ' ' && currentLine[i] != '\t') {

                return true;
            }
        }

        return false;
    }

    /*!@return if the there is next line in the scanner*/
    inline bool hasNextLine() const {

        return file.good();
    }

private:

    //VARIABLES
    //the file stream
    std::ifstream file;
    //the path of the file
    std::string path;

    //the current line of the file
    std::string currentLine;

    //PRIVATE MEMBER FUNCTIONS
    /*!Reads the next line of the file*/
    inline void readNextLine() {

        if (file.good()) {

            //create a buffer to put the line in
            char lineBuffer[1000];

            //get the line
            file.getline(lineBuffer, 1000);

            //put into the string
            currentLine = std::string(lineBuffer);
        }
        else {

            currentLine = "";
        }
    }

    /*!Reads the next string in the current line*/
    inline std::string readString() {

        //read until either the end of the the line
        //or a white space character
        for (unsigned i = 0; i < currentLine.length(); ++i) {

            if (currentLine[i] == ' ' || currentLine[i] == '\t') {

                //get this string
                std::string line = currentLine.substr(0, i);

                //find the next non white space character
                for (unsigned j = i; j < currentLine.length(); ++j) {

                    if (currentLine[j] != ' ' && currentLine[j] != '\t') {

                        currentLine =
                            currentLine.substr(j, currentLine.length());

                        return line;
                    }
                }

                readNextLine();
                
                return line;
            }
        }

        //store this line
        std::string line = currentLine;

        //read the next line
        readNextLine();

        return line;
    }
};

} } //util //parse

#endif