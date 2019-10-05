#include <iostream>
#include <string>
#include <vector>

#include "LinkedStack.h"
#include "PostfixEvaluator.h"

std::vector<std::string> tokenize(std::string expression);
double evalOperation(double op1, double op2, char operand);

using namespace std;

int main()
{
    LinkedStack<double> ls;
    PostfixEvaluator evaluator;

    // string expr = "1 2 +";
    // string expr = "2 3 + 7 *";
    // string expr = "2 3 4 + *";
    string expr = "5 3 2 * + 4 - 5 +";
    // string expr = "6 3 + 2 *";

    double result = evaluator.evaluate(expr);
    cout << "Result is " << result << endl;

    // string str = "1 2 +";

    // vector<string> tokens = tokenize(str);

    // for (auto token : tokens)
    // {
    //     cout << token << endl;
    // }

    // double result1 = evalOperation(2, 3, '+');
    // double result2 = evalOperation(2, 3, '-');
    // double result3 = evalOperation(2, 3, '*');
    // double result4 = evalOperation(2, 3, '/');


    // cout << "evalOperation(2, 3, '+'): " << result1 << endl;
    // cout << "evalOperation(2, 3, '-'): " << result2 << endl;
    // cout << "evalOperation(2, 3, '*'): " << result3 << endl;
    // cout << "evalOperation(2, 3, '/'): " << result4 << endl;

    // try
    // {
    //     double badExpr = evalOperation(1, 0, '/');
    //     cout << "evalOperation(1, 0, '/'): " << badExpr << endl;

    // }
    // catch(DivisionByZeroException e)
    // {
    //     cerr << "Division by zero" << endl;

    // }

    // try
    // {
    //     double anotherBadExpr = evalOperation(1, 0, ' ');
    //     cout << "evalOperation(1, 0, '/'): " << anotherBadExpr << endl;
    // }
    // catch (InvalidExpressionException e)
    // {
    //     cerr << "Invalid expression" << endl;
    // }

    return 0;
}

std::vector<std::string> tokenize(std::string expression)
{
    std::vector<std::string> tokens;
    char delimiter = ' ';
    std::istringstream iss(expression);

    while (!iss.eof())
    {
        std::string token;
        std::getline(iss, token, delimiter);
        tokens.push_back(token);
    }

    return tokens;
}

/** Evaluates a single postfix operation */
double evalOperation(double op1, double op2, char operand)
{
    double result;
    switch (operand)
    {
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        if (op2 == 0) throw DivisionByZeroException();
        result = op1 / op2;
        break;
    default:
        throw InvalidExpressionException();
        break;
    }

    return result;
}
