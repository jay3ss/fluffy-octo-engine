#include <iostream>
#include "selectionsort.h"

int main()
{
    int n = 5;
    int intArr[] = {29, 10, 14, 37, 13};

    for (int i = 0; i < n; i++)
    {
        std::cout << intArr[i] << ", ";
    }
    std::cout << std::endl;

    selectionsort(intArr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << intArr[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}
