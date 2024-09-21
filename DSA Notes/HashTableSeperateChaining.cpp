#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

//Creating data to hash
struct Data
{
	const char* name;
	int age;
	Data* next;
};

//Creating the global scope HashTable
Data* HashTable[TABLE_SIZE];

//Hashing function
unsigned int Hash(const char* key)
{
	int length = strlen(key);
	unsigned int hashValue = 0;
	
	for(int i = 0; i < length; i++)
	{
		//Creating the hash value
		hashValue += key[i];
		hashValue = (hashValue * key[i]) % TABLE_SIZE;	
	}
	
	return hashValue;
}

//HashTable function to search name
void HashTableSearch(const char* key)
{
	//Creating the index from hashing
	int index = Hash(key);
	
	//Creating the duplicate, so the HashTable position remain the same
	Data* curr = HashTable[index];
	
	//Traverse the HashTable using curr
	while(curr != NULL)
	{
		//Check if the name are the same
		if(strcmp(curr->name, key) == 0)
		{
			printf("%s Target Found!\n", key);
			printf("Name: %s\n", curr->name);
			printf("Age: %d\n\n", curr->age);
			return;
		}
		
		//Go to the next location if the name are different
		curr = curr->next;
	}
	
	//If the target isn't found
	printf("%s Target Not Found!\n", key);
}

//Inserting Data to the HashTable
void HashTableInsert(const char* name, int age)
{

	//Creating a newNode	
	Data* newNode = (Data*)malloc(sizeof(Data));
	newNode->age = age;
	newNode->name = name;
	newNode->next = NULL;
	
	//Creating the index using hash
	int index = Hash(name);
	
	//Creating the duplicate, so the HashTable remain the same
	Data* curr = HashTable[index];
	
	//Check if the curr index is null or not
	if(curr == NULL)
	{
		//Insert the value if it's null
		HashTable[index] = newNode;
		return;
	}
	
	//Traverse the HashTable if there's more than one value
	while(curr != NULL)
	{	
		//Check if the next one are NULL
		if(curr->next == NULL)
		{
			//Assign the next one to the newNode
			curr->next = newNode;	
			return;	
		}
		
		//Move the curr to the next one
		curr = curr->next;
	}
}

//Print all the data in the hash Table
void PrintHashTable()
{	
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		//Creating a copy just like usual
		Data* curr = HashTable[i];
		
		//Traverse the curr
		while(curr != NULL)
		{
			printf("%d:\n", i);
			printf("%s\n", curr->name);
			printf("%d\n\n", curr->age);
			
			curr = curr->next;
		}
	}
}

int main(void)
{	
	//Creating a target for the inputs
	char* target = (char*)malloc(100 * sizeof(char));
	
	//Inserting the value
	HashTableInsert("joe mama", 100);
	HashTableInsert("joe mama", 100);
	HashTableInsert("smem", 18);
	HashTableInsert("samwang", 25);
	HashTableInsert("berat", 19);

	//Using user input to get the data
	printf("Search Name: ");
	scanf("%[^\n]", target);
	HashTableSearch(target);
	
	//Showing all the data on the HashTable
	printf("Target List:\n");
	printf("---------------------------------\n\n");
	PrintHashTable();
}