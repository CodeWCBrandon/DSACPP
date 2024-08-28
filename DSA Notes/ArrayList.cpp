#include <stdio.h>
#include <cstdlib>

//i tried to make my own simple vector (this is a simple int vector that i've made)
struct ArrayList
{
	int *items; // item array
	size_t capacity;
	size_t length;
	
	void push(int item)
	{
		if(this->capacity > this->length)
		{
			this->items[this->length] = item; // add item
		}else
		{
			//Creating a handler
			size_t newCap = this->capacity * 2; // create a new cap for the next cap of the array
			int *newArr = (int*)malloc(newCap * sizeof(int)); // create a new Array
			int *oldArr = this->items; // keep the pointer to the old array
			
			//Assigning the handler
			this->capacity = newCap; // update the capacity
			this->items = newArr; // pointing to the new array
			for(int i = 0; i < this->length; i++)
			{
				newArr[i] = oldArr[i]; // assigning old array value to the new array value
			}
			free(oldArr); // free the memory
			this->items[this->length] = item; // add item 
		}
		this->length += 1;
		
	}
	
	void Reserve(int newCap) // reserve a memory
	{
		this->capacity = newCap;
		this->length = 0;
	}
	
	void UpdateItems() // allocate memory for the items (item array)
	{		
		this->items = (int*)malloc(this->capacity * sizeof(int));
	}
	
	void FreeItems()
	{
		free(this->items); // free items memory
	}
	
	void DisplayAll()
	{
		for(int i = 0; i < this->length; i++)
		{
			printf("%d. %d\n", i + 1, this->items[i]);
		}
	}
};

int main(void)
{
		
	ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList*)); 	
	list->Reserve(10);
	list->UpdateItems();	
	
	for(int i = 0; i < 10000; i++)
	{
		list->push(i * 100);
	}
	
	list->DisplayAll();
	printf("\ncapacity: %d, length: %d", list->capacity, list->length);
	
	list->FreeItems();
	free(list);
}