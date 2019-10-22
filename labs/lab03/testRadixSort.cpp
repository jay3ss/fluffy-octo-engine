#include <iostream>

#include "LinkedList.h"
#include "radixsort.h"

using namespace std;

int main()
{
    const int numElems = 10;
    string strArray[] = {
        // "abc", "xyz", "bwz", "aac", "rlt", "jbx", "aaa"
        "abc", "xyz", "bwz", "aac", "rlt", "jbx", "rdt", "klt", "aeo", "tlj"
    };

    // const int numElems = 3;
    // string strArray[] = {"abc", "aac", "aaa"};

    LinkedList<string> stringList;

    for (int i = 0; i < numElems; i++)
    {
        stringList.insert(i+1, strArray[i]);
    }

    cout << "State of the list before sorting:\n";
    cout << stringList << "\n\n";

    stringList.sort();

    cout << "State of the list after sorting:\n";
    cout << stringList << endl;

    return 0;
}
