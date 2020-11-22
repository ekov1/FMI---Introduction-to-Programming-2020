// По въведено цяло положително число N програмата да прочита N на брой 
// цели числа, а след това да отпечатва сумата от цифрите им.

// Пример:

// Вход:  3
// 11 255 42
// Изход : 20 // 1 + 1 + 2 + 5 + 5 + 4 + 2

#include <iostream>

unsigned SumOfDigits(unsigned n);

int main()
{
	unsigned n, sum = 0, num;

	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> num;
		sum += SumOfDigits(num);
	}

	std::cout << "sum = " << sum << std::endl;
}

unsigned SumOfDigits(unsigned n) {
	unsigned sum = 0, digit;


	while (n != 0)
	{
		digit = n % 10;
		sum += digit;
		n /= 10;
	}

	return sum;
}