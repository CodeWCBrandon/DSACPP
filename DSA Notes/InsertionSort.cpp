#include <stdio.h>
#include <cstdlib>
#include <time.h>

void InsertionSort(int* arr, int arrLength);

int main(void)
{
	//*******************************************************
	
	// Insertion Sort = store the right value to temp and if the
	//					left element is greater than the temp
	//					shift the left element to the right
	
	// 					Time complexity = O(n^2)
	
	//					Best cases = O(n)
	
	//*******************************************************
	
	//Input Case
	srand(time(NULL));
	
	int arrLength = 100;
	int arrInput[arrLength];
	
	for(int i = 0; i < arrLength; i++)
	{
		arrInput[i] = rand() % 100;
		printf("%d, ", arrInput[i]);
	}
	
	//Sorting
	printf("\n----------------------------------------------\n");
	printf("Sorted:\n");
	
	InsertionSort(arrInput, arrLength);
	
	for(int i = 0; i < arrLength; i++)
	{
		printf("%d, ", arrInput[i]);
	}
	
	//*******************************************************
}

void InsertionSort(int* arr, int arrLength)
{
	for(int i = 1; i < arrLength; i++)
	{	
		int temp = arr[i]; // store the right value
		int j = i - 1;
		
		while(j >= 0 && arr[j] > temp) //shift the left value to the rigth value
		{
			arr[j + 1] = arr[j];
			j--;
		}
		
		arr[j + 1] = temp;
	}
}
