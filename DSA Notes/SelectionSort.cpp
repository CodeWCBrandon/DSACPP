#include <stdio.h>
#include <cstdlib>
#include <time.h>

void SelectionSort(int* arr, int arrLen);

int main(void)
{
	//*********************************************************************
	
	//Selection Sort = search through an array and keep the min value then
	//				   at the end of array swap the lowest value with the front
	
	//				   Time complexity = O(n^2)
	
	//*********************************************************************
	
	//Setting Input
	srand(time(NULL));
	
	int arrLen = 100;
	int arr[arrLen];
	
	for(int i = 0; i < arrLen; i++)
	{
		arr[i] = rand() % 10;
		printf("%d, ", arr[i]);
	}
	
	//Sorting
	printf("\n--------------------------------------\n");
	printf("Sorted: \n");

	SelectionSort(arr, arrLen);
	
	for(int i = 0; i < arrLen; i++)
	{
		printf("%d, ", arr[i]);
	}
	
	//*********************************************************************
}

void SelectionSort(int* arr, int arrLen)
{
	for(int i = 0; i < arrLen - 1; i++)
	{
		int min = i; // create a variable min as an index
				
		for(int j = i + 1; j < arrLen; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j; // change the min to smaller index
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}