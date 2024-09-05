#include <stdio.h>

void Recursion(int x);
int Factorial(int x);
int Power(int base, int exponent);
int OptPower(int base, int exponent);

int main(void)
{
	//***************************************
	
	//Recursion = is a function that calls itself
	//			  recursion can be used as a stack
	//			  because it's algorithm is LIFO
	//			  (Last In First Out)
	
	//				Advantages
	//				------------------------
	//				easier to read/write
	//				easier to debug
	
	//				Disadvantages
	//				------------------------
	//				sometimes slower
	//				uses more memory
	
	//***************************************
	
	printf("First Recursion Example: \n");
	Recursion(5); //Recursion example
	
	printf("\n-----------------------------------------------");
	printf("\nFactorial Example with recursion: \n");
	printf("%d", Factorial(5)); // example in factorial
		
	printf("\n-----------------------------------------------");
	printf("\nPower Example with recursion: \n");
	printf("%d", Power(2, 8)); // example in Power
		
	printf("\n-----------------------------------------------");
	printf("\nOptimized Power Example with recursion: \n");
	printf("%d", OptPower(2, 8)); // example in Optimized Power
	
}

int OptPower(int base, int exponent) // O(log n)
{
	if(exponent == 0) return 1;
	if(exponent % 2 == 0)
	{
		int halfPower = Power(base, exponent / 2);
		return halfPower * halfPower;
	}else
	{
		return base * Power(base, exponent - 1);
	}
}

int Power(int base, int exponent) // O(n)
{
	if(exponent < 1) return 1;
	return base * Power(base, exponent - 1);
}

int Factorial(int x)
{
	if(x < 1) return 1;
	return x * Factorial(x - 1);
}

void Recursion(int x)
{
	if(x == 0)
	{
		printf("\n");
		return;
	}
	
	printf("%d", x); //descending order
	
	Recursion(x - 1);
	
	printf("%d", x); //ascending order
}