#include <stdio.h>
#include <cstdlib>
#include <time.h>

void MergeSort(int* arr, int length);
void Merge(int* leftArr, int leftSize, int* rightArr, int rightSize, int* arr);

int main(void)
{
	
	//***************************************
	
	//Merge sort = is a sorting algorithm that uses the
	//			   divide-and-conquer approach (use recursion)
	
	//Divide = split the array into two halves until two elements each
	//Conquer = Recursively sort each half
	//Merge = Combine two sorted halves to produce the sorted array
	
	//Time Complexity = O(n log n)
	
	//*************************************** 
	
	//Input Test
    srand(time(NULL));
    
    const int arrLength = 100;
    int arr[arrLength];
    
    for(int i = 0; i < arrLength; i++)
    {
        arr[i] = rand() % 100;
        printf("%d, ", arr[i]);
    }
    
    //Output Test
    printf("\n---------------------------------------------\n");
    printf("Sorted: \n");
    
    MergeSort(arr, arrLength);
    
    for(int i = 0; i < arrLength; i++)
    {
        printf("%d, ", arr[i]);
    }
}

void MergeSort(int* arr, int length)
{
    if(length <= 1) return; // base case
    
    // Split the array in half and
	// make the left array and the right array
    int middle = length / 2;
    int leftArr[middle];
    int rightArr[length - middle];
    
	// Insert the left array value from original array   
    for(int i = 0; i < middle; i++)
    {
        leftArr[i] = arr[i];
    }
    
    //Insert the right array value from original array
    for(int i = middle; i < length; i++)
    {
        rightArr[i - middle] = arr[i];
    }
    
    // Split the array in half again until the length <= 1
    MergeSort(leftArr, middle);
    MergeSort(rightArr, length - middle);
    
    // Sort and Merge the array to the upper layer
    Merge(leftArr, middle, rightArr, length - middle, arr);
}

void Merge(int* leftArr, int leftSize, int* rightArr, int rightSize, int* arr)
{
	// creating a variable for index arr, left arr index, and right arr index
    int i = 0, l = 0, r = 0; 
    
    // Sort each value by compare it which one is the lowest from left arr and right arr
    while(l < leftSize && r < rightSize)
    {
        if(leftArr[l] < rightArr[r])
        {
            arr[i] = leftArr[l];
            i++;
            l++;
        }
        else
        {
            arr[i] = rightArr[r];
            i++;
            r++;
        }
    }
    
    // Merge the remaining value if the right array doesn't have any value left
    while(l < leftSize)
    {
        arr[i] = leftArr[l];
        i++;
        l++;
    }
    
    // Merge the remaining value if the left array doesn't have any value left
    while(r < rightSize)
    {
        arr[i] = rightArr[r];
        i++;
        r++;
    }
}
