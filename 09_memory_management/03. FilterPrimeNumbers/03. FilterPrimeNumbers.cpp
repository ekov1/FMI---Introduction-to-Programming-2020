// 03. FilterPrimeNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::endl;

void PrintArray(unsigned array[], unsigned size);
void ArrayRemoveAt(unsigned*& array, unsigned& size, unsigned position);
bool IsPrime(unsigned n);
void FilterPrimes(unsigned*& arr, unsigned& size);

int main()
{
	unsigned size = 7;
	unsigned* arr = new unsigned[] {5, 55, 22,53,61, 111, 3, 7};
	PrintArray(arr, size);
	FilterPrimes(arr, size);
	PrintArray(arr, size);

	delete[] arr;
	return 0;
}

// removes element from array at given position
void ArrayRemoveAt(unsigned*& array, unsigned& size, unsigned position) {
	unsigned* tempArr = new unsigned[size - 1];

	for (unsigned i = 0; i < position; i++)
	{
		tempArr[i] = array[i];
	}

	for (unsigned i = position + 1; i < size; i++)
	{
		tempArr[i - 1] = array[i];
	}

	delete[] array;
	array = tempArr;
	size--;
}

void PrintArray(unsigned array[], unsigned size) {
	for (unsigned i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

bool IsPrime(unsigned n) {
	if (n == 0 || n == 1)
	{
		return 0;
	}

	bool isPrime = 1;

	for (unsigned i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			isPrime = 0;
		}
	}

	return isPrime;
}

void FilterPrimes(unsigned*& arr, unsigned& size) {
	for (size_t i = 0; i < size; i++)
	{
		if (!IsPrime(arr[i]))
		{
			ArrayRemoveAt(arr, size, i);
			i--;
		}
	}
}