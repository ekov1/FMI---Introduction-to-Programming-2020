// Напишете функция, която по въведени цели положителни числа a, b(b > a)
// да върне сумата на всички прости числа в интервала[a;b].
// 
// Пример:
// 
// Вход:  2 10
// Изход : 17 // 2+3+5+7

#include <iostream>

bool IsPrime(int x);
int GetPrimesSum(int n, int k);

int main()
{
	int k, n;
	std::cout << "enter two numbers" << std::endl;
	std::cin >> n >> k;

	std::cout <<  "sum = " << GetPrimesSum( n,k);
}

int GetPrimesSum(int n, int k) {
	int sum = 0;
	for (size_t i = n; i < k; i++)
	{
		if (IsPrime(i))
		{
			sum += i;
		}
	}
	return sum;
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
