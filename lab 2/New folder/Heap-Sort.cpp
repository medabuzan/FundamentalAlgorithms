// Heap-Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "Profiler.h"

using namespace std;


    void Heapify(int a[],int  i, int heapsize)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i ;
        if (left <= heapsize && a[left] > a[i])
            largest = left;
        if (right <= heapsize && a[right] > a[largest])
            largest = right;
        if (largest != i)
        {
            swap(a[i], a[largest]);
            Heapify(a, largest, heapsize);
        }

    }


    void BuildHeap(int a[], int heapsize)
    {
       /// int heapsize = sizeof(a);
        for (int i = heapsize / 2; i >= 1; i--)
            Heapify(a, i, heapsize);

    }

        void HeapSort(int a[], int heapsize)
        {
            int heapsize2 = heapsize;

            BuildHeap(a, heapsize);
            for (int i = heapsize; i > 1; i--)
            {
                swap(a[1], a[i]);
                heapsize2--;
                Heapify(a, 1, heapsize2);

            }
        }
int main()
{
    int a[] = { 0,2,8,5,3,9,1 };
    ///int n = sizeof(a) / sizeof(a[0]) + 1;
    HeapSort(a, 7);
    ///cout << n << endl;

    ///BuildHeap(a, 7);
    ///Heapify(a, 0);
    for (int i = 1; i <= 6; i++)
        cout << a[i] << ' ';
}


