// Buzan Meda 30421
// 
//	Heap sort:
//		best case -nlogn
//		worst case -nlogn
//
//	Quick sort :
//		best case -nlogn
//		worst case -n ^ 2
// 
// -quick sort is a recursive algorithm : we choose an element, a PIVOT that meets the conditions (after sorting) : 1. pivot in its correct position 
//																													2. elements on the left are smaller 
//																													3. elements in the right are larger
// -how does it work? : first, we move the pivot to the end of the array. Then, we look for 2 elements : 1. the first element larger than the pivot starting from the left - let's call it A
//																										2. the first element smaller than the pivot starting from the right - let's call it B
//					   after we find the two elements, we swap them. We repeat this process until the index of elem B is smaller than the index of elem A
//					   when the index of B is smaller than the index of A we swap the pivot with element A
//					   Now, we have 2 partitions - one to the left of the pivot, and one to the right -> we repeat the steps above on these partitions using recursion
// We want to choose a pivot that divides in half or as close as possible 
//

#include <iostream>
#include "Profiler.h"
#define sizeM 10001


using namespace std;
Profiler profiler("AverageQuick");

void Heapify(int a[], int  i, int heapsize)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i;
    profiler.countOperation("HeapSort", heapsize, 2);
    if (left <= heapsize && a[left] > a[i])
        largest = left;
    profiler.countOperation("HeapSort", heapsize, 2);
    if (right <= heapsize && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        profiler.countOperation("HeapSort", heapsize, 3);
        swap(a[i], a[largest]);
        Heapify(a, largest, heapsize);
    }
}

void BuildHeap(int a[], int heapsize)
{
    for (int i = heapsize / 2; i >= 1; i--)
        Heapify(a, i, heapsize);
}

void HeapSort(int a[], int heapsize)
{
    int heapsize2 = heapsize;
    profiler.countOperation("HeapSort", heapsize);
    BuildHeap(a, heapsize);
    for (int i = heapsize; i > 1; i--)
    {
        swap(a[1], a[i]);
        heapsize2--;
        Heapify(a, 1, heapsize2);

    }
}

int partition(int a[], int p, int r)
{
	profiler.countOperation("QuickSort-all",r);
	int x = a[p];
	int i = p ;
	for (int j = p + 1; j <= r ; j++)
	{
		profiler.countOperation("QuickSort-all", r);
		if (a[j] <= x)
		{
			i+= 1;
			swap(a[i], a[j]);
			profiler.countOperation("QuickSort-all", r,3);
		}

	}
	swap(a[i], a[p]);
	profiler.countOperation("QuickSort-all", r, 3);

	return i;
}


void quickSort(int a[], int p, int r)
{
	profiler.countOperation("QuickSort-all", r);

	if (p < r)
	{
		int q = partition(a, p, r);
		quickSort(a, p, q );
		quickSort(a, q + 1, r);
	}
}
int randPartition(int a[], int p, int r)
{
	int i = rand() % r + p;
	swap(a[r], a[i]);
	return partition(a, p, r);
}
int QuickSelect(int a[], int p, int r, int i)
{
	if (p == r)
		return a[p];
	int q = randPartition(a, p, r);
	int k = q - p + 1;
	if (i == k)
		return a[q];
	else
		if (i < k)
			return QuickSelect(a, p, q - 1, i);
		else
			return QuickSelect(a, q + 1, r, i - k);
}
void AverageCase()
{
	int a[sizeM], b[sizeM];
	for (int i = 100; i <= sizeM; i += 500)
	{
		FillRandomArray(a, i,10,50000,true,0);
		CopyArray(b, a, i);
		quickSort(a, 1, i);
		///CopyArray(c, b, i);
		HeapSort(a, i);
	}
	profiler.createGroup("QuickSort + HeapSort", "QuickSort-all", "HeapSort");
	profiler.showReport();
}
void WorstCase()
{
	int c[sizeM];
	for (int i = 100; i <= sizeM; i += 500)
	{
		FillRandomArray(c, i, 10, 50000, true, DESCENDING);
		///CopyArray(b, a, i);
		///quickSort(a, 1, i);
		///CopyArray(c, b, i);
		HeapSort(c, i);
	}
	profiler.createGroup("HeapSort-worst", "HeapSort");
	profiler.showReport();
}
int main()
{
	int a[] = { 0,5,6,7, 4 ,3, 2, 1 };

	quickSort(a, 1, 7);
	cout << " quick sort ";
	for (int i = 1; i <= 7; i++)
		cout << a[i]<<' ';
	cout << '\n';

	int abc[] = { 0,2,8,5,3,9,1 };
	HeapSort(abc, 6);
	cout << " heap sort ";
	for (int i = 1; i <= 6; i++)
		cout << abc[i] << ' ';
	cout << '\n';

	int ab[] = { 0,3, 1, 2, 5 };
	cout << "quick select ";
	cout<<QuickSelect(ab,1,4,2 );
	

	///AverageCase();
	///WorstCase();

	return 0;

}


