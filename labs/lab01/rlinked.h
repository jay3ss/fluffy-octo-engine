#ifndef _R_LINKED_H
#define _R_LINKED_H

#include "ListInterface.h"

// Node struct
template <typename T>
struct Node
{
    Node(T d) : data(d), next(nullptr) {}
    T data;
    Node *next;
};

template <class T>
class LinkedList : public ListInterface<T>
// class LinkedList
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
    void entry(int position, const T &newEntry);

    /** Inserts an entry into this list in descending order by value. An
    insertion before existing entries causes the renumbering of entries that
    follow the new one.
    @post   The entry will be added to the list, the entry will be at the given
            position and the entries following it will be renumbered
    @param  newEntry A pointer to the entry that is to be added to the list
    @return True if the insertion was successful, false otherwise */
    bool insert(const T &newEntry);

    /** Inserts an entry into this list (using recursion) in descending order
    by value. An insertion before existing entries causes the renumbering of
    entries that follow the new one.
    @post   The entry will be added to the list, the entry will be at the given
    position and the entries following it will be renumbered
    @param  subChainPtr The head pointer
    @param  newPosition A reference to the entry that is to be added to the
            list
    @return The head pointer */
    Node<T> *insertRecur(Node<T>* &subChainPtr, const T &newEntry);

    /** Checks if the list is empty.
    @return True if the list is empty, false otherwise*/
    bool isEmpty() const;

    /** Gets the number of entries in the list
    @return The integer number of entries in the list */
    int length() const;

    /** Removes the entry at a given position from this list. A removal before the last entry
    causes the renumbering of entries that follow the deleted
    one.
    @post If 1 <= position <= getLength() and the removal is successful, the
    entry at the given position in the list is removed, other items are
    renumbered accordingly, and the returned value is true.
    @param position The list position of the entry to remove.
    @return True if the entry was removed, false otherwise */
    bool remove(int position);

    Node<T> *head; // Pointer to the head node

private:
    int numEntries_;    // The number of entries currently in  the list

    /** Allocates memory for a new Node
    @post   Memory will be allocated for a new Node. This memory must be
    unallocated when finished with the Node
    @param  data The data that the Node will hold
    @return A pointer to the newly allocated memory for the Node */
    Node<T> *newNode(T data);

    /** Frees up previously allocated memory for a Node
    @pre    Must have previously allocated memory for a Node
    @post   The Node will be deleted
    @param  node Reference to a pointer to a Node */
    void deleteNode(Node<T> *&node);

    /** Locates a specified node in the list
    @pre    1 <= position <= length()
    @post   The Node is found and a pointer to it is retruned
    @param  position The position of the Node to find
    @return A pointer to the Node at the given position*/
    Node<T>* nodeAt(int position) const;
};

// Exception class
class PreconditionViolatedExcep
{
};

#include "rlinked.cpp"
#endif // _R_LINKED_H
