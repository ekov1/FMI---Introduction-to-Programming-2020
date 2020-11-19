// 03. Да се прочетат три цели положителни числа и да се отпечатат във възходящ ред.

#include <iostream>

int main()
{
	unsigned x, y, z, big, medium, small;
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

	if (big == x) {
		if (z > y) {
			medium = z;
			small = y;
		}
		else {
			medium = y;
			small = z;
		}
	}
	else if (big == y) {
		if (x > z) {
			medium = x;
			small = z;
		}
		else {
			medium = z;
			small = x;
		}
	}
	else if (big == z) {
		if (x > y) {
			medium = x;
			small = y;
		}
		else {
			medium = y;
			small = x;
		}
	}

	std::cout << small << " " << medium << " " << big << "\n";
}