#include "PostfixEvaluator.h"

/** Default constructor */
PostfixEvaluator::PostfixEvaluator() {}

/** Destructor */
PostfixEvaluator::~PostfixEvaluator() {}

/** Evaluates a postfix expression */
double PostfixEvaluator::evaluate(std::string expression)
{
    LinkedStack<double> operands;

    std::vector<std::string> tokens = tokenize(expression);
    double op1 = std::stod(tokens[0]);
    double op2 = std::stod(tokens[1]);
    char opertr = tokens[2][0];
    double result = evalOperation(op1, op2, opertr);

    return result;
}

/** Evaluates a single postfix operation */
double PostfixEvaluator::evalOperation(double op1, double op2, char opertr)
{
    double result;
    switch (opertr)
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

/** Tokenizes the given expression by splitting the string at spaces
From http://www.cplusplus.com/faq/sequences/strings/split/#getline
Accessed on 10/4/2019 */
std::vector<std::string> PostfixEvaluator::tokenize(std::string expression)
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
