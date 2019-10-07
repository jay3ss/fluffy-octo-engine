#include "FileReader.h"

/** Default constructor */
FileReader::FileReader() {}

/** Constructor */
FileReader::FileReader(std::string fileName)
{
    open(fileName);
}

/** Destructor */
FileReader::~FileReader()
{
    expressionFile_.close();
}

/** Reads and returns the next line in the expression file */
std::string FileReader::getline()
{
    std::string line;
    std::getline(expressionFile_, line);

    return line;
}

/** Opens the expression file */
void FileReader::open(std::string fileName)
{
    expressionFile_.open(fileName, std::ios::in);

    if (!expressionFile_)
    {
        throw FileNotFoundException();
    }
}

/** Determines if the end of file has been reached */
bool FileReader::isEof()
{
    return expressionFile_.good();
}
