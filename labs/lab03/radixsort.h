#ifndef _RADIX_SORT_H
#define _RADIX_SORT_H

#include <cmath>
#include <list>
#include <string>

using namespace std;

template <class T>
void radixsortint(T theArray[], int n, int d, int radix = 10);
void radixsortstr(string theArray[], int n, int d);

#include "radixsort.cpp"
#endif // _RADIX_SORT_H
