// Да се напише програма, която прочита получава цяло 
// 1положително 4-байтово число и изкарва неговото двоично представяне.

#include <iostream>

int main()
{
	unsigned n, remainder;
	std::cin >> n;

	short i = 31;
	short bit;
	while (i >= 0)
	{
		bit = (n & (1 << i)) >> i;
		std::cout << bit;
		if (i % 8 == 0) {
			std::cout << " ";
		}
		i--;
	}

	/*while (n>0)
	{
		remainder = n % 2;
		n /= 2;
		std::cout << remainder;
	}*/
}