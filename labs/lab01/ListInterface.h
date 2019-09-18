/** Interface for the ADT list */
#ifndef _LIST_INTERFACE_H
#define _LIST_INTERFACE_H

template<class T>
class ListInterface
{
public:
    /** Removes all entries from the list
    @post The list is empty and the length is 0 */
    virtual void clear() = 0;

    /** Gets the entry at the given position in the list
    @pre    1 <= position <= length()
    @post   The desired entry has been returned
    @param  position The position in the list of the desired entry
    @return The entry at the given position */
    virtual T entry(int position) const = 0;

    /** Replaces the entry at the given position in the list
    @pre    1 <= position <= length()
    @post   The entry will be added to the list
    @param  position The position in the list of the desired entry
    @param  newPosition A reference to the replacement entry at the given
    position */
    virtual void entry(int position, T* newEntry) = 0;

    /** Inserts an entry into this list in descending order by value. An
    insertion before existing entries causes the renumbering of entries that
    follow the new one.
    @post   The entry will be added to the list, the entry will be at the given
    position and the entries following it will be renumbered
    @param  newPosition A reference to the entry that is to be added to the
            list
    @return True if the insertion was successful, false otherwise */
    virtual bool insert(T* newEntry) = 0;

    /** Checks if the list is empty.
    @return True if the list is empty, false otherwise*/
    virtual bool isEmpty() const = 0;

    /** Gets the number of entries in the list
    @return The integer number of entries in the list */
    virtual int length() const = 0;

    /** Removes the entry at a given position from the list. A removal before
    the last entry causes the renumbering of entries that follow the deleted
    one.
    @pre    1 <= position <= length()
    @post   The entry at the given position will be removed and the length will
            be decreased by one
    @param  position The position of the entry to remove
    @return True if the entry was removed, false otherwise */
    virtual bool remove(int position) = 0;
};

#endif // _LIST_INTERFACE_H
