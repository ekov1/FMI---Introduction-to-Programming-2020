// 05. IstTiangle.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	bool result = false;

	if (a + b > c && a + c > b && b + c > a) {
		result = true;
	}

	if (result) {
		std::cout << "sides make triangle";
	}
	else {
		std::cout << "no triangle possible";
	}

}
