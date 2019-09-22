#include <iostream>
#include "rlinked.h"

using namespace std;

int main()
{
    LinkedList<int> intLL;

    cout << "Testing the linked-list:\n"
         << "========================\n\n";

    // 1. Test whether the list is empty
    cout << "1. The initial list is empty\n"
         << "----------------------------\n"
         << "The list should be empty\n"
         << "isEmpty(): returns " << intLL.isEmpty()
         << "; should be 1 (true)\n\n";

    // 2. Get the number of entries in the (empty) list
    cout << "2. Get the number of entries in the (empty) list\n"
         << "------------------------------------------------\n"
         << "The number of entries should be 0\n"
         << "length(): returns " << intLL.length()
         << "; should be 0\n\n";

    // 3. Insert an entry into the list
    int data = 5;

    cout << "3. Insert an entry into the list\n"
         << "--------------------------------\n"
         << "The node should have been inserted\n"
         << "insert(node): returns " << intLL.insert(data)
         << "; should be 1 (true)\n\n";

    // a. Get the number of entries in the (non-empty) list
    cout << "The number of entries should be 1\n"
         << "length(): returns " << intLL.length()
         << "; should be 1\n\n";

    // Add a few entries to the list for the following tests
    for (int i = 0; i < 5; i++)
    {
        data = i;
        intLL.insert(data);
    }

    // 4. Remove a given entry entry from the list
    // NOTE: node.data = 4
    cout << "4. Remove a given entry from the list\n"
         << "-------------------------------------\n"
         << "The node should have been removed\n"
         << "remove(node): returns " << intLL.remove(data)
         << "; should be 1 (true)\n\n";

    // a. Get the number of entries in the list
    cout << "The number of entries should be 5\n"
         << "length(): returns " << intLL.length()
         << "; should be 5\n\n";

    // 5. Remove the entry at a given position from the list
    // We'll remove an arbitrary entry, let's say the third one
    cout << "5. Remove the entry at a given position from the list\n"
         << "-----------------------------------------------------\n"
         << "The node should have been removed\n"
         << "remove(3): returns " << intLL.remove(3)
         << "; should be 1 (true)\n\n";

    // a. Get the number of entries in the list
    cout << "The number of entries should be 3\n"
         << "length(): returns " << intLL.length()
         << "; should be 3\n\n";

    // 6. Get the entry at a given position in the list
    cout << "6. Get the entry at a given position in the list\n"
         << "------------------------------------------------\n"
         << "The entry should have been returned\n"
         << "entry(2): returns " << intLL.entry(2)
         << "; should be 1\n\n";

    // 7. Get the position in the list of a given entry
    cout << "7. Get the entry at a given position in the list\n"
         << "------------------------------------------------\n"
         << "The entry should have been returned\n"
         << "entry(2): returns " << intLL.entry(2)
         << "; should be 1\n\n";

    // 8. Remove all entries from the list
    intLL.clear();
    cout << "8. Remove all entries from the list\n"
         << "-----------------------------------\n"
         << "The list should be empty\n"
         << "isEmpty(): returns " << intLL.isEmpty()
         << "; should be 1 (true)\n\n";

    // a. Get the number of entries in the list
    cout << "The number of entries should be 0\n"
         << "length(): returns " << intLL.length()
         << "; should be 0\n\n";

    // Add a few entries to the list to test the printing of the list
    for (int i = 0; i < 5; i++)
    {
        data = i;
        intLL.insert(data);
    }

    // Print out the entires in the list
    int listLength = intLL.length();
    for (int i = 0; i < listLength; i++)
    {
        cout << "Entry " << (i + 1) << ":\t" << intLL.entry(i) << endl;
    }


    return 0;
}
