#ifndef CHAIN_H
#define CHAIN_H

#include <ostream>

template <typename T> class Chain;

using std::ostream;

template <typename T>
class ChainNode
{
    friend Chain<T>;
private:
    T data;
    ChainNode<T> *next;
};


template <typename T>
class Chain
{
public:
    Chain(){ first =0; }
    ~Chain();
    bool isEmpty() const{ return first ==0; }
    int length() const;
    bool find(int k, T &x) const;//通过位置找元素
    int search(const T &x) const;//通过元素找位置
    Chain<T> & insert(int k, const T &x);//插入在第k个元素之后，从0（第0之后就是第一）开始
    Chain<T> & remove(int k, T &x);
    void outPut(ostream &) const;
private:
    ChainNode<T> *first;
};


////////////////////////////////////////////////////////////////////////
#include "chain.h"
#include "except.h"


template <typename T>
Chain<T>::~Chain()
{
    ChainNode<T> *next;
    while(first)
    {
        next = first->next;
        delete first;
        first = next;
    }
}

template <typename T>
int Chain<T>::length() const
{
    ChainNode<T> *current;
    current = first;
    int length = 0;
    while(current)
    {
        ++length;
        current = current->next;
    }
    return length;
}

template <typename T>
bool Chain<T>::find(int k, T &x) const
{
    if(k < 1) return false;
    int index = 1;
    ChainNode<T> *current = first;
    while(current && index < k)
    {
        ++index;
        current = current->next;
    }
    if(current)
    {
        x = current->data;
        return true;
    }
    return false;

}

template <typename T>
int Chain<T>::search(const T &x) const
{
    ChainNode<T> *current = first;
    int index = 1;
    while(current && current->data != x)
    {
        ++index;
        current = current->next;
    }
    if(current)
        return index;
    return 0;
}

template <typename T>
Chain<T> &Chain<T>::insert(int k, const T &x)
{
    if(k < 0)
    {
        throw OutOfBounds();
    }
    ChainNode<T> *current = first;
    for(int index = 1; index < k && current; ++index)
    {
        current = current->next;
    }
    if(!current && k > 0)//k>0表示不在第一个位置插入即排除k=0
    {
        throw OutOfBounds();
    }
    ChainNode<T> * newNode = new ChainNode<T>;
    newNode->data = x;
    if(k)
    {
        newNode->next = current->next;
        current->next = newNode;
    }
    else//k=0
    {
        newNode->next = first;
        first = newNode;
    }
    return *this;
}

template <typename T>
Chain<T> &Chain<T>::remove(int k, T &x)//主要注意的是删除首尾元素，删除唯一元素
{
    if(k < 1 || !first)
    {
        throw OutOfBounds();
    }
    ChainNode<T> *current = first;

    if(k == 1)//删除第一个元素
    {
        first = first->next;//将current从链表中移除
    }
    else
    {
        for(int index = 2; index < k && current; ++index)
        {
            current = current->next;
        }
        if(!current || !current->next)
        {
            throw OutOfBounds();
        }
        ChainNode<T> *tmp = current;//保存删除结点的前一节点
        current = current->next;//将current移至要删除结点
        tmp->next = current->next;//将current从链表中移除
    }
    x = current->data;
    delete current;
    return *this;
}

template <typename T>
void Chain<T>::outPut(ostream &out) const
{
    ChainNode<T> *current;
    for(current = first; current; current = current->next)
    {
        out<< current->data << " ";
    }
}

// 重载 << 运算符
template <class T>
ostream& operator<<(ostream &out, const Chain<T> &x)
{
    x.outPut(out);
    return out;
}

////////////////////////////////////////////////////////////////////////////

#endif // CHAIN_H
