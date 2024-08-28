#include <stdio.h>

int BinarySearch(int* arr, int length, char target);

int main(void)
{
	//*********************************************
	
	// Binary Search =  Search algorithm that finds the position of a target
	//					value within a sorted array. Half of the array
	//					is eleminated during each "step"
	
	//*********************************************
	
	int arrLen = 26;
	char target = '/';
	int arr[arrLen] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N',
					'O', 'P', 'Q', 'R', 'S', 'T', 'U',
					'V', 'W', 'X', 'Y', 'Z'};
					
	int index = BinarySearch(arr, arrLen, target);
	
	if(index == -1)
	{
		printf("%c wasn't found", target);
		return 1;
	}else
	{
		printf("%c is in index: %d", target, index);
	}

	//*********************************************		
}

int BinarySearch(int* arr, int length, char target)
{
	int low = 0; //lowest index
	int high = length - 1; //highest index
	
	while(low <= high)
	{
		int middle = low + (high - low) / 2; // get the middle index
		int value = arr[middle];
		
		if(target > value)
		{
			low = middle + 1; // change the low index to the middle part
		}else if(target < value)
		{
			high = middle - 1; //change the high index to the middle part
		}else
		{
			return middle; // if the value == target
		}
	}
	
	return -1;
}