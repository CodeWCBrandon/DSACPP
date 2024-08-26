#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
	for(const T& x : vec)
	{
		os << x << " ";
	}
	return os;
}

int main(void)
{
	//*******************************************************************
	
	//Dynamic Array = An array that can be resized automatically based on user needs
	
	//				How to Create Dynamic Array in CPP?
	//				  		We Used std::Vector
	
	// Capacity
	
	//	.empty()           = to checks whether the container is empty or not
	//  .size()            = returns the number of elements
	//  .max_size() 	   = returns the maximum possible number of elements
	//  .reserve(new_cap)  = allocate some memory so the vector doesn't make other copy 
	//						 everytime the value reached the max capacity
	
	// Iterators
	
	// .begin() = return an iterator to the beginning
	// .end()   = return an interator to the end
	
	// Modifiers
	
	// .push_back(value)    		 		 = add elements to the end
	// .emplace_back(value)					 = add elements to the end 
	//										   without making another copy use emplace if possible
	// .insert(iterator pos, value)   		 = inserts elements
	// .erase(iterator pos) 		 		 = erase elements
	// .pop_back()					 		 = removes the last elements
	// std::vector.swap(std::vector) 		 = swap between vectors
	
	//*******************************************************************	
	
	std::vector<int>* arrayList = new std::vector<int>();
	
	arrayList->reserve(10); // reserve some memory (it's okay if you have an array of size 11)
							// but it'll reserve a size of 10 at the start, so it'll make 1 copy
							// instead of 10 copy
	
	arrayList->push_back(20); // Add elements to the end
	arrayList->push_back(30);
	arrayList->push_back(50);
	
	std::cout << *arrayList << std::endl;
	
	arrayList->insert(arrayList->begin() + 2, 40); // insert the value in the arrayList[2]
	
	std::cout << *arrayList << std::endl;
	
	arrayList->erase(arrayList->begin()); // erase the the value of arrayList[0]
	
	std::cout << *arrayList << std::endl;
	
	arrayList->pop_back(); // removes the last elements
	
	std::cout << *arrayList << std::endl;
	
	arrayList->emplace_back(80); // example of using emplace back
	arrayList->emplace_back(90);
	arrayList->emplace_back(100);
	arrayList->emplace_back(110);
	
	std::cout << *arrayList << std::endl;
	
	std::cout << arrayList->size() << std::endl; //check size
	
	delete arrayList; // don't forget to free the memory :)
	
	
	// ******************************************************************
	
	// Advantanges using Dynamic Array?
	
	// 1. Random Access Elements O(1)
	// 2. Good Locality of reference and data cache utilization
	// 3. Easy to insert/delete at the end
	
	// Disadvantages using Dynamic Array?
	
	// 1. Wastes more memory
	// 2. Shifting elements is time consuming O(n)
	// 3. Expanding/Shrinking the array is time consuming O(n)
	
	// ******************************************************************
	
}