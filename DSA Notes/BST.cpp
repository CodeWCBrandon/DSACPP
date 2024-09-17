#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG_MODE 1

#if DEBUG_MODE == 1
#define Debug(x, arg) printf(x, arg)
#elif DEBUG_MODE == 0
#define Debug(x, arg)
#endif

struct Node
{
	int value;
	Node* left;
	Node* right;
};

void AddNode(Node*& root, int value)
{
	//Creating a new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	//Setup the new node
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	//Check if the root exist
	if(root == NULL)
	{
		root = newNode;
		return;
	}
	
	//creating a current node that traverse between the root node
	Node* curr = root;
	
	//traverse the root node
	while(curr != NULL)
	{
		//check if the value is less than or greater than the current node
		if(value <= curr->value)
		{
			if(curr->left == NULL)
			{
				curr->left = newNode;
				return;
			}
			curr = curr->left;
		}else
		{
			if(curr->right == NULL)
			{
				curr->right = newNode;
				return;
			}
			curr = curr->right;
		}
	}
}

void PrintAll(Node* root)
{
	printf("%d\n", root->value);
	
	if(root->left != NULL) PrintAll(root->left);
	if(root->right != NULL) PrintAll(root->right);
	
	return;
}

void CheckValue(Node*& root, int target)
{
	//check if the root is null
	if(root == NULL)
	{
		printf("root is not found");
		return;	
	}	
	
	//creating the current node that traverse in root node
	Node* curr = root;
	
	while(curr != NULL)
	{
		Debug("current value: %d\n", curr->value);
		
		//check if the current value is equal to the target
		if(curr->value == target)
		{
			printf("%d Found", target);
			return;
		}
		else //if the current value is not equal to the target
		{
			
			//check if the value less than or greater than the current value
			if(target <= curr->value)
			{
				curr = curr->left;
			}else
			{
				curr = curr->right;
			}
		}

	}
	
	printf("%d is not found", target);
}

int Max(int a, int b)
{
	return (a > b) ? a : b;
}

//only works for the height of a binary search tree
int FindHeight(Node* root)
{
	if(root == NULL)
	{
		return -1;
	}
	
	//using recursion to check every tree 
	int leftNode = FindHeight(root->left);
	int rightNode = FindHeight(root->right);
	
	return Max(leftNode, rightNode) + 1;
}

int main(void)
{	
	srand(time(NULL));

	auto BasicUnderstanding = []()
	{
		//or you can use (if you avoiding any first value)
		//Node* root = NULL;
		
		Node* root = (Node*)malloc(sizeof(Node));
		root->value = 20;
		root->left = NULL;
		root->right = NULL;
		
		AddNode(root, 15);
		AddNode(root, 15);
		AddNode(root, 40);
		AddNode(root, 12);
		AddNode(root, 35);
		
		CheckValue(root, 40);	
	};
	//BasicUnderstanding();
	
	//Implementation in Array and searching for the lowest value or some value
	//input Array
	auto ArrayImplementationExample = [](){
		int arrSize = 100;
		int numberRange = 100;
		int inputArr[arrSize];
		printf("input Array: [");
		for(int i = 0; i < arrSize; i++)
		{
			inputArr[i] = rand() % numberRange;
			if(i == arrSize - 1)
			{
				printf("%d", inputArr[i]);
				break;
			}
			printf("%d, ", inputArr[i]);
		}
		printf("]\n");
		
		//BST Implementation
		Node* BST = (Node*)malloc(sizeof(Node));
		BST->value = inputArr[0];
		BST->left = NULL;
		BST->right = NULL;
		for(int i = 0; i < arrSize; i++)
		{
			AddNode(BST, inputArr[i]);
		}
		
		//Check Value location
		int target = 0;
		printf("Enter Target: ");
		scanf("%d", &target); getchar();
		CheckValue(BST, target);
		printf("\nTree height: %d\n", FindHeight(BST));	
		
		PrintAll(BST);
	};
	ArrayImplementationExample();
	
}