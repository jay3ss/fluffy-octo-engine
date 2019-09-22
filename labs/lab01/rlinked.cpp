#include "rlinked.h"

/** Constructor */
template<class T>
LinkedList<T>::LinkedList()
{
    numEntries_ = 0;
    head_ = nullptr;
}

/** Copy constructor */
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{

}

/** Destructor */
template<class T>
LinkedList<T>::~LinkedList()
{

}

/** Removes all entries from the list */
template<class T>
void LinkedList<T>::clear()
{

}

/** Gets the entry at the given position in the list */
template <class T>
T LinkedList<T>::entry(int position) const
{
    // NOTE: this needs to raise an error if not 1 <= position <= length
    Node<T>* tempNodePtr = head_;
    if (1 <= position && position <= length())
    {
        int entryNum = 1;
        while (tempNodePtr != nullptr && entryNum < position)
        {
            tempNodePtr = tempNodePtr->next;
            entryNum++;
        }
    }

    return tempNodePtr->data;
}

/** Replaces the entry at the given position in the list */
template<class T>
void LinkedList<T>::entry(int position, const T &newEntry)
{

}

/** Inserts an entry into this list in descending order by value. An
insertion before existing entries causes the renumbering of entries that follow
the new one. */
template<class T>
bool LinkedList<T>::insert(const T &newEntry)
{
    head_ = insertRecur(head_, newEntry);

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

/** Removes the entry at a given position from the list. A removal before
the last entry causes the renumbering of entries that follow the deleted one */
// template <class T>
// bool LinkedList<T>::remove(int position)
// {
//     return false;
// }

/** Removes the entry at a given position from the list. A removal before
the last entry causes the renumbering of entries that follow the deleted one */
template <class T>
bool LinkedList<T>::remove(const T &anEntry)
{
    return false;
}

/** Inserts an entry into this list (using recursion) in FIFO order by. */
template <class T>
Node<T> *LinkedList<T>::insertRecur(Node<T> *subChainPtr, const T &newEntry)
{
    // The list is empty, or we've reached the end of the chain
    if (subChainPtr == nullptr)
    {
        subChainPtr = newNode(newEntry);
        numEntries_++;
    }
    // Keep going down the chain
    else
    {
        Node<T>* nodePtr = insertRecur(subChainPtr->next, newEntry);
        subChainPtr->next = nodePtr;
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
