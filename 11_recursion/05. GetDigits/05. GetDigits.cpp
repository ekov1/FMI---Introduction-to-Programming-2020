// 05. GetDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void GetDigits(unsigned n);
int main()
{
	GetDigits(2345);
	GetDigits(35897);
}

void GetDigits(unsigned n) {
	unsigned digit = n % 10;
	n /= 10;

	if (n == 0)
	{
		std::cout << digit<<" ";
		return;
	}
	else {
		GetDigits(n);
	}
	
	std::cout <<digit<<" ";
}

