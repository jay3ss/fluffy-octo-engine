#include <iostream>
#include <string>
#include <vector>

#include "FileReader.h"
#include "PostfixEvaluator.h"

using namespace std;

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
        try
        {
            double result = evaluator.evaluate(expr);
            cout << expr << " = " << result << endl;
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
