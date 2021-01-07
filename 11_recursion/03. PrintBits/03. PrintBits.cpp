// 03. PrintBits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;


void PrintBits(unsigned n, unsigned position = 31);

int main()
{
	PrintBits(8);
	PrintBits(10);

}

void PrintBits(unsigned n, unsigned position) {

	unsigned bit = (n & (1 << position)) >> position;
	cout << bit;

	if (position == 0)
	{
		return;
	}
	PrintBits(n, position - 1);
}
