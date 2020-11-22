// Напишете функция, която връща по-голямото от две цели числа.

#include <iostream>

int MathMax(int a, int b);

int main()
{
	int a, b;
	std::cout << "enter two numbers: ";
	std::cin >> a >> b;
	std::cout << MathMax(a, b);
}

int MathMax(int a, int b) {
	int big;

	if (a > b)
	{
		big = a;
	}
	else {
		big = b;
	}

	return big;
}