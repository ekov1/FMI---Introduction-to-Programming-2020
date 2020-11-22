//По въведено цяло положително число N програмата да отпечатва всичките му прости делители разделени с интервали.
//
//Пример:
//
//Вход:  990
//Изход : 2 3 3 5 11
#include <iostream>

bool IsPrime(int x);

int main()
{
	unsigned n;
	std::cin >> n;

	for (size_t i = 1; i < sqrt(n + 1); i++)
	{
		if (IsPrime(i) && n % i == 0)
		{
			std::cout << i << " ";
		}
	}
}

bool IsPrime(int x) {
	bool isPrime = true;

	for (size_t i = 2; i < sqrt(x + 1); i++)
	{
		if (x % i == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
}