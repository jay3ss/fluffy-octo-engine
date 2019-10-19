#include "LinkedList.h" // assuming the linked list is implemented accord to specs in the book
#include "Node.h"       // assuming the node is implemented accord to specs in the book

void removeVowels(Node<char>* headPtr)
{
    Node<char> *prevPtr = nullptr;
    int position = 1;

    while(headPtr != nullptr)
    {
        char ch = headPtr->getEntry();

        // if the character is a vowel, delete it
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            if (position == 1)
            {
                prevPtr = headPtr;
                headPtr = headPtr->getNext();

                prevPtr->setNext(nullptr);
                delete prevPtr;
                prevPtr = nullptr;
            }
        }
        else
        {
            prevPtr = headPtr;
            headPtr = headPtr->getNext();
        }

        position++;
    }
}

int main()
{
    return 0;
}
