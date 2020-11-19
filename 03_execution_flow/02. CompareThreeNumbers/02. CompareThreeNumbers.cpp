// Да се прочетат три цели положителни числа и да се отпечата най-голямото от тях.

#include <iostream>

int main()
{
	unsigned x, y, z, big;
	std::cin >> x >> y >> z;

	if (x > y) {
		big = x;
	}
	else {
		big = y;
	}

	if (z > big) {
		big = z;
	}

	std::cout << big << "\n";
}