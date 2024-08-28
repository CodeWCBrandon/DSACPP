#include <stdio.h>

int LinearSearch(int* arr, int length, int value);

int main(void)
{
	//**************************************************
	
	// Linear Search = Iterate through a collection one element at a time
	
	//				   Runtime Complexity
	//						  O(n)
	
	//				   Disadvantages:
	//				   1. slow for data sets
		
	//				   Advantages:
	//				   1. Fast for searches of small to medium data sets
	//				   2. Does not need to sorted
	//				   3. Useful for data structure that do not have random access (linked list)
	
	//**************************************************
	
	int arrLen = 10;
	int arr[arrLen] = {9, 1, 5, 3, 2, 5, 1, 5, 7, 9};
	
	int index = LinearSearch(arr, arrLen, 10);
	
	if(index == -1)
	{
		printf("Value isn't found\n");
	}else
	{
		printf("Index: %d\n", index);	
	}
	
	//**************************************************
}

int LinearSearch(int* arr, int length, int value)
{
	for(int i = 0; i < length; i++)
	{
		if(arr[i] == value)
		{
			return i;
		}
	}
	
	return -1;
}