#include <iostream>
#include "sequentialsearch.h"
#include "binarysearch.h"

using namespace std;

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    //cout << sequentialSearch(a,5,10);
    cout << binarySearch(a,5,10);

    return 0;
}

