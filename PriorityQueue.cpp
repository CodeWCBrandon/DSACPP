#include <iostream>
#include <queue> //priority queue is also in queue header

struct Person //using custom objects
{
	std::string name;
	int age;	
	
	//the comparator operator is needed in queue header
	//to compare the priorities based on the age	
	bool operator<(const Person& other) const
	{
		return age < other.age; // descending order
	  //return age > other.age; // ascending order
	}
};

int main(void)
{
	// ****************************************************************
	
	// Priority Queue = FIFO data structures, First-In First-Out
	//		  			that serves elements with the highest priorities
	//         			first before the elements with lower priorites
	
	//			add    			= enqueue, push();
	//			remove 			= dequeue, pop();
	//			pQueue1.swap()  = swap the value like the Stack
	//			top()  			= accessing the top (the highest priorities)
	// 			empty()			= check empty (return bool)
	//			size()			= check size (return int)
	
	// ****************************************************************
	
	std::cout << "Using Custom Object Example: " << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	
	auto UsingCustomObjectsExample = [](){
		std::priority_queue<Person> pQueue;
		
		pQueue.push({"John", 50});
		pQueue.push({"Smem", 17});
		pQueue.push({"Roberto", 20});
		pQueue.push({"Wolf", 30});
		pQueue.push({"Owl", 60});
		
		while(!pQueue.empty())
		{
			std::cout << "Name: " << pQueue.top().name << ", Age: " << pQueue.top().age << std::endl;
			pQueue.pop();
		}
	};
	UsingCustomObjectsExample();
	
	std::cout << std::endl;
	std::cout << "################################################" << std::endl;
	std::cout << "################################################" << std::endl << std::endl;
	std::cout << "Swap Example: " << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	
	
	auto SwapExample = [](){
		std::priority_queue<double> pQueue1;
		std::priority_queue<double> pQueue2;
		
		pQueue1.push(3.4);
		pQueue1.push(7);
		pQueue1.push(2.8);
		pQueue1.push(5);
		
		pQueue2.push(1.4);
		pQueue2.push(8.2);
		pQueue2.push(3.4);
		pQueue2.push(2.3);
		
		pQueue1.swap(pQueue2);
		
		std::cout << "pQueue1 :" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		
		while(!pQueue1.empty())
		{
			std::cout << "Value: " << pQueue1.top() << std::endl;
			pQueue1.pop();
		}
		
		std::cout << std::endl;
		std::cout << "pQueue2 :" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		
		while(!pQueue2.empty())
		{
			std::cout << "Value: " << pQueue2.top() << std::endl;
			pQueue2.pop();
		}
	};
	SwapExample();
	
	std::cout << std::endl;
	std::cout << "################################################" << std::endl;
	std::cout << "################################################" << std::endl;
	std::cout << std::endl;
	std::cout << "Priority Queue Example: " << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	
	auto PriorityQueueExample = [](){
		std::priority_queue<double> pQueue;
		
		pQueue.push(3.0);
		pQueue.push(2.7);
		pQueue.push(3.9);
		pQueue.push(4.0);
		pQueue.push(1.3);
		
		while(!pQueue.empty())
		{
			std::cout << "value: " << pQueue.top() << std::endl;
			pQueue.pop();
		}		
	};
	PriorityQueueExample();
	
	// ******************************************************************
	
	// Uses of Priority Queue?
	
	// 1. Search Algorithm (like google)
	// 2. used in Dijkstra's Shortest path algorithm, Prim's algorithm, Huffman Coding,
	// 3. Operating System (task scheduling, load balancing, intterupt handling, etc)
	
	// ******************************************************************
	
}