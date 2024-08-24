#include <iostream>
#include <queue>

int main(void)
{
	// ****************************************************************
	
	// Queue = FIFO data structures, First-In First-Out (ex. A Line of people)
	//		   A collection designed for holding elements prior to processing
	//         Linear Data Structures
	
	//			add    			= enqueue, push();
	//			remove 			= dequeue, pop();
	//			queue1.swap()   = swap the value like the Stack
	//			front()  		= accessing the front (the head)
	// 			back()   		= accessing the back (the tails)
	// 			empty()			= check empty (return bool)
	//			size()			= check size (return int)
	
	// ****************************************************************
	
	std::cout << "Swap Example: " << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	
	auto SwapExample = []()
	{
		std::queue<std::string> firstQ;
		std::queue<std::string> secondQ;
		
		firstQ.push("Udyn");   //head
		firstQ.push("Joejoe");
		firstQ.push("Bernut");
		firstQ.push("Tewwy");  //tails
			
		secondQ.push("Bondan"); //head
		secondQ.push("Smem");
		secondQ.push("DerrEnd");
		secondQ.push("Niko");	//tails
		
		firstQ.swap(secondQ);	
		
		std::cout << "First Queue: " << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
			
		while(!firstQ.empty())
		{
			std::cout << "Heads: " << firstQ.front() << ", Tails: " << firstQ.back() << std::endl;
			firstQ.pop();
		}
		
		std::cout << std::endl;
		std::cout << "Second Queue: " << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		
		while(!secondQ.empty())
		{
			std::cout << "Heads: " << secondQ.front() << ", Tails: " << secondQ.back() << std::endl;
			secondQ.pop();
		}
	};
	SwapExample();
	
	std::cout << std::endl;
	std::cout << "################################################" << std::endl;
	std::cout << "################################################" << std::endl;
	std::cout << std::endl;
	std::cout << "Queue Example: " << std::endl;
	std::cout << "------------------------------------------------" << std::endl << std::endl;
	
	auto QueueExample = []()
	{
		std::queue<std::string> queue;
		
		queue.push("Udyn");
		queue.push("Joejoe");
		queue.push("Bernut");
		queue.push("Tewwy");
		
		while(!queue.empty())
		{
			std::cout << "Heads: " << queue.front() << ", Tails : " << queue.back() << std::endl;
			queue.pop();
		}		
	};
	QueueExample();

	// ******************************************************************
	
	// Uses of Queue?
	
	// 1. Keyboard Buffer (Letters should appear on the screen in order they're pressed)
	// 2. Printer Queue (Print jobs should be completed in order)
	// 3. Used in LinkedLists, PriorityQueues, Breadth-first Search 	
	
	// ******************************************************************
}