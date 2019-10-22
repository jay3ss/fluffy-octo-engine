#include "radixsort.h"

template<class T>
void radixsortint(T theArray[], int n, int d, int radix)
{
    T tempArray[n];

    // Copy the array for debugging purposes
    for (int i = 0; i < n; i++)
    {tempArray[i] = theArray[i];}

    for (int j = d; j > 0; j--)
    {
        // Initialize 10 groups to empty
        // Initialize a counter for each group to 0
        list<T> groups[radix];
        int counters[radix] = {};

        int exponent = d - j + 1;
        int div = pow(radix, d - j);
        int modNumber = pow(radix, exponent);
        for (int i = 0; i < n; i++)
        {
            // k = j th digit of theArray[i]
            T k = theArray[i];
            int group = (k % modNumber) / div;
            // Place theArray[i] at the end of group
            groups[group].push_back(k);
            // Increase k th counter by 1
            counters[group]++;
        }

        int count = 0;
        for (int i = 0; i < radix; i++)
        {
            while(!groups[i].empty())
            {
                theArray[count] = groups[i].front();
                tempArray[count] = groups[i].front(); // Debug purposes
                groups[i].pop_front();
                count++;
            }
        }
    }
}

void radixsortstr(string theArray[], int n, int d)
{
    string tempArray[n];
    const int radix = 26; // number of lowercase letters

    // Copy the array for debugging purposes
    for (int i = 0; i < n; i++)
    {
        tempArray[i] = theArray[i];
    }

    for (int j = d - 1; j >= 0; j--)
    {
        // Initialize 26 groups to empty
        // Initialize a counter for each group to 0
        list<string> groups[radix];
        int counters[radix] = {};

        for (int i = 0; i < n; i++)
        {
            // k = j th digit of theArray[i]
            string elem = theArray[i];
            char letter = elem[j];
            int group = (static_cast<int>(letter - 'a')) % radix;
            // Place theArray[i] at the end of group
            groups[group].push_back(elem);
            // Increase k th counter by 1
            counters[group]++;
        }

        int count = 0;
        for (int i = 0; i < radix; i++)
        {
            while (!groups[i].empty())
            {
                theArray[count] = groups[i].front();
                tempArray[count] = groups[i].front(); // Debug purposes
                groups[i].pop_front();
                count++;
            }
        }
    }
}
