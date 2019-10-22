#include "LinkedList.h"

/** Constructor */
template <class T>
LinkedList<T>::LinkedList() : topPtr_(nullptr), numEntries_(0)
{

}

/** Copy constructor */
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    // We only need to do something if the list isn't empty
    if (!list.isEmpty())
    {
        T entry;
        // Take the elements from the list and add them to this one
        for (int position = 1; position <= list.length(); position++)
        {
            entry = list.entry(1);
            insert(position, entry);
        }
    }
}

/** Destructor */
template <class T>
LinkedList<T>::~LinkedList()
{
    // Free up all allocated memory by clearing the list
    clear();
}

/** Sees if the list is empty */
template<class T>
bool LinkedList<T>::isEmpty() const
{
    return numEntries_ == 0;
}

/** Get the number of entries in the list. */
template<class T>
int LinkedList<T>::length() const
{
    return numEntries_;
}

/** Insert an entry at a given position in the list. */
template<class T>
bool LinkedList<T>::insert(int position, const T &newEntry)
{
    // Enforce the precondition that 1 <= position <= length() + 1
    bool canInsert = ((1 <= position) && (position <= length() + 1));
    if (canInsert)
    {
        // Create a new Node with the entry
        Node<T>* newNodePtr = new Node<T>(newEntry, nullptr);

        if (position == 1)
        {
            // Insert at the beginning of the list
            newNodePtr->next(topPtr_);
            topPtr_ = newNodePtr;
        }
        else
        {
            // Get the previous node and set our new node's next pointer to the
            // node that the previous node points to
            Node<T>* prevNodePtr = getNodeAt(position - 1);
            newNodePtr->next(prevNodePtr->next());
            prevNodePtr->next(newNodePtr);
        }
        numEntries_++;
    }
    return canInsert;
}

/** Remove the entry at a given position. */
template<class T>
bool LinkedList<T>::remove(int position)
{
    bool canRemove = ((1 <= position) && (position <= length()));
    if (canRemove)
    {
        Node<T> *nodeToDeletePtr = nullptr;
        if (position == 1)
        {
            nodeToDeletePtr = topPtr_;
            topPtr_ = topPtr_->next();

        }
        else
        {
            // Get the node before the one that we want to delete
            Node<T> *prevNodePtr = getNodeAt(position - 1);

            // Now get the node that want to delete so that we know what it
            // points to and use it
            nodeToDeletePtr = prevNodePtr->next();
            prevNodePtr->next(nodeToDeletePtr->next());
        }
        // Return the old node used to pointer back to the system
        nodeToDeletePtr->next(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        numEntries_--;
    }
    return canRemove;
}

/** Remove all entries from the list. */
template<class T>
void LinkedList<T>::clear()
{
    // Keep removing the first entry until the list is empty
    while(!isEmpty())
    {
        remove(1);
    }
}

/** Get the entry at a given position. */
template<class T>
T LinkedList<T>::entry(int position) const
{
    if (isEmpty())
    {
        throw EmptyList();
    }
    Node<T>* nodePtr = getNodeAt(position);
    return nodePtr->item();
}

/** Replace the entry at the given position. */
template<class T>
void LinkedList<T>::replace(int position, const T &newEntry)
{
    if (isEmpty())
    {
        throw EmptyList();
    }
    Node<T>* node = getNodeAt(position);
    node->item(newEntry);
}

/** Sorts the entries in the list in ascending order */
template<class T>
void LinkedList<T>::sort()
{
    // Create a copy of this list
    LinkedList<std::string> copyList = *this;

    for (int i = 1; i <= numEntries_; i++)
    {
        copyList.insert(i, entry(i));
    }

    // Every entry in the list is assumed to be the same size
    // So, just use the size of the first entry
    const int length = entry(1).length();
    const int numLetters = 26;

    // Compare the strings from right to left
    for (int j = length - 1; j >= 0; j--)
    {
        // Initalize a list with 26 groups (letters)
        LinkedList<std::string> groups[numLetters];

        // Go through each entry in the list and place them into
        // the appropriate group
        for (int i = 1; i <= numEntries_; i++)
        {
            std::string item = copyList.entry(i);
            char letter = item[j];
            int group = static_cast<int>(letter - 'a') % numLetters;

            // Place the item into the end of the group
            int endOfGroup = groups[group].length() + 1;
            groups[group].insert(endOfGroup, item);
        }

        // Place the list entries (items) into the copy list at the appropriate
        // location
        int count = 1;
        for (int i = 0; (i < numLetters) && (count <= numEntries_); i++)
        {
            while(!groups[i].isEmpty())
            {
                std::string item = groups[i].entry(1);
                copyList.replace(count, item);
                groups[i].remove(1);
                count++;
            }
        }
    }

    // Copy the replace this list's entries with the now sorted list's entries
    for (int i = 1; i <= numEntries_; i++)
    {
        replace(i, copyList.entry(i));
    }
}

template <class friendT>
std::ostream &operator<<(std::ostream &strm, const LinkedList<friendT> &obj)
{
    // Enter the elements to the osftream object (strm) so that the set will be
    // printed in the following format:
    // {elem1, elem2, ..., elemN}
    // where each elemI is an element in the elements array
    strm << "{";
    const int listLength = obj.length();
    for (int i = 1; i < listLength; i++)
    {
        strm << obj.entry(i) << ", ";
    }
    strm << obj.entry(listLength);

    // Add the closing '}'
    strm << "}";
    return strm;
}

/** Gets the pointer to a node at a desired position */
template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
    Node<T>* nodePtr = topPtr_;

    // Traverse the list until we arrive at the proper position
    for (int count = 1; count < position; count++)
    {
        nodePtr = nodePtr->next();
    }
    return nodePtr;
}
