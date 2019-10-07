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

    /** Evaluates a postfix expression and returns the result
    @pre        expression must be a valid postfix expression. E.g., formatted
    as

    operand1 operand2 operand3 operator1 operator2

    or concretely

    2 1 3 + * // which would return 8

    with spaces between each argument (operators and operands) and no leading
    or trailing white space. Also, it is assumed that every character is either
    an operator, operand, or a whitespace (the delimiter).
    @param      expression The postfix expression to be evaluated
    @returns    The result of the postfix expression */
    double evaluate(std::string expression);
private:
    /** Determines if a token is an operand: +, -, *, or /
    @param token The token to be checked
    @returns True if the token is an operator, false otherwise */
    bool isOperator(std::string token);

    /** Converts a token to an operand (double)
    @pre        The token should be able to be converted to a double
    @param      token The token to be converted
    @returns    Returns a an operand (as a double) */
    double convertToOperand(std::string token);

    /** Evaluates a single postfix operation
    @pre    If operand is division ('/'), then op2 cannot equal zero
    @param  op1 First operand
    @param  op2 Second operand
    @param opertr The operation that's to be performed
    @returns    The result of the evaluation of the operation */
    double evalOperation(double op1, double op2, char opertr);

    /** Splits the expression into a vector of tokens (operators and operands)
    and returns the token vector
    @pre    expression should be a well-formed postfix expression
    @param  expression The postfix expression
    @returns A vector containing the tokens that are the operands and operators
    of the postfix expression */
    std::vector<std::string> tokenize(std::string expression);
};

// Custom exceptions
class DivisionByZeroException {};
class InvalidExpressionException {};

#endif // _POSTFIX_EVAL_H
