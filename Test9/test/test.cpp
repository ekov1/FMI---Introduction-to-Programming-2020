// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int A[2] = { 1,2 };
	int* p1 = A;
	

	for (size_t i = 0; i < 2; i++)
	{
		cout << A[i] << " ";
	}

	for (size_t i = 0; i < 2; i++)
	{
		cout << p1[i] << " ";
	}

}

