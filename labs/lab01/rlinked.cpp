#include "rlinked.h"

/** Constructor */
template<class T>
LinkedList<T>::LinkedList()
{

}

/** Copy constructor */
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{

}

template<class T>
LinkedList<T>::~LinkedList()
{

}

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
void LinkedList<T>::entry(int position, const T* newEntry)
{

}

/** Inserts an entry into this list in descending order by value. An
    insertion before existing entries causes the renumbering of entries that
    follow the new one. */
template<class T>
bool LinkedList<T>::insert(const T *newEntry)
{
    return false;
}

/** Checks if the list is empty. */
template<class T>
bool LinkedList<T>::isEmpty() const
{
    return false;
}

/** Gets the number of entries in the list */
template<class T>
int LinkedList<T>::length() const
{
    return -1;
}

/** Removes the entry at a given position from the list. A removal before
    the last entry causes the renumbering of entries that follow the deleted
    one. */
template<class T>
bool LinkedList<T>::remove(int position)
{
    return false;
}

/** Inserts an entry into this list (using recursion) in descending order by
value. An insertion before existing entries causes the renumbering of entries
that follow the new one. */
template<class T>
bool LinkedList<T>::insertRecur(const T *newEntry)
{
    return false;
}
