#include <iostream>

class Node
{
	public:
		int value;
		Node* prev;
		Node* next;
};

void PrintList(Node* startingPoint, int isForward = 1)// if forward using int 0 / 1 (0 = backward, 1 = forward)
{
	if(isForward == 1) // if forward
	{
		while(startingPoint != nullptr)
		{
			std::cout << startingPoint->value << std::endl;
			startingPoint = startingPoint->next;
		}
		return;
	}
	
	if(isForward == 0) // if backward
	{
		while(startingPoint != nullptr)
		{
			std::cout << startingPoint->value << std::endl;
			startingPoint = startingPoint->prev;
		}
		return;
	}
}

void InsertAtFront(Node*& head, int value)
{
	//things to do:
	//1. Prepare a newNode
	Node* newNode = new Node();
	newNode->value = value;
	
	//2. Put it infront of the head node
	newNode->prev = nullptr;
	newNode->next = head;
	
	//3. Set the previous head to point to the newNode
	head->prev = newNode;
	
	//4. Change the head into newNode
	head = newNode;
}

void InsertAtBack(Node*& tail, int value)
{
	//things to do:
	//1. Prepare a newNode
	Node* newNode = new Node();
	newNode->value = value;
	
	//2. Put it infront of the tail node
	newNode->prev = tail;
	newNode->next = nullptr;
	
	//3. Set the previous tail to point to the newNode
	tail->next = newNode;
	
	//4. Change the tail into newNode
	tail = newNode;
}

void InsertAfter(Node* prevNode, int value)
{
	//things to do:
	//1. Check if the Previous Node is NULL
	if(prevNode == nullptr)
	{
		std::cout << "prevNode can't be NULL" << std::endl;
		return;
	}
	
	//2. Prepare a New Node
	Node* newNode = new Node();
	newNode->value = value;
	newNode->next = prevNode->next;
	newNode->prev = prevNode;
	
	//3. Insert a New Node after previous
	prevNode->next = newNode;
}

void InsertBefore(Node* nextNode, int value)
{
	//things to do:
	//1. check if the nextNode prev is NULL
	if(nextNode->prev == nullptr)
	{
		std::cout << "nextNode prev can't be NULL" << std::endl;
		return;
	}

	//2. Prepare a New node
	Node* newNode = new Node();
	newNode->value = value;
	newNode->next = nextNode;
	newNode->prev = nextNode->prev;

	//3. Insert a New Node after previous
	nextNode->prev = newNode;

	//4. Assign the previous newNode next to point to new Node
	newNode->prev->next = newNode;
}

void DeleteNode(Node*& head, int key)
{
	//things to do:
	//1. store head Node
	Node* temp = head;

	//2. Check if the head node itself hold the key
	if(temp != nullptr && temp->value == key)
	{
		head = temp->next;
		if(head != nullptr)
		{
			head->prev = nullptr; //change the newHead prev to nullptr
		}
		delete temp;
		return;
	}

	//3. search for the key to be deleted
	while(temp != nullptr && temp->value != key)
	{
		temp = temp->next;
	}

	//4. return if the key wasn't found
	if(temp == nullptr)
	{
		std::cout << "Key wasn't found" << std::endl;
		return;
	}

	//5. unlink the node from the linked list
    if (temp->next != nullptr) // if the next is nullptr (tail)
	{
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) // if the prev is nullptr (head)
	{
        temp->prev->next = temp->next;
    }

	//6. free memory
	delete temp;
}

int main(void)
{
	//*******************************************************************
	
	//Doubly Linked list = is a list that contains 3 value: the first value is
	// 				   	   the value, and the second one is the address of the 
	//					   prev value, and the third one is the address of the 
	// 					   next value.
	
	//					  					Doubly Linked List
	//					 Node			  			Node			    	   Node
	//	null <- [address|data|address] <-> [address|data|address] <-> [address|data|address] -> null
	
	//*******************************************************************	
	
	//Manually adding Nodes
	Node *head = new Node();
	Node *second = new Node();
	Node *third = new Node();
	Node *tail = new Node();
	
	//Assigning head
	head->value = 100;
	head->prev = nullptr;
	head->next = second;
	
	//Assigning Second
	second->value = 200;
	second->prev = head;
	second->next = third;
	
	//Assigning Third
	third->value = 300;
	third->prev = second;
	third->next = tail;
	
	//Assigning Tail
	tail->value = 400;
	tail->prev = third;
	tail->next = nullptr;

	//Testing InsertAfter Function
	InsertAfter(head, 150); // pass the node by value
	InsertAfter(second, 250);
	InsertAfter(third, 350);

	//Testing InsertBefore Function
	InsertBefore(second, 175); //pass the node by value
	InsertBefore(third, 275);
	InsertBefore(tail, 375);
	
	//Testing InsertAtFront Function
	InsertAtFront(head, 50); // pass the head by reference
	InsertAtFront(head, 20);
	InsertAtFront(head, 10);
	
	//Testing InsertAtBack Function
	InsertAtBack(tail, 600); // pass the tail by reference
	InsertAtBack(tail, 700);
	InsertAtBack(tail, 800);

	//Testing DeleteNode Function
	DeleteNode(head, 700); // pass the head by reference
	DeleteNode(head, 100);
	DeleteNode(head, 200);
	
	//Printing Output
	PrintList(head); //print forward
	std::cout << "---------------------------------------" << std::endl; 
	PrintList(head, 1); //print forward using isForward Parameter
	std::cout << "---------------------------------------" << std::endl; 
	PrintList(tail, 0); //print backward using isForward Parameter
	
	
	
	// ******************************************************************
	
	// Uses of Linked List?
	
	// 1. Using Stack, Queues, Graphs
	// 2. Dynamic Memory Allocation
	// 3. Image Viewer (the previous image and next image is the implementation of doubly linked list)
	
	// Advantages of Using Doubly instead of Singly?
	
	// 1. Can go forward and backward (from head to tail, and from tail to head)
	
	// Disadvantes of Using Doubly instead of Singly?
	
	// 1. More memory
	
	// ******************************************************************
}