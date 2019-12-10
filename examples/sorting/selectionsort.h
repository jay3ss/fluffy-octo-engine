#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H

template <class T>
int findIndexOfLargest(T theArray, int n)
{
    int indexOfLargest = 0;

    for (int i = 1; i < n; i++)
    {
        if (theArray[indexOfLargest] < theArray[i])
        {
            indexOfLargest = i;
        }
    }

    return indexOfLargest;
}

template <class T>
void selectionsort(T theArray[], int n)
{
    for (int last = n - 1; last >= 1; last--)
    {
        int indexOfLargest = findIndexOfLargest(theArray, last+1);
        T elem = theArray[last];
        theArray[last] = theArray[indexOfLargest];
        theArray[indexOfLargest] = elem;
    }
}

#endif // _SELECTION_SORT_H
