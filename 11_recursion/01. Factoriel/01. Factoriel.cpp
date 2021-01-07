// 01. Factoriel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;

 unsigned long long Factorial(unsigned long long n);

int main()
{
	cout<<Factorial(5);
}

unsigned long long Factorial( unsigned long long n) {
	if (n == 1)
	{
		return 1;

	}
	return n * Factorial(n - 1);
}