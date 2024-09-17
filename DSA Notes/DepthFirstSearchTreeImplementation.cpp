#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
	int value;
	Node* left;
	Node* right;
};

void AddNode(Node* root, int value)
{
	//Creating newNode
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	//Creating a temp node
	Node* curr = root;
	
	//traversing the node
	while(curr != NULL)
	{
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

//---------------------DEPTH FIRST SEARCH IMPLEMENTATION------------------------------
void PreOrderPrint(Node* root)
{
	printf("PreOrder Value: %d\n", root->value);
	
	if(root->left != NULL) PreOrderPrint(root->left);
	if(root->right != NULL) PreOrderPrint(root->right);
	
	return;
}

void InOrderPrint(Node* root)
{
	if(root->left != NULL) InOrderPrint(root->left);
	printf("InOrderPrint Value: %d\n", root->value);
	if(root->right != NULL) InOrderPrint(root->right);
	
	return;
	
}

void PostOrderPrint(Node* root)
{
	if(root->left != NULL) PostOrderPrint(root->left);
	if(root->right != NULL) PostOrderPrint(root->right);
	
	printf("PostOrder Value: %d\n", root->value);
	
	return;
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
	
	//DFS Test
	printf("-------------PreOrder-------------\n");
	PreOrderPrint(root);
	printf("-------------InOrder-------------\n");
	InOrderPrint(root);
	printf("-------------PostOrder-------------\n");
	PostOrderPrint(root);
	
}