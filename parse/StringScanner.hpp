/*********************\
| A string scanner.   |
|                     |
| @author David Saxon |
\*********************/

#ifndef UTILITIES_PARSE_STRINGSCANNER_H_
#   define UTILITIES_PARSE_STRINGSCANNER_H_

#include <iostream>

namespace util { namespace parse {

class StringScanner {
public:

    //CONSTRUCTOR
    /*!Creates a new string scanner\
    @_string the string to read*/
    StringScanner(const std::string& _string) :
        str(_string),
        index(0),
        atEnd(false) {

        //read the first line of the string
        readNextLine();
    }

    /*Copies this scanner from the other string scanner
    #NOTE: this will not keep the position of the scanner
    @other the other file scanner*/
    StringScanner(const StringScanner& other) :
        str(other.str),
        index(0),
        atEnd(false) {

        readNextLine();
    }

    //DESTRUCTOR
    /*!Destroys the string scanner*/
    ~StringScanner() {
    }

    //OPERATORS
    /*!Copies the string from the other scanner to this scanner
    #NOTE: this will not keep the position of the scanner
    @other the other file scanner*/
    inline const StringScanner& operator=(const StringScanner& other) {

        str = other.str;
        index = 0;
        atEnd = false;

        readNextLine();

        return *this;
    }

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the next string between white space characters in the string*/
    inline std::string next() {

        while(hasNext()) {

            //read the line looking for non white space chars
            for(unsigned i = 0; i < currentLine.length(); ++i) {

                if (currentLine[i] != ' ' && currentLine[i]  != '\t') {

                    //remove the white space
                    currentLine = currentLine.substr(i, currentLine.length());

                    //read through the full string and return
                    return readString();
                }
            }

            //get the next line
            readNextLine();
        }

        return "";
    }

    /*!@return the next line in the string*/
    inline std::string nextLine() {

        //store the current line
        std::string nextLine = currentLine;
        //get the next line
        readNextLine();

        return nextLine;
    }

    /*!@return if there is still data to be read*/
    inline bool hasNext() const {

        //std::cout << "_" << currentLine << "_" << std::endl;

        return currentLine != "";
    }

    /*!@return if there is a next line in the string*/
    inline bool hasNextLine() const {

        return atEnd;
    }


private:

    //VARIABLES
    //the string
    std::string str;
    //the current line of the scanner
    std::string currentLine;

    //the index in the string
    unsigned index;

    //is true when we are at the end of the string
    bool atEnd;

    //PRIVATE MEMBER FUNCTIONS
    /*!Reads the next line of the string*/
    inline void readNextLine() {

        for (unsigned i = index; i < str.length(); ++i) {

            if (str[i] == '\n') {

                if (i == str.length() - 1) {

                    atEnd = true;
                }

                //read the current line
                currentLine = str.substr(index, i);
                index = i + 1;

                return;
            }
        }

        atEnd = true;

        currentLine = str.substr(index, str.length());

        index = str.length();
    }

    /*!Reads the next string that is surrounded by white space*/
    inline std::string readString() {

        //read until either the end of the line or a white space char
        for (unsigned i = 0; i < currentLine.length(); ++i) {

            if (currentLine[i] == ' ' || currentLine[i] == '\t') {

                //get this string
                std::string line = currentLine.substr(0, i);

                //find the next non white space char
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
        readNextLine();

        return line;
    }
};

} } //util //parse

#endif