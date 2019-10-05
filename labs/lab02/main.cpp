#include <iostream>
#include <string>
#include <vector>

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

    return 0;
}
