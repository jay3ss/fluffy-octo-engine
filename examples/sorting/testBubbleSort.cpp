#include <iostream>
#include "bubblesort.h"

int main()
{
    int n = 5;
    int intArr1[] = {29, 10, 14, 37, 13};

    for (int i = 0; i < n; i++)
    {
        std::cout << intArr1[i] << ", ";
    }
    std::cout << std::endl;

    bubblesortnaive(intArr1, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << intArr1[i] << ", ";
    }
    std::cout << std::endl;

    int intArr2[] = {29, 10, 14, 37, 13};

    for (int i = 0; i < n; i++)
    {
        std::cout << intArr2[i] << ", ";
    }
    std::cout << std::endl;

    bubblesortsmart(intArr2, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << intArr2[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}
