// 06. SumAndProduct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void ReadInputAdCalculate(int arr[], unsigned& n, int& sum, int& product);

int main()
{
	unsigned n;
	int arr[1024];
	int sum = 0, product = 1;

	ReadInputAdCalculate(arr, n, sum, product);
	std::cout << "sum = " << sum << " product = " << product << std::endl;
}

void ReadInputAdCalculate(int arr[], unsigned& n, int& sum, int& product) {
	std::cout << "Enter arr size : ";
	std::cin >> n;

	std::cout << "Enter arr elements" << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		sum += arr[i];
		product *= arr[i];
	}
}