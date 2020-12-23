// 05. Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;


void f(int* arr1, const int* arr2)
{
	int* p1 = arr1;
	const int* p2 = arr2;

	while (*p2 >= 0)
	{
		*p1++ = *p2++;
	}
}

void main()
{

	int A[4] = { -1, -2, -3, -4 };
	int B[4] = { 10, 20, 30, -1 };
	for (size_t i = 0; i < 4; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < 4; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	f(A, B);
	cout << endl;

	// На колко са равни елементите на A и B?

	for (size_t i = 0; i < 4; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;


	for (size_t i = 0; i < 4; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

}


- 1 - 2 - 3 - 4
10 20 30 - 1

10 20 30 - 4
10 20 30 - 1

