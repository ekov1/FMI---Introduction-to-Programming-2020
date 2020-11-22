// 01. Print triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void PrintSeven();
void PrintFive();
void PrinFour();

int main()
{
	int n;

	std::cin >> n;

	switch (n)
	{
	case 7: {
		PrintSeven();
		break;
	}
	case 5: {
		PrintFive();
		break;
	}
	case 4: {
		PrinFour();
		break;
	}
	default:
		break;
	}
}

void PrinFour() {
	int n = 4;
	int counter = 4;
	int start = 1;
	int whiteSpaceCounter = 0;
	while (counter > 0)
	{
		for (size_t i = 0; i < whiteSpaceCounter; i++)
		{
			std::cout << " ";

		}
		for (size_t i = start; i <= n; i++)
		{
			std::cout << i << " ";
		}
		for (size_t i = n; i >= start; i--)
		{
			std::cout << i << " ";
		}
		if (counter > 1)
		{
			std::cout << std::endl;
		}
		start++;
		counter--;
		whiteSpaceCounter += 2;
	}
	while (counter <= n)
	{
		for (size_t i = 0; i < whiteSpaceCounter; i++)
		{
			std::cout << " ";

		}
		for (size_t i = start; i <= n; i++)
		{
			std::cout << i << " ";
		}
		for (size_t i = n; i >= start; i--)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		start--;
		counter++;
		whiteSpaceCounter -= 2;
	}
}

void PrintFive() {
	int n = 5;
	int counter = 1;
	while (counter < n + 1)
	{
		for (size_t i = 1; i < counter + 1; i++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;
		counter++;
	}

	while (counter > 0)
	{
		for (size_t i = 2; i < counter; i++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;

		counter--;
	}
}

void PrintSeven() {
	int n = 7;
	int counter = 1;
	while (counter < n + 1)
	{
		for (size_t i = 1; i < counter + 1; i++)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		counter++;
	}
	int whiteSpaceCounter = 2;

	while (counter > 0)
	{
		for (size_t i = 0; i < whiteSpaceCounter; i++)
		{
			std::cout << " ";

		}
		for (size_t i = 2; i < counter; i++)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;

		counter--;
		whiteSpaceCounter += 2;
	}
}

