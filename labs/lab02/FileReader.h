#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <fstream>
#include <iostream>
#include <string>

class FileReader
{
public:
    FileReader(std::string fileName);
    FileReader();
    ~FileReader();

    /** Reads and returns the next line in the expression file
    @pre    Must have another line to read
    @post   The
    */
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
