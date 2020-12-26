// 03. PrintVetorsRecirsive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int DrawNthVectors(unsigned n, unsigned vector[], unsigned index);

unsigned const n = 3;
unsigned vector[n];
unsigned vectorsCount = 0;

int main()
{
	unsigned index = 0;
	DrawNthVectors(n, vector, index);
	cout << "v count = " << vectorsCount;
}

int DrawNthVectors(unsigned n, unsigned vector[], unsigned index) {
	if (index == n)
	{
		for (size_t i = 0; i < n; i++)
		{
			cout << vector[i] << " ";
		}
		cout << endl;
		vectorsCount++;
		return 0;
	}

	for (size_t i = 0; i <= 1; i++)
	{
		vector[index] = i;
		DrawNthVectors(n, vector, index + 1);
	}
}

