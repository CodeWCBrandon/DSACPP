#include <stack>
#include <iostream>

int main(void)
{
	// **********************************************************************************
	
	//Stack = is a LIFO data structure Last In First Out
	//		  stores object into a sort of "vertical tower"
	//		  push(value) to add them from the top
	//        pop() to remove them from the top
	// 		  top() to get the top value
	//		  size() to get the size
	//		  swap() to swap the value between 2 stacks using stack1.swap(stack2);
	
	// **********************************************************************************
	
	std::cout << "Swap Example: " << std::endl;
	std::cout << "-----------------------------------------------" << std::endl << std::endl;
	
	
	auto SwapValueExample = []()
	{
		std::stack<int> s1;
		std::stack<int> s2;
		
		s1.push(1);	
		s1.push(2);	
		s1.push(3);	
		s1.push(4);	//top
		
		s2.push(5);	
		s2.push(6);	
		s2.push(7);	
		s2.push(8); //top
		
		s1.swap(s2); //swapping the values
		
		while(!s1.empty())
		{
			std::cout << "s1: " << s1.top() << std::endl;	
			s1.pop();
		}	
		
		std::cout << "-----------------------------------------------" << std::endl;
		while(!s2.empty())
		{
			std::cout << "s2: " << s2.top() << std::endl;
			s2.pop();
		}
	};
	SwapValueExample();
	
	std::cout << std::endl;
	std::cout << "################################################" << std::endl;
	std::cout << "################################################" << std::endl;
	std::cout << std::endl;
	std::cout << "Stack Example: " << std::endl;
	std::cout << "-----------------------------------------------" << std::endl << std::endl;
	
	auto StackExample = []()
	{
		std::stack<std::string> stack;
		
		//std::cout << stack.empty();
		
		stack.push("Minecraft");
		stack.push("Doom eternal");
		stack.push("Valorant");
		stack.push("Sekiro");
		stack.push("Dark Souls 3"); //last in (the top)
		
		/*
		//example
		std::string darkSouls = stack.top(); //get the top
		std::cout << darkSouls <<std::endl; //print the top
		stack.pop(); //pop the top
		std::string sekiro = stack.top();
		std::cout << sekiro << std::endl;
		stack.pop();
		*/
		
		
		// print one by one
		std::cout << "elements on the stack: " << std::endl;
		while(!stack.empty())
		{
			std::cout << stack.top() << std::endl;
			stack.pop();
		}
	};
	StackExample();
	
	// ******************************************************************
	
	// Uses of Stack?
	
	// 1. Undo/Redo features in text editors
	// 2. Moving back/forward through browser history
	// 3. Backtracking algorithms (maze, file directories)
	// 4. Calling function(call stack)		
	
	// ******************************************************************
	
}