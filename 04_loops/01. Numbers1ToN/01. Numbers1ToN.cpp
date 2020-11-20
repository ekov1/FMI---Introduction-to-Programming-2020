// Напишете програма, която принтира числата от 1 до n, обградени в квадратни скоби.

#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	for (size_t i = 1; i <= n; i++)
	{
		std::cout << "[" << i << "]";
	}

}