#include <iostream>
#include <string>

#include "FileReader.h"

using namespace std;

// Function prototype
/** Opens a file */
void openFile(FileReader &reader, string fileName);

int main()
{
    FileReader filereader;

    cout << "+------------------------------+\n"
         << "| Testing the FileReader class |\n"
         << "+------------------------------+\n\n";

    cout << "Attempting to open a non-existent file\n"
         << "--------------------------------------\n"
         << "Attempting to open a non-existent file should throw an error\n";

    openFile(filereader, "does-not-exist.txt");
    cout << endl;

    cout << "Attempting to open an existent file\n"
         << "-----------------------------------\n"
         << "Attempting to open an existent file should not throw an error\n";

    openFile(filereader, "../expressions.txt");
    cout << endl;

    cout << "Read lines until the end of the expression file is reached\n"
         << "----------------------------------------------------------\n\n";

    int count = 1;
    string expr = filereader.getline();
    while (filereader.isEof())
    {
        cout << "Expression " << count << ": " << expr << endl;
        expr = filereader.getline();
        count++;
    }

    return 0;
}

/** Opens a file
@post   The FileReader object will have an open file
@param  reader A reference to the FileReader object
@param  fileName The name of (path to) the file to open*/
void openFile(FileReader &reader, string fileName)
{
    try
    {
        reader.open(fileName);
    }
    catch (FileNotFoundException)
    {
        cerr << "ERROR: File does not exist.\n";
    }
}
