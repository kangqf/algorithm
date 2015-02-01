#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//返回数组大小
template <typename T>
int ArraySize(T a[])
{
    int i;
    for(i = 0; a[i] != "\0"; ++i)
    {
        ;
    }
    return i;
}

//交换俩个元素
template <typename T>
void Swap(T &a , T &b)
{
    T temp = b;
    b = a;
    a = temp;
}

//返回前n个元素中最大元素的位置
template <typename T>
int Max(T a[], int n)
{
    int pos = 0;
    for(int i = 0; i <= n; ++i)
    {
        if(a[pos] < a[i])
        {
            pos = i;
        }
    }
    return pos;
}


#endif // FUNCTIONS_H
