#include <iostream>

class Node
{
	public:
		int value;
		Node *next; // store the next address
};

void PrintList(Node *n)
{
	while(n != nullptr) // loop until the n is equal to null aka the tail
	{
		std::cout << n->value << std::endl; //print the value in the node address
		n = n->next; //set the Node Address to the next one
	}
}

void InsertAtTheFront(Node*& head, int newValue)
{
	//things to do:
	//1. Prepare a newNode
	Node *newNode = new Node();
	newNode->value = newValue;
	
	//2. Put it infront of current head
	newNode->next = head;
	
	//3. Move head of the list to point to the newNode
	head = newNode;
}

void InsertAtTheBack(Node*& head, int newValue)
{
	//things to do:
	//1. Prepare a newNode
	Node *newNode = new Node();
	newNode->next = nullptr;
	newNode->value = newValue;
	
	//2. if linked list is empty, newNode will be a head node
	if(head == nullptr)
	{
		head == newNode;
		return;
	}
	
	//3. find the last node
	//you make a temp node just so you're not gonna change the head->next
	//because it was passed by reffrence which can affect the original value
	Node *temp = head;
	while(temp->next != nullptr)
	{
		temp = temp->next;
	}
	
	//4. Insert newNode after the last node(at the end)
	temp->next = newNode;
}

void InsertAfter(Node* prevNode, int newValue)
{
	//things to do:
	// 1. Check if the previous Node is NULL
	if(prevNode == nullptr)
	{
		std::cout << "previous Node Cannot be NULL" << std::endl;
		return;
	}
	
	// 2. Prepare a New Node
	Node* newNode = new Node();
	newNode->value = newValue;	
	newNode->next = prevNode->next;
	
	// 3. Insert newNode after previous
	prevNode->next = newNode;
}

// Delete a node with a given key
void DeleteNode(Node*& head, int key)
{
	//things to do: 
	// 1. Store Head Node
	Node* temp = head; //create a new temp Node
	Node* prev = nullptr; // create a prev node
	
	// 2. Check if the head node itself holds the key
	if(temp != nullptr && temp->value == key)
	{
		head = temp->next; // Change the head location
		delete temp; // Delete the previous head
		return;
	}
	
	// 3. Search for the key to be Deleted
	while(temp != nullptr && temp->value != key)
	{
		prev = temp;
		temp = temp->next;
	}
	
	// 4. If the key wasn't found
	if(temp == nullptr)
	{
		return;
	}
	
	// 5. Unlink the Node from linked list
	prev->next = temp->next;
	
	// 6. Free Memory
	delete temp;
}

int main(void)
{
	//*******************************************************
	
	//Singly Linked list = is a list that contains 2 value: the first value is
	// 				   	   the value, and the second one is the address of the 
	//					   next value
	
	//					   Singly Linked List
	//			Node			  Node			    Node
	//		[data|address] -> [data|address] -> [data|address] -> null
	
	//*******************************************************
	
	Node *head = new Node(); // creating the first node
	Node *second = new Node(); // second node
	Node *third = new Node(); // third node
	
	head->value = 10; // set the head value manually
	second->value = 15; // set the second value manually
	third->value = 20; // set the third value manually
	
	head->next = second; // manually set the address of the head list
	second->next = third; // manually set the address of the second list
	third->next = nullptr; // manually set the address of the third list
	
	InsertAtTheFront(head, -1); // we're passing the address of head pointer &(*head)
	InsertAtTheBack(head, 40); // we're also passing the address of head pointer &(*head)
	InsertAfter(second, 500); // we're passing the copy of address second
	DeleteNode(head, 40); // we're deleting the node with a value of 40
	
	PrintList(head);
	
	// ******************************************************************
	
	// Uses of Linked List?
	
	// 1. Using Stack, Queues, Graphs
	// 2. Dynamic Memory Allocation
	// 3. Image Viewer (the previous image and next image is the implementation of doubly linked list)
	
	// ******************************************************************
}