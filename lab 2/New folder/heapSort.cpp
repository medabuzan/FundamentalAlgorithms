// heapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Profiler.h"


using namespace std;

Profiler profiler("Heap");
#define sizeM 10000
void insert(int a[], int k, int heapsize)
{
	heapsize++;

	int i = heapsize - 1;
	a[i] = k;
	while (i > 0 && a[(i - 1) / 2] < a[i])
	{
		swap(a[(i - 1) / 2], a[i]);
		i = (i - 1) / 2;
	}
}

void topDown(int a[], int n)
{
	int heapsize = 1;
	int i;
	for (i = 0; i < n; i++)
		insert(a, a[i], n);

}

void heapify(int a[], int i, int n)
{
	int heapsize = n;
	int largest;
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	if (l <= heapsize && a[l] > a[i])
	{
		largest = l;
	}
	else
		largest = i;
	if (r < heapsize && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, largest, n);
	}
}

void bottomUp(int a[], int n)
{
	int heapsize = (n - 1) / 2;
	for (int i = heapsize; i >= 0; i--)
		heapify(a, i, n);
}


void heapSort(int a[], int n)
{
	bottomUp(a, n);
	for (int i = n-1; i >0; i--)
	{
		swap(a[0], a[i]);
		n--;
		heapify(a, 0,i);
	}
}


void heaptest( )
{
	int a[10000];
	for (int i = 100; i <= 10000; i += 500)
	{
		FillRandomArray(a, i);
		heapSort(a, i);
	}
}

int main()
{
	int a[] = { 3, 2, 1, 5, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	bottomUp(a, n);
	heapSort(a, n);
	for (int i = 0; i < 5; i++)
		cout << a[i] << ' ';
	cout << '\n';


	return 0;
}


