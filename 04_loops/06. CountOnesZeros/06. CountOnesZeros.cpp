// Напишете програма, която да преброи колко единици и нули
// има в двоичното представяне на дадено цяло число.

#include <iostream>

int main()
{
	unsigned n, remainder;
	std::cin >> n;

	short i = 31;
	short bit, ones = 0, zeros = 0;
	while (i >= 0)
	{
		bit = (n & (1 << i)) >> i;
		if (bit == 1) {
			ones++;
		}
		else
		{
			zeros++;
		}
		i--;
	}
	std::cout << "ones = " << ones << " zeros = " << zeros;
}
