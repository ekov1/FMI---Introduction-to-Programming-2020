﻿// Напишете програма, която намира сумата на първите n естествени числа.
// Можем ли без цикъл ?
#include <iostream>

//n(n+1) / 2
int main()
{
	int n;
	std::cin >> n;
	std::cout << (n * (n + 1)) / 2;
}