#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Functions.h"

class BubbleSort
{
public:
    BubbleSort();
};

template <typename T>
bool bubble(T a[], int n)
{
    bool sorted = true;//表示是否已经排序完成rrrr
    for(int i = 0; i < n; ++i)
    {
        if(a[i+1] < a[i])
        {
           Swap(a[i],a[i+1]);
           sorted = false;
        }
    }
    return sorted;
}
template <typename T>
void bubbleSort(T a[], int n)
{
    for(int i =0; i <= n; ++i)
    {
        if(bubble(a,n))
            break;
    }
}

#endif // BUBBLESORT_H
