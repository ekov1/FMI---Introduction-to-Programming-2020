// 05. ReverseDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void ReverseDigits(unsigned n);
int main()
{
	ReverseDigits(2345) ;
	std::cout << std::endl;
	ReverseDigits(35897);
}

void ReverseDigits(unsigned n) {
	unsigned digit = n % 10;
	std::cout << digit << " ";
	n /= 10;

	if (n == 0)
	{
		return;
	}
	
		ReverseDigits(n);

	
}

