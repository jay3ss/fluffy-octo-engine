#ifndef _STACK_INTERFACE_H
#define _STACK_INTERFACE_H

template <class T>
class StackInterface
{
public:
    /** Determines if the stack is empty.
    @return True if the stack is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the top of the stack.
    @post If the operation was successful, newEntry is at the top of the stack.
    @param newEntry The object to be added to the top of the stack.
    @return True if the addition is successful, false if not. */
    virtual bool push(const T &newEntry) = 0;

    /** Removes the top of this stack.
    @post If the operation was successful, the top of the stack
    has been removed.
    @return True if the removal is successful, false if not. */
    virtual bool pop() = 0;

    /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and
    the stack is unchanged.
    @return The top of the stack. */
    virtual T peek() const = 0;
};

#endif // _STACK_INTERFACE_H
