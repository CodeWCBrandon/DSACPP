#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//---------------------------------- BST IMPLEMENTATION -----------------------------------

struct Node
{
	int value;
	Node* left;
	Node* right;
};

void AddNode(Node*& root, int value)
{	
	//creating a new Node
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	//if root is NULL
	if(root == NULL)
	{
		root = newNode;
		return;
	}
	
	//Create a temp node
	Node* curr = root;
	
	//Traverse the root
	while(curr != NULL)
	{
		if(value <= curr->value)
		{
			if(curr->left == NULL)
			{
				curr->left = newNode;
				return;
			}else
			{
				curr = curr->left;	
			}	
			
		}else
		{
			if(curr->right == NULL)
			{
				curr->right = newNode;
				return;
			}else
			{
				curr = curr->right;
			}
		}
	}
}

//Check the max value
int Max(int a, int b)
{
	return (a > b) ? a : b;
}

//Root itself isn't printed
void PostOrderPrint(Node* root)
{
	if(root->left != NULL) PostOrderPrint(root->left);
	if(root->right != NULL) PostOrderPrint(root->right);
	
	printf("value: %d\n", root->value);
	
	return;
}

//Searching a value in a binary tree
void Search(Node* root, int target)
{
	Node* curr = root;
	
	while(curr != NULL)
	{
		if(target == curr->value)
		{
			printf("%d Found\n", target);
			return;
		}else if(target < curr->value)
		{
			curr = curr->left;
		}else
		{
			curr = curr->right;
		}
	}
	
	printf("%d is not Found\n", target);
}

//Root itself is printed
void PreOrderPrint(Node* root)
{
	printf("value: %d\n", root->value);
	
	if(root->left != NULL) PreOrderPrint(root->left);
	if(root->right != NULL) PreOrderPrint(root->right);
	
	return;
}

//--------------------- BREATH FIRST SEARCH ALGORITHM -----------------------------

//Check the height of the tree
int CheckHeight(Node* root)
{
	if(root == NULL) return 0;
	int leftHeight = CheckHeight(root->left);
	int rightHeight = CheckHeight(root->right);
	
	return Max(leftHeight, rightHeight) + 1;
}

//Print everything in current level
void PrintCurrentLevel(Node* root, int level)
{
	if(root == NULL) return;
	if(level == 1)
	{
		printf("%d ", root->value);
	}else if(level > 1)
	{
		PrintCurrentLevel(root->left, level - 1);
		PrintCurrentLevel(root->right, level - 1);
	}
}

//BFS
void BFS(Node* root, int height)
{
	for(int i = 1; i <= height; i++)
	{
		PrintCurrentLevel(root, i);
		printf("\n");
	}
}


int main(void)
{
	srand(time(NULL));
	
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = rand() % 10;
	root->left = NULL;
	root->right = NULL;
	
	printf("Root: %d\n", root->value);
	for(int i = 0; i < 10; i++)
	{
		int inputValue = rand() % 10;
		AddNode(root, inputValue);
		printf("Input: %d\n", inputValue);
	}
	printf("\n");
	
	PreOrderPrint(root);
	Search(root, 14);
	printf("Height: %d\n", CheckHeight(root));
	printf("----------BFS--------\n");
	BFS(root, CheckHeight(root));
}