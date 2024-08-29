#include <stdio.h>
#include <cstdlib>
#include <time.h>

void BubbleSort(int* arr, int length);

int main(void)
{
	//***********************************************
	
	//Bubble Sort = pairs of adjecent elements are compared, and the elements
	//				swapped if they are not in order.
	
	//				Time Complexity : O(n^2)

	//***********************************************
	
	
	//Making Randomized user input
	srand(time(NULL));
	
	int arrLen = 100;
	int arr[arrLen];
	for(int i = 0; i < arrLen; i++) 
	{
		arr[i] = rand() % 1000;
		printf("%d, ", arr[i]);
	}
	
	printf("-------------------------------------------------\n");
	printf("Sorted:\n");
	
	//Sorting
	BubbleSort(arr, arrLen);
	
	for(int i = 0; i < arrLen; i++)
	{
		printf("%d, ", arr[i]);
	}
	
	//***********************************************
}

void BubbleSort(int* arr, int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])	
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}