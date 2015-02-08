#include <iostream>
#include "chain.h"

using namespace std;

int main()
{
    try
    {
        Chain<int> L;
        cout << "Length = " << L.length() << endl;
        cout << "IsEmpty = " << L.isEmpty() << endl;
        L.insert(0,2).insert(1,6);
        cout << "List is " << L << endl;
        cout << "IsEmpty = " << L.isEmpty() << endl;
        int z;
        L.find(1,z);
        cout << "First element is " << z << endl;
        cout << "Length = " << L.length() << endl;
        L.remove(1,z);
        cout << "Deleted element is " << z << endl;
        cout << "List is " << L << endl;
    }
    catch (...)
    {
        cerr << "An exception has occurred" << endl;
    }
    return 0;
}

