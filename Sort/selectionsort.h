#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Functions.h"

class SelectionSort
{
public:
    SelectionSort();
};

//对a中的前n个元素进行排序,考虑如何及时终止排序
template <typename T>
void selectionSort(T a[], int n)
{
    for(int size = n; size > 1; --size)
    {
        int max = Max(a,size);
        Swap(a[size],a[max]);
    }
}

#endif // SELECTIONSORT_H
