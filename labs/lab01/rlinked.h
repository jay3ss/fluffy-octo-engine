#ifndef _R_LINKED_H
#define _R_LINKED_H

// #include "ListInterface.h"
#include "Node.h"

template <class T>
// class LinkedList : public ListInterface<T>
class LinkedList
{
public:
    /** Constructor */
    LinkedList();

    /** Copy constructor */
    LinkedList(const LinkedList<T>& list);

    /** Destructor */
    virtual ~LinkedList();

    /** Removes all entries from the list
    @post The list is empty and the length is 0 */
    void clear();

    /** Gets the entry at the given position in the list
    @pre    1 <= position <= length()
    @post   The desired entry has been returned
    @param  position The position in the list of the desired entry
    @return The entry at the given position */
    T entry(int position) const;

    /** Replaces the entry at the given position in the list
    @pre    1 <= position <= length()
    @post   The entry will be added to the list
    @param  position The position in the list of the desired entry
    @param  newPosition A reference to the replacement entry at the given
    position */
    void entry(int position, const Node<T> *newEntry);

    /** Inserts an entry into this list in descending order by value. An
    insertion before existing entries causes the renumbering of entries that
    follow the new one.
    @post   The entry will be added to the list, the entry will be at the given
            position and the entries following it will be renumbered
    @param  newEntry A pointer to the entry that is to be added to the list
    @return True if the insertion was successful, false otherwise */
    bool insertRecur(const Node<T> *newEntry);

    /** Checks if the list is empty.
    @return True if the list is empty, false otherwise*/
    bool isEmpty() const;

    /** Gets the number of entries in the list
    @return The integer number of entries in the list */
    int length() const;

    /** Removes the entry at a given position from the list. A removal before
    the last entry causes the renumbering of entries that follow the deleted
    one.
    @pre    1 <= position <= length()
    @post   The entry at the given position will be removed and the length will
            be decreased by one
    @param  position The position of the entry to remove
    @return True if the entry was removed, false otherwise */
    bool remove(int position);

    /** Removes the entry at a given position from the list. A removal before
    the last entry causes the renumbering of entries that follow the deleted
    one.
    @pre    1 <= position <= length()
    @post   The entry at the given position will be removed and the length will
            be decreased by one
    @param  position The position of the entry to remove
    @return True if the entry was removed, false otherwise */
    bool remove(const Node<T> *anEntry);

private:
    int numEntries_;    // The number of entries currently in  the list
    Node<T>* head_;     // Pointer to the head node

    Node<T> *getNodeBefore(const Node<T>* node);
};

#include "rlinked.cpp"
#endif // _R_LINKED_H
