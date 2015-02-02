#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

class BinarySearch
{
public:
    BinarySearch();
};

//只适用于有序数组
template <typename T>
int binarySearch(T a[], const T &x, int n)
{
    int left = 0, right = n-1;
    while(left <= right)
    {
        int middle = (left + right)/2;
        if(a[middle] == x)
            return middle;
        else if(a[middle] > x)
            right = middle;
        else
            left = middle;

    }
    return -1;

}

#endif // BINARYSEARCH_H
