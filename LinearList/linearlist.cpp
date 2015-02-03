#include "linearlist.h"
#include "except.h"

#include <ostream>

template <typename T>
LinearList<T>::LinearList(int maxListSize)
{
    maxSize = maxListSize;
    element = new T[maxSize];
    length = 0;
}

template <typename T>
bool LinearList<T>::Find(int k, T &x) const
{
    if(k < 1 || k > length)
    {
        return false;
    }
    else
    {
        x = element[k-1];
        return true;
    }
}

template <typename T>
bool LinearList<T>::Search(const T &x) const
{
    for(int i = 0; i < length; ++i)
    {
        if(element[i] == x)
        {
            return ++i;
        }
    }
    return false;

}

template <typename T>
LinearList<T> &LinearList<T>::Delete(int k, T &x)
{
    if(Find(k,x))
    {
        for(int i = k; i < length; ++i)
        {
            element[k-1] = element[k];
        }
        --length;
        return *this;
    }
    else
    {
        throw OutOfBounds();
    }

}

template <typename T>
LinearList<T> &LinearList<T>::Insert(int k, const T &x)
{
    if(k < 1 || k > length)
    {
        throw OutOfBounds();
    }
    if(maxSize == length)
    {
        throw NoMem();
    }
    for(int i = length; i > k-1; --i)
    {
        element[i] = element[i-1];
    }
    element[k-1] = x;
    ++length;
    return *this;

}

template <typename T>
void LinearList<T>::Output(ostream &out) const
{
    for(int i =0; i < length; ++i)
    {
        out<<element[i]<<" ";
    }
}

// 重载 << 运算符
template <class T>
ostream& operator <<(ostream& out, const LinearList<T>& x)
{
    x.Output(out);
    return out;
}
