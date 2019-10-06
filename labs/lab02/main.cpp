#include <iostream>
#include <string>
#include <vector>

#include "FileReader.h"
#include "PostfixEvaluator.h"

using namespace std;

int main()
{
    PostfixEvaluator evaluator;

    // string expr = "1 2 +";
    // string expr = "2 3 + 7 *";
    // string expr = "2 3 4 + *";
    // string expr = "5 3 2 * + 4 - 5 +";
    // string expr = "6 3 + 2 *";
    string expr = "2 1 3 + *";

    double result = evaluator.evaluate(expr);
    cout << "Result is " << result << endl;

    cout << "Testing the FileReader class\n";

    cout << "Going to pen a non-existent file\n";

    FileReader filereader;

    try
    {
        filereader.open("dne.txt");
    }
    catch (FileNotFoundException)
    {
        cerr << "ERROR: File does not exist.\n\n";
    }

    cout << "Going to open an existent file\n";

    try
    {
        filereader.open("../expressions.txt");
    }
    catch (FileNotFoundException)
    {
        cerr << "ERROR: File does not exist.\n";
    }

    // Test the reading of lines of the file until the end of the file
    expr = filereader.getline();
    while (filereader.isEof())
    {
        result = evaluator.evaluate(expr);
        cout << expr << " = " << result << endl;
        expr = filereader.getline();
    }

    return 0;
}
