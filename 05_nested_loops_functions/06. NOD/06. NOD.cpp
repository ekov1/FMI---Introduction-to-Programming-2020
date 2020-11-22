// Да се напише функция, която връща НОД на две цели числа.

#include <iostream>

int NOD(int n, int k);

int main()
{
	int k, n;
	std::cout << "enter two numbers" << std::endl;
	std::cin >> n >> k;
	std::cout << NOD(n,k);
}

int NOD(int n, int k) {
	int nod = 1;
	int start;
	if (k > n) {
		start = n;
	}
	else {
		start = k;
	}

	for (size_t i = start; start >= 1; i--)
	{
		if (n % i == 0 && k % i == 0)
		{
			nod = i;
			break;
		}
	}
	return nod;
}

