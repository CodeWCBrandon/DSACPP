#include <stdio.h>

int InterpolationSearch(int* arr, int length, int target);

int main(void)
{
	//*******************************************
	
	//Interpolation Search = Improvement over binary search best used for "uniformly" distributed data
	//						 "guesses" where a value might be on calculated probe results
	//						 if probe is incorrect, search area is narrowed, and the new probe is calculated
	//						 (only works in sorted array)
	
	//						Average Case: O(log(log (n)))
	//						Worst Case: O(n) [values increase exponentially] 
	
	//*******************************************
	
	int arrLen = 10;
	int target = 8;
	int array[arrLen] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int index = InterpolationSearch(array, arrLen, target);
	
	if(index == -1)
	{
		printf("%d was not found", target);
	}else
	{
		printf("%d is in index: %d", target, index);
	}
	
	//*******************************************
}

int InterpolationSearch(int* arr, int length, int target)
{
	int low = 0;
	int high = length - 1;
	
	while(target >= low && target <= high && low <= high)
	{
		int probe = low + (high - low) * (target - arr[low]) / (arr[high] - arr[low]); // the probe formula
		
		printf("probe: %d\n", probe); // print the probe for testing
		
		if(arr[probe] == target)
		{
			return probe;
		}else if(arr[probe] < target)
		{
			low = probe + 1;
		}else if(arr[probe] > target)
		{
			high = probe - 1;
		}
	}
	
	return -1;
}