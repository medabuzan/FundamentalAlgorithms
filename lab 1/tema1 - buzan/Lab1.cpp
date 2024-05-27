/*	Buzan Meda  30421
*  

		Assignment No. 1: Analysis & Comparison of Direct
		Sorting Methods - Bubble sort, Selection sort and Insertion sort 
 *
 * 
 * - the  average case : - random input
 *						 - efficiency : 1) based on total operations : 1-SELECTION SORT complexity: ?(n^2)
 *																	 2-INSERTION SORT complexity: ?(n^2)
 *																	 3-BUBBLE SORT complexity: ?(n^2)
 *									  2) based on assignments : 1-SELECTION SORT is the most efficient (linear number of assignments)
 *																2-INSERTION SORT and BUBBLE SORT (quadratic number of assignments)
 *									  3) based on comparisons : 1-INSERTION SORT 
 * 
 * 
 * - the best case (the input is already sorted ) : -  bubble and insertion sort are equally efficient (linear complexity for comparisons)
 *													-  selection sort has a quadratic number of comparisons performed
 *													-  no algorithm makes assignments
 *													- complexity : selection sort-> ?(n^2)
 *																   bubble sort-> O(n)
 *																   insertion sort-> O(n)
 *
 * - the worst case (input sorted backwards) - efficiency : 1) selection sort (linear number of assignments) complexity: ?(n^2)
*															2) insertion and bubble sort(quadratic assignments) complexity: ?(n^2)
* 
*  Stability : bubble sort and insertion sort are stable
*/

#include <iostream>
#include "Profiler.h"

#define sizeM 10000

using namespace std;

Profiler profiler("Average");

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			profiler.countOperation("bubbleSort-comp", n);
			profiler.countOperation("bubbleSort-all", n);

			if (a[i] > a[j])
			{ 
				swap(a[i], a[j]);

				profiler.countOperation("bubbleSort-ass", n, 3);
				profiler.countOperation("bubbleSort-all", n, 3);

			}

		}
}

void SelectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{	
			profiler.countOperation("selectionSort-comp", n);
			profiler.countOperation("selectionSort-all", n);
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			swap(a[min], a[i]);
			profiler.countOperation("selectionSort-ass", n, 3);
			profiler.countOperation("selectionSort-all", n, 3);
		}
	}
		
}

void InsertionSort(int a[], int n)
{
	int i = 1;
	int j;
	while (i < n)
	{
		j = i;
		profiler.countOperation("insertionSort-comp", n);
		profiler.countOperation("insertionSort-all", n);
		while (j > 0 && a[j - 1] > a[j])
		{
			swap(a[j], a[j - 1]);
			profiler.countOperation("insertionSort-ass", n, 3);
			profiler.countOperation("insertionSort-all", n, 3);
			j--;
		}
		i++;
	}

}

void AverageCase()
{
	int a[sizeM], b[sizeM], c[sizeM];
	for (int i = 100; i <= sizeM; i += 500)
	{
		FillRandomArray(a, i);
		CopyArray(b, a, i);
		BubbleSort(a, i);
		CopyArray(c, b, i);
		InsertionSort(b, i);
		SelectionSort(c, i);
	}

	profiler.createGroup("BubbleSort-average", "bubbleSort-ass", "bubbleSort-comp", "bubbleSort-all");
	profiler.createGroup("InsertionSort-average", "insertionSort-ass", "insertionSort-comp", "insertionSort-all");
	profiler.createGroup("SelectionSort-average", "selectionSort-ass", "selectionSort-comp", "selectionSort-all");
	profiler.createGroup("AllSorts-sums-average", "bubbleSort-all", "insertionSort-all", "selectionSort-all");
}

void WorstCase()
{
	int a[sizeM], b[sizeM], c[sizeM];
	for (int i = 100; i <= sizeM; i += 500)
	{
		FillRandomArray(a, i, 10, 50000, false, 2); /// 2 = DESCENDING ; 1 = ASCENDING 
		CopyArray(b, a, i);
		BubbleSort(a, i);
		CopyArray(c, b, i);
		InsertionSort(b, i);
		SelectionSort(c, i);
	}

	profiler.createGroup("BubbleSort-worst", "bubbleSort-ass", "bubbleSort-comp", "bubbleSort-all");
	profiler.createGroup("InsertionSort-worst", "insertionSort-ass", "insertionSort-comp", "insertionSort-all");
	profiler.createGroup("SelectionSort-worst", "selectionSort-ass", "selectionSort-comp", "selectionSort-all");
	///same as average for selection
	profiler.createGroup("AllSorts-sums-worst", "bubbleSort-all", "insertionSort-all", "selectionSort-all");
}

void BestCase()
{
	int a[sizeM], b[sizeM], c[sizeM];
	for (int i = 100; i <= sizeM; i += 500)
	{
		FillRandomArray(a, i, 10, 50000, false, 1); /// 2 = DESCENDING ; 1 = ASCENDING 
		CopyArray(b, a, i);
		BubbleSort(a, i);
		CopyArray(c, b, i);
		InsertionSort(b, i);
		SelectionSort(c, i);

	}

	profiler.createGroup("BubbleSort-best", "bubbleSort-comp", "bubbleSort-all");
	///we have no assignments so the assignment column does not exist
	profiler.createGroup("InsertionSort-best", "insertionSort-comp", "insertionSort-all");
	///we have no assignments so the assignment column does not exist
	profiler.createGroup("SelectionSort-best", "selectionSort-comp", "selectionSort-all");
	profiler.createGroup("AllSorts-sums-best", "bubbleSort-all", "insertionSort-all", "selectionSort-all");
}

int main()
{
	int a[] = { 3, 1, 2, 5 };
	BubbleSort(a, 4);
	for (int i = 0; i < 4; i++)
		cout << a[i] << ' ';
	cout << '\n';

	int ab[] = { 3, 1, 2, 5 };
	InsertionSort(ab, 4);
	for (int i = 0; i < 4; i++)
		cout << ab[i] << ' ';
	cout << '\n';

	int abc[] = { 3, 1, 2, 5 };
	SelectionSort(abc, 4);
	for (int i = 0; i < 4; i++)
		cout << abc[i] << ' ';
	cout << '\n';

	AverageCase();
	profiler.reset("Worst");
	WorstCase();
	profiler.reset("Best");
	BestCase();
	profiler.showReport();

	return 0;
}
