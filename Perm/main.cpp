#include <iostream>

using namespace std;


/**
 *
 * 函数难点：递归调用
 * 函数功能：使用递归生成排列组合
 * 难点注释：首先确定前缀，前缀确定后，后缀从尾部长度为二时开始交换，这时只能交换最后两个，
 * 返回上级，长度为三的时候，开始依次是交换倒数32 跳入长度为二级 跳出 交换倒数31 跳入长度为二级 跳出
 * 循环层数依次减少
 *  swap list 0 list 0 list turn to abc
        swap list 1 list 1 list turn to abc
            output  abc
        swap list 1 list 1 list turn to abc
        swap list 1 list 2 list turn to acb
            output  acb
        swap list 1 list 2 list turn to abc
    swap list 0 list 0 list turn to abc
    swap list 0 list 1 list turn to bac
        swap list 1 list 1 list turn to bac
            output  bac
        swap list 1 list 1 list turn to bac
        swap list 1 list 2 list turn to bca
            output  bca
        swap list 1 list 2 list turn to bac
    swap list 0 list 1 list turn to abc
    swap list 0 list 2 list turn to cba
        swap list 1 list 1 list turn to cba
            output  cba
        swap list 1 list 1 list turn to cba
        swap list 1 list 2 list turn to cab
            output  cab
        swap list 1 list 2 list turn to cba
    swap list 0 list 2 list turn to abc
 *
 */

template <typename T>
void Swap(T &a , T &b)
{
    T temp = b;
    b = a;
    a = temp;
}

template <typename T>
void Perm(T list[], int k, int m)
{
    int i;
    if(k == m)
    {
        cout <<"output  ";
        cout << list << endl;
    }
    else
    {
        for(i = k; i <= m; ++i)
        {
            //cout << "swap " << "list " << k << " list " << i <<endl;
            Swap(list[k] , list[i]);
            cout << "swap " << "list " << k << " list " << i << " list turn to "<< list << endl;
            Perm(list, k+1, m);
            //cout << "swap " << "list " << k << " list " << i <<endl;
            Swap(list[k] , list[i]);
            cout << "swap " << "list " << k << " list " << i << " list turn to "<< list << endl;
        }
    }
}



int main()
{
    char ll[5] = "abc";
    Perm(ll,0,2);
    return 0;
}

