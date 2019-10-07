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
    double result;

    for (auto token: tokens)
    {
        // Every token is either an operator or an operand
        if (!isOperator(token))
        {
            double op = convertToOperand(token);
            operands.push(op);
        }
        else
        {
            // Get the two operands off of the stack
            double op2 = operands.peek();
            operands.pop();
            double op1 = operands.peek();
            operands.pop();

            // Get the operator token and convert it to a char
            char opertr = static_cast<char>(token[0]);

            result = evalOperation(op1, op2, opertr);

            // Store the result back on the stack
            operands.push(result);
        }
    }

    return result;
}

double PostfixEvaluator::convertToOperand(std::string token)
{
    try
    {
        return std::stod(token);
    }
    catch (std::invalid_argument)
    {
        throw InvalidExpressionException();
    }
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

/** Determines if a token is an operand */
bool PostfixEvaluator::isOperator(std::string token)
{
    return (token == "+") || (token == "-") || (token == "*") || (token == "/");
}
