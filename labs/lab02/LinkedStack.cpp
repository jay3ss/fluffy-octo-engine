#include <cassert>
#include "LinkedStack.h"

/** Constructor */
template <class T>
LinkedStack<T>::LinkedStack() : topPtr(nullptr)
{
}

/** Copy constructor */
template <class T>
LinkedStack<T>::
    LinkedStack(const LinkedStack<T> &aStack)
{
    // Point to nodes in original chain
    Node<T> *origChainPtr = aStack->topPtr;
    if (origChainPtr == nullptr)
        topPtr = nullptr; // Original bag is empty
    else
    {
        // Copy first node
        topPtr = new Node<T>();
        topPtr->setEntry(origChainPtr->getEntry());

        // Point to first node in new chain
        Node<T> *newChainPtr = topPtr;

        // Copy remaining nodes
        while (origChainPtr != nullptr)
        {
            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();

            // Get next entry from original chain
            T nextEntry = origChainPtr->getEntry();

            // Create a new node containing the next entry
            Node<T> *newNodePtr = new Node<T>(nextEntry);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

/** Destructor */
template <class T>
LinkedStack<T>::~LinkedStack()
{
    // Keep popping until stack is empty
    while (!isEmpty())
        pop();
}

/** Determines if the stack is empty. */
template <class T>
bool LinkedStack<T>::isEmpty() const
{
    return topPtr == nullptr;
}

/** Adds a new entry to the top of the stack. */
template <class T>
bool LinkedStack<T>::push(const T &newEntry)
{
    Node<T> *newNodePtr = new Node<T>(newEntry, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

/** Removes the top of this stack. */
template <class T>
bool LinkedStack<T>::pop()
{
    bool result = !isEmpty();
    if (result)
    {
        // Stack is not empty
        Node<T> *nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();

        // Return deleted node to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
    }
    return result;
}

/** Returns the top of this stack. */
template <class T>
T LinkedStack<T>::peek() const
{
    assert(!isEmpty()); // Enforce precondition

    return topPtr->getEntry();
}
