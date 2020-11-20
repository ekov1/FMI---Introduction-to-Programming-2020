// 01. Print triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int n;
	int counter=1;
	std::cin >> n;

	while (counter < n+1)
	{
		for (size_t i = 1; i < counter+1; i++)
		{
			std::cout << i<<" ";
		}
		std::cout << std::endl;
		counter++;
	}

	while (counter >0)
	{
		for (size_t i = 0; i < counter-i; i++)
		{
			std::cout << " ";
		}
		for (size_t i = 1; i < counter; i++)
		{
			std::cout << i << " ";
		}
	}

}

