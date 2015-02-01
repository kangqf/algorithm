#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

class InsertionSort
{
public:
    InsertionSort();
};

template <typename T>
void insertionSort(T a[], int n)
{
    for(int i = 1; i < n; ++i)
    {
        int t = a[i];
        int j;
        for(j = i-1; j >= 0 && a[j] > t; --j)
        {
            a[j+1] = a[j];
        }
        a[j+1] = t;
    }
}

#endif // INSERTIONSORT_H
