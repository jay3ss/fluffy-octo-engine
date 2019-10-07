#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <fstream>
#include <iostream>
#include <string>

class FileReader
{
public:
    /** Default constructor */
    FileReader();

    /** Constructor */
    FileReader(std::string fileName);

    /** Destructor */
    ~FileReader();

    /** Reads and returns the next line in the expression file
    @pre    Must have another line to read
    @post   The internal fstream object will point to the next line in the
    file
    @returns One line of text from the file */
    std::string getline();

    /** Opens the expression file */
    void open(std::string fileName);

    /** Determines if the end of file has been reached */
    bool isEof();
private:
    std::fstream expressionFile_;
};

// Custom exception class
class FileNotFoundException {};

#endif // _FILE_READER_H
