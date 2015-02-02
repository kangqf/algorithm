#ifndef SEQUENTIALSEARCH_H
#define SEQUENTIALSEARCH_H

class SequentialSearch
{
public:
    SequentialSearch();
};

//返回下标
template <typename T>
int sequentialSearch(T a[], const T &x, int n)
{
    a[n] = x;
    int i;
    for(i = 0; a[i] != x; ++i)
    {
        ;
    }
    if(i != n)
        return i;
    return -1;
}

#endif // SEQUENTIALSEARCH_H
