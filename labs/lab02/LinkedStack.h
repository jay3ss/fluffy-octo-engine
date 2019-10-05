#ifndef _LINKED_STACK_H
#define _LINKED_STACK_H

#include "StackInterface.h"
#include "Node.h"

template <class T>
class LinkedStack : public StackInterface<T>
{
public:
    // Constructors and destructor:
    /** Default constructor */
    LinkedStack();

    /** Copy constructor */
    LinkedStack(const LinkedStack<T> &aStack);

    /** Destructor */
    virtual ~LinkedStack();

    /** Determines if the stack is empty.
    @return True if the stack is empty, or false if not. */
    bool isEmpty() const;

    /** Adds a new entry to the top of the stack.
    @post If the operation was successful, newEntry is at the top of the stack.
    @param newEntry The object to be added to the top of the stack.
    @return True if the addition is successful, false if not. */
    bool push(const T &newEntry);

    /** Removes the top of this stack.
    @post If the operation was successful, the top of the stack
    has been removed.
    @return True if the removal is successful, false if not. */
    bool pop();

    /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and
    the stack is unchanged.
    @return The top of the stack. */
    T peek() const;

private:
    Node<T> *topPtr; // Pointer to first node in the chain
};

#include "LinkedStack.cpp"
#endif // _LINKED_STACK_H
