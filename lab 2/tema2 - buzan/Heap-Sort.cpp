// Heap-Sort : efficiency top down: O(nlogn) - the tree is constructed first and a heapify function is called on the nodes
//                        bottom up: O(n)
// 
//

#include <iostream>
#include "Profiler.h"
#define sizeM 10001
#define stepSize 501
#define tests 5
using namespace std;
Profiler profiler("AverageCase");

    void Heapify(int a[],int  i, int heapsize)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i ;
        profiler.countOperation("BottomUp", heapsize,2);
        if (left <= heapsize && a[left] > a[i])
            largest = left;
        profiler.countOperation("BottomUp", heapsize, 2);
        if (right <= heapsize && a[right] > a[largest])
            largest = right;
        if (largest != i)
        {
            profiler.countOperation("BottomUp", heapsize, 3);
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
            profiler.countOperation("BottomUp", heapsize);
            BuildHeap(a, heapsize);
            for (int i = heapsize; i > 1; i--)
            {
                swap(a[1], a[i]);
                heapsize2--;
                Heapify(a, 1, heapsize2);

            }
        }


    void insert(int a[], int i, int heapsize)
    {
        int j = i;
        heapsize++;
        
        while (a[j / 2] < a[j] && j>1)
        {
            profiler.countOperation("TopDown", heapsize);
            profiler.countOperation("TopDown", heapsize, 3);
            swap(a[j], a[j / 2]);
                j = j / 2;
        }
    }

    void topDown(int a[], int n)
    {
        profiler.countOperation("TopDown", n);
        int heapsize = 1;
        for (int i = 2; i <= n; i++)
        {
            insert(a, i, heapsize);
        }
    }

    void Charts()
    {
        int countt = 0;
        int a1[sizeM];
        int a2[sizeM];
        for (int i = 101; i <= sizeM; i += 500)
            for(int j=1; j<= tests; j++)
        {
            
                FillRandomArray(a1,i);
                CopyArray(a2, a1, i);
                BuildHeap(a1, i);
                topDown(a2, i);
            }
           // profiler.divideValues("BottomUp", countt);
          //  profiler.divideValues("TopDown", countt);
            profiler.createGroup("BottomUp+TopDown", "BottomUp", "TopDown");
            profiler.showReport();
    }
int main()
{
    int a[] = { 0,2,8,5,3,9,1 };
   
    ///BuildHeap(a, 6);
    ///Heapify(a, 1,6);

    topDown(a, 6);
    cout << "top down ";
    for (int i = 1; i <= 6; i++)
        cout << a[i] << ' ';
    cout << '\n';

    int ab[] = { 0,2,8,5,3,9,1 };
    BuildHeap(ab, 6);
    cout << "bottom up ";
    for (int i = 1; i <= 6; i++)
        cout << ab[i] << ' ';
    cout << '\n';

    int abc[] = { 0,2,8,5,3,9,1 };
    HeapSort(abc, 6);
    cout <<" heap sort ";
    for (int i = 1; i <= 6; i++)
        cout << abc[i] << ' ';
    cout << '\n';

    Charts();
    return 0;
}

