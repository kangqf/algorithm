#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <iostream>
using std::ostream;

template <typename T>
class LinearList
{
public:
    LinearList(int maxListSize = 10);
    ~LinearList(){ delete []element; }
    bool IsEmpty() const { return length == 0;}
    int Length() const { return length; }
    bool Find(int k, T &x) const ;//在线性表中查找第k个元素，如果存在则返回其值x，否则返回false
    bool Search(const T &x) const;//在线性表中查找是否含有x，如果存在则返回其位置，否则返回FALSE
    LinearList<T>& Delete(int k, T &x);//删除指定位置的某个元素，通过x返回该元素，函数返回修改后的线性表
    LinearList<T>& Insert(int k, const T &x);//在指定位置插入一个元素x后，返回插入后的线性表
    void Output(ostream &out) const;


private:
    T *element;
    int maxSize;
    int length;

};

////////////////////////////////////////////////////////////////////
#include "linearlist.h"
#include "except.h"

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
    if(k < 1 || k > maxSize)
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
ostream& operator<<(ostream &out, const LinearList<T> &x)
{
    x.Output(out);
    return out;
}
////////////////////////////////////////////////////////////////////

#endif // LINEARLIST_H
