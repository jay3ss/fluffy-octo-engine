#ifndef _POSTFIX_EVAL_H
#define _POSTFIX_EVAL_H

#include <sstream>
#include <string>
#include <vector>

#include "LinkedStack.h"

class PostfixEvaluator
{
public:
    /** Default constructor */
    PostfixEvaluator();

    /** Destructor */
    ~PostfixEvaluator();
    // void evaluate();

    /** Evaluates a postfix expression and returns the result
    @pre        expression must be a valid postfix expression. E.g., formatted
    as

    operand1 operand2 operand3 operator1 operator2

    or concretely

    2 1 3 + *

    which would return 8. NOTE: DOUBLE CHECK THIS!!!

    spaces between each argument (operators and operands) and no leading or
    trailing white space.
    @param      expression The postfix expression to be evaluated
    @returns    The result of the postfix expression */
    double evaluate(std::string expression);
private:
    bool isOperand(std::string str);
    bool isOperator(std::string str);
    bool isParenthesis(std::string str);

    /** Evaluates a single postfix operation
    @pre    If operand is division ('/'), then op2 cannot equal zero
    @param  op1 First operand*/
    double evalOperation(double op1, double op2, char opertr);

    /** Splits the expression into a vector of tokens (operators and operands)
    and returns the token vector */
    std::vector<std::string> tokenize(std::string expression);
};

// Custom exceptions
class DivisionByZeroException {};
class InvalidExpressionException {};

#endif // _POSTFIX_EVAL_H