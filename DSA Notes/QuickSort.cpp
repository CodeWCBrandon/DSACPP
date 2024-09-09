#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int* arr, int start , int end);
int Partition(int* arr, int start, int end);


int main(void)
{
	//***************************************************
	
	// QuickSort = Move smaller element to the left side of the pivot,
	//			   recursively divide array in 2 partitions
	
	// 				What to do? 
	// 				1. Choosing a pivot, at this case place the pivot at the back
	//				2. Partitioning, rearrange the array so that all of the elements
	//				   less than the pivot is on the left and the greater one is on the right
	//				3. Recursively apply, partitioning in the sub array by splitting the array
	
	//				Time Complexity: O(n log n)
	//				Worst case	   : O(n^2)
	
	//***************************************************
				
	//User input
	srand(time(NULL));
	
	int arrLen = 10;
	int arr[arrLen];
	
	for(int i = 0; i < arrLen; i++)
	{
		arr[i] = rand() % 100;
		printf("%d, ", arr[i]);
	}
	
	//User Output
	printf("\n--------------------------------------\n");
	printf("Sorted: \n");
	
	QuickSort(arr, 0 , arrLen - 1);
	
	for(int i = 0; i < arrLen; i++)
	{
		printf("%d, ", arr[i]);
	}
	
}

void QuickSort(int* arr, int start, int end)
{
	if(end <= start) return; //base case
	
	//Set Pivot and sort
	int pivot = Partition(arr, start, end);
	
	//Recursively using pivot to sort
	QuickSort(arr, start, pivot - 1);
	QuickSort(arr, pivot + 1, end);
}

int Partition(int* arr, int start, int end)
{
	//set the last element of the array to pivot
	int pivot = arr[end];
	
	//set the i before the start
	int i = start - 1;

	//set the j in the start postion
	for(int j = start; j < end; j++)
	{
		if(arr[j] < pivot)
		{
			//Step 1. move i
			i++;
			
			//Step 2. switch the value between the i and the j
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	//Switching the value with the pivot so the pivot is in the center
	//Step 1. Move i
	i++;
	
	//Step 2. Switch the value between the i and pivot
	int temp = arr[i];
	arr[i] = arr[end];
	arr[end] = temp;
	
	return i; // return the location of the pivot
}