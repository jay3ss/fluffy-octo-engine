#include "rlinked.h"

/** Constructor */
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), numEntries_(0) {}

/** Copy constructor */
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
    // We only need to do something if the list isn't empty
    if (!list.isEmpty())
    {
        T entry;
        for (int position = 1; position <= list.length(); position++)
        {
            entry = list.entry(position);
            insert(position, entry);
        }
    }
}

/** Destructor */
template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

/** Removes all entries from the list */
template<class T>
void LinkedList<T>::clear()
{
    // T anEntry = entry(1);
    while (!isEmpty())
    {
        remove(1);
        // if (!isEmpty())
        // {
        //     anEntry = entry(1);
        // }
    }
}

/** Gets the entry at the given position in the list */
template <class T>
T LinkedList<T>::entry(int position) const
{
    // NOTE: this needs to raise an error if not 1 <= position <= length
    Node<T>* tempNodePtr = head;
    if (1 <= position && position <= length())
    {
        int entryNum = 1;
        while (tempNodePtr != nullptr && entryNum < position)
        {
            tempNodePtr = tempNodePtr->next;
            entryNum++;
        }
        return tempNodePtr->data;
    }
    else
    {
        throw PreconditionViolatedExcep();
    }
}

/** Replaces the entry at the given position in the list */
template <class T>
void LinkedList<T>::entry(int position, const T &newEntry)
{
    Node<T>* nodePtr = nodeAt(position);
    nodePtr->data = newEntry;
}

/** Inserts an entry into this list in descending order by value. An
insertion before existing entries causes the renumbering of entries that follow
the new one. */
template<class T>
bool LinkedList<T>::insert(const T &newEntry)
{
    head = insertRecur(head, newEntry);

    return true;
}

/** Checks if the list is empty. */
template<class T>
bool LinkedList<T>::isEmpty() const
{
    return numEntries_ == 0;
}

/** Gets the number of entries in the list */
template<class T>
int LinkedList<T>::length() const
{
    return numEntries_;
}

/** Removes the entry at a given position from this list. A removal before the
last entry causes the renumbering of entries that follow the deleted */
template <class T>
bool LinkedList<T>::remove(int position)
{
    // If the list is empty, there's nothing to remove
    if (isEmpty())
    {
        return false;
    }

    // Enforce the precondition of 1 <= position <= length()
    bool canRemove = (1 <= position) && (position <= length());

    if (canRemove)
    {
        Node<T> *currNodePtr = nullptr;
        if (position == 1)
        {
            currNodePtr = head;
            head = head->next;
        }
        else
        {
            Node<T> *prevNodePtr = nodeAt(position - 1);

            currNodePtr = prevNodePtr->next;
            prevNodePtr->next = currNodePtr->next;

        }

        currNodePtr->next = nullptr;
        deleteNode(currNodePtr);
        numEntries_--;
    }
    else
    {
        throw PreconditionViolatedExcep();
    }

    // The entry was not found, so return false
    return canRemove;
}

/** Inserts an entry into this list (using recursion) in FIFO order by. */
template <class T>
Node<T> *LinkedList<T>::insertRecur(Node<T>* &subChainPtr, const T &newEntry)
{
    if (isEmpty())
    {
        // The list is empty, so insert at the head pointer
        subChainPtr = newNode(newEntry);
        head = subChainPtr;
        numEntries_++;
    }
    else if (subChainPtr == nullptr)
    {
        // We've traversed the chain and now we're at the end
        numEntries_++;
        return newNode(newEntry);
    }
    else
    {
        // Still in the middle of the chain so keep going down
        subChainPtr->next = insertRecur(subChainPtr->next, newEntry);
    }

    return subChainPtr;
}

/** Allocates memory for a new Node */
template<class T>
Node<T>* LinkedList<T>::newNode(T data)
{
    Node<T>* newNodePtr = new Node<T>(data);
    return newNodePtr;
}

/** Frees up previously allocated memory for a Node */
template<class T>
void LinkedList<T>::deleteNode(Node<T>* &node)
{
    delete node;
    node = nullptr;
}

/** Locates a specified node in the list */
template<class T>
Node<T>* LinkedList<T>::nodeAt(int position) const
{
    Node<T>* nodePtr = head;

    for (int count = 1; count < position; count++)
    {
        nodePtr = nodePtr->next;
    }

    return nodePtr;
}
