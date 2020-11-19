// Да се прочетат две цели числа и да се отпечата по - голямото от тях.

#include <iostream>

int main()
{
	int x, y, big;
	std::cin >> x >> y;

	if (x > y) {
		big = x;
	}
	else {
		big = y;
	}

	std::cout << big << "\n";
}

