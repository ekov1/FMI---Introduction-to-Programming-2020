// Функция, която връща n-тото число на Фибоначи.

#include <iostream>

bool IsPrime(int x);

int main()
{
	int n;
	std::cin >> n;
	std::cout << (IsPrime(n) ? "prime" : "not prime");
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