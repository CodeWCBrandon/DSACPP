#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

struct Data
{
	const char *name;
	unsigned int age;
};

// Hash table (Global Scope)
Data* hashTable[TABLE_SIZE];

unsigned int Hash(const char* key)
{
	// Get the string from the data
	int length = strlen(key);
	
	// Hashvalue for the key
	unsigned int hashValue = 0;
	
	// creating a key (randomness)
	for(int i = 0; i < length; i++)
	{
		hashValue += key[i];
		hashValue = (hashValue * key[i]) % TABLE_SIZE;
	}
	
	// Return the hash key
	return hashValue;
}

void HashTableLook(const char* key)
{
	//hash the dat into index
	int index = Hash(key);
	
	//check if the location is found or not
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		int probeIndex = (index + i) % TABLE_SIZE;

		if(strcmp(hashTable[probeIndex]->name, key) == 0)
		{
			printf("%s found\n", key);
			return;
		}
	}
	
	printf("%s is not found]\n", key);
}

void HashTableDelete(const char* key)
{
	//hash the dat into index
	int index = Hash(key);
	
	//check if the location is found or not
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		int probeIndex = (index + i) % TABLE_SIZE;
		
		if(strcmp(hashTable[probeIndex]->name, key) == 0)
		{
			printf("%s deleted\n", key);
			hashTable[probeIndex] = NULL;
			return;
		}
	}
	
	printf("%s as a delete key not found!!\n", key);
}

void InitHashTable()
{
	//Set the table to NULL
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}

void PrintTable()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(hashTable[i] == NULL)
		{
			// \t for tab
			printf("\t%i\t---------\n", i);	
		}else
		{
			printf("\t%i\t%s\t\t%u\n", i, hashTable[i]->name, hashTable[i]->age);
		}
	}
}

void HashTableInsert(Data* dat)
{
	//if data NULL
	if(dat == NULL) return;
	
	//Hashing for the index
	int index = Hash(dat->name);
	
	// **LINEAR PROBING IMPLEMENTATION**
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		//Check the empty space
		int empty = (i + index) % TABLE_SIZE;
		if(hashTable[empty] == NULL)
		{
			//Assign the data
			hashTable[empty] = dat;
			return;
		}
	}
	
	//if the table size is not enough
	printf("Table size limit exceeded\n");
}

void PrintKey(const char* key)
{
	// Create an index using key
	int index = Hash(key);
	
	// if the key is found
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		// calculate the current index
		int probeIndex = (index + i) % TABLE_SIZE;
		
        if (strcmp(hashTable[probeIndex]->name, key) == 0)
        {
            // If the key is found, print a message and return
            printf("Name: %s, Age: %d\n", hashTable[probeIndex]->name, hashTable[probeIndex]->age);
            return;
        }
	}
	
	printf("%s is not found\n", key);
}

int main(void)
{
	//*************************************************
	
	// Hashtable = A Data Structure that stores unique keys to values ex. <Key, value>
	//			   Each key/value pair is known as an Entry
	//			   Fast insertion, look up, deletion of key/value pairs
	//			   Not ideal for small data sets, great with large data sets
	
	// Hashing = takes a key computes an int
	//			 in HashTable, we use hash % capacity to calculate the index number
	
	//			 hashCode % capacity = index
	
	// Bucket = an indexed storage location for one or more Entries
	//			can store multiple Entries in case of a Collision (linked similarly a LinkedList)
	
	// Collision = hash function generates the same index for more than one entry
	//			   less collision = more effecient
	
	//*************************************************
	
	// 			Ways to fix the collision in HashTable??
	
	//			1. Seperate Chaining
	//			2. Open Addressing
	//			   - linear probing
	//			   - quadratic probing
	//			   - double hashing
	//			3. Robin Hood Hashing
	
	// At This moment we use Linear Probing
	
	//*************************************************
	
	// in C++ we use std::map as a HashTable
	
	// But we're gonna make it from scratch using C
	
	//*************************************************
	
	InitHashTable();
	
	Data p1 = {.name = "joe", .age = 200};
	Data p2 = {.name = "jojo", .age = 12};
	Data p3 = {.name = "udyn", .age = 18};
	Data p4 = {.name = "john", .age = 20};
	Data p5 = {.name = "chris", .age = 12};
	Data p6 = {.name = "some", .age = 18};
	Data p7 = {.name = "ppl", .age = 20};
	Data p8 = {.name = "roblox", .age = 12};
	Data p9 = {.name = "justin", .age = 18};
	Data p10 = {.name = "sam", .age = 18};
	Data p11 = {.name = "dareh", .age = 18};
	
	HashTableInsert(&p1);
	HashTableInsert(&p2);
	HashTableInsert(&p3);
	HashTableInsert(&p4);
	HashTableInsert(&p5);
	HashTableInsert(&p6);
	HashTableInsert(&p7);
	HashTableInsert(&p8);
	HashTableInsert(&p9);
	HashTableInsert(&p10);
	
	//table limit test
	HashTableInsert(&p11);
	
	PrintKey("ppl");
	
	HashTableLook("sam");	
	HashTableDelete("joe");
	
	PrintTable();
	
	
}