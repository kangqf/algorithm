#define SIZE 10
#include <iostream>

#include "selectionsort.h"
#include "bubblesort.h"

using namespace std;

int main()
{

    int arr[SIZE];

    for(int i = 0; i < SIZE-1; ++i)
        cin >> arr[i];

    for(int i = 0; i < SIZE-1; ++i)
        cout<<arr[i]<<"  ";

    //selectionSort(arr,SIZE-1);
    bubbleSort(arr,SIZE-1);
    cout<<" "<<endl<<"";

    for(int i = 0; i < SIZE-1; ++i)
        cout<<arr[i]<<"  ";

    return 0;
}

