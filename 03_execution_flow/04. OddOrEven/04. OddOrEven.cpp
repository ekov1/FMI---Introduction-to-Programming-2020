// Напишете програма, която прочито цяло число и проверява дали то е четно или нечетно.

#include <iostream>

int main()
{
	int x;
	std::cin >> x;

	if (x % 2==0) {
		std::cout << "even";
	}
	else {
		std::cout << "odd";
	}
}