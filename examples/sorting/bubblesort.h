#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

template<class T>
void bubblesortnaive(T theArray[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (theArray[i] < theArray[j])
            {
                T elem = theArray[j];
                theArray[j] = theArray[i];
                theArray[i] = elem;
            }
        }
    }
}

template<class T>
void bubblesortsmart(T theArray[], int n)
{
    int pass = 1;
    bool sorted = false;    // Set to false during a swap

    while (!sorted && (pass < n))
    {
        sorted = true;      // Assume sorted

        // Keep sorting the array. As the largest values bubble up towards
        // the top (end) of the array, decrease the last position that
        // we examine until there's nothing left
        for (int index = 0; index < n - pass; index++)
        {
            int nextIndex = index + 1;
            if (theArray[nextIndex] < theArray[index])
            {
                T elem = theArray[nextIndex];
                theArray[nextIndex] = theArray[index];
                theArray[index] = elem;
                sorted = false; // Swap occured, array was not sorted
            }
        }

        pass++;
    }
}

#endif // _BUBBLE_SORT_H
