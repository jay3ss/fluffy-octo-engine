#include <iostream>
#include <string>
#include <vector>

#include "FileReader.h"
#include "PostfixEvaluator.h"

using namespace std;

// Function prototype
/** Opens a file */
bool openFile(FileReader &reader, string fileName);

int main()
{
    PostfixEvaluator evaluator;
    FileReader filereader;


    string fileName = "../expressions.txt";
    openFile(filereader, fileName);

    cout << "Evaluating expressions file\n"
         << "---------------------------\n";

    // Test the reading of lines of the file until the end of the file
    string expr = filereader.getline();
    while (filereader.isEof())
    {
        cout << expr << " = ";
        try
        {
            double result = evaluator.evaluate(expr);
            cout << result << endl;
        }
        catch (InvalidExpressionException)
        {
            cerr << "ERROR: Invalid expression\n";
        }
        catch (DivisionByZeroException)
        {
            cerr << "ERROR: Division by zero.\n";
        }
        expr = filereader.getline();
    }

    return 0;
}

/** Opens a file
@post   The FileReader object will have an open file
@param  reader A reference to the FileReader object
@param  fileName The name of (path to) the file to open*/
bool openFile(FileReader &reader, string fileName)
{
    try
    {
        reader.open(fileName);
        return true;
    }
    catch (FileNotFoundException)
    {
        cerr << "ERROR: File does not exist.\n";
        return false;
    }
}
