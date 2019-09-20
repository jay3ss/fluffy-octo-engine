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

/** Replaces the entry at the given position in the list */
template <class T>
T LinkedList<T>::entry(int position) const
{

}

/** Gets the entry at the given position in the list */
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
    Node<T> *newNodePtr = new Node<T>(newEntry);
    head_ = insertRecur(newNodePtr, head_);

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

/** Inserts an entry into this list (using recursion) in descending order by
value. An insertion before existing entries causes the renumbering of entries
that follow the new one. */
template <class T>
Node<T> *LinkedList<T>::insertRecur(Node<T> *newNodePtr, Node<T> *subChainPtr)
{
    if (subChainPtr == nullptr)
    {
        subChainPtr = newNodePtr;
    }
    else if (subChainPtr->data < newNodePtr->data)
    {
        subChainPtr = insertRecur(newNodePtr, subChainPtr->next);
    }
    else
    {
        // Node<T> *oldNodeNextPtr = subChainPtr->next;
        newNodePtr->next = subChainPtr->next;
        subChainPtr->next = newNodePtr;
    }

    numEntries_++;
    return subChainPtr;
}
