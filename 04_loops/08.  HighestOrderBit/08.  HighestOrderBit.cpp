// Напишете програма, която да преброи колко единици и нули
// има в двоичното представяне на дадено цяло число.

#include <iostream>

int main()
{
	unsigned n, remainder;
	std::cin >> n;

	short i = 31;
	short bit,position;
	while (i >= 0)
	{
		bit = (n & (1 << i)) >> i;
		if (bit == 1) {
			position = i;
		}
		
		i--;
	}
	std::cout << "position = " << position ;
}
