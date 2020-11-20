// Да се напише програма, която приема цяло положително 4-байтово число
// като вход и принтира цифрите му в обратен ред.

#include <iostream>

int main()
{
	unsigned n;
	std::cin >> n;
	unsigned reverced = 0;
	while (n != 0)
	{
		unsigned remainder = n % 10;
		reverced = reverced * 10 + remainder;
		n = n / 10;
	}
	std::cout << reverced;
}

