#include <iostream>
#include <string>

#include "PostfixEvaluator.h"

using namespace std;

// Prototypes
/** Evaluates a postfix expression */
double evaluateExpression(PostfixEvaluator &evaluator, string expr);

int main()
{
    PostfixEvaluator evaluator;

    cout << "+------------------------------------+\n"
         << "| Testing the PostfixEvaluator class |\n"
         << "+------------------------------------+\n\n";

    string expr = "2 1 3 + *";
    cout << "Test evaluating a correctly formed postfix expression\n"
         << "-----------------------------------------------------\n"
         << "evaluate(" << expr << "): returns " << evaluateExpression(evaluator, expr)
         << "; should return 8\n\n";

    expr = " 2 1 3 + *";
    cout << "Test evaluating incorrectly formed postfix expressions\n"
         << "------------------------------------------------------\n"
         << "a. Expression with a leading space\n"
         << "evaluate(" << expr << ") should throw an error. Results in\n";
    evaluateExpression(evaluator, expr);
    cout << endl;

    expr = "2  1 3 + *";
    cout << "b. Expression with an extra space within the expression\n"
         << "evaluate(" << expr << ") should throw an error. Results in\n";
    evaluateExpression(evaluator, expr);
    cout << endl;

    expr = "2 1 3 + * ";
    cout << "c. Expression with a trailing space\n"
         << "evaluate(" << expr << ") should throw an error. Results in\n";
    evaluateExpression(evaluator, expr);
    cout << endl;

    expr = "1 0 /";
    cout << "d. Expression that includes division zero\n"
         << "evaluate(" << expr << ") should throw an error. Results in\n";
    evaluateExpression(evaluator, expr);
    cout << endl;

    return 0;
}

/** Evaluates a postfix expression
@param evaluator The postfix expression evaluator reference
@param expr A string containing the postfix expression
@returns The result of the postfix expression*/
double evaluateExpression(PostfixEvaluator &evaluator, string expr)
{
    try
    {
        return evaluator.evaluate(expr);
    }
    catch (InvalidExpressionException)
    {
        cerr << "ERROR: Invalid expression\n";
    }
    catch (DivisionByZeroException)
    {
        cerr << "ERROR: Division by zero.\n";
    }
}
