// Функция, която връща n-тото число на Фибоначи.

#include <iostream>

int Fibonacci(int n);

int main()
{
	int n;
	std::cin >> n;
	std::cout << Fibonacci(n);
}

int Fibonacci(int n) {
	int result=0;
	if (n == 1) {
		result = 0;
	}
	if (n == 2 || n == 3) {
		result = 1;
	}
	if (n > 3) {
		int beforeLast = 1;
		int last = 1;
		int current;
		int counter = 4;
		int temp;
		while (counter <= n)
		{
			current = last + beforeLast;
			temp = last;
			last = current;
			beforeLast = temp;
			counter++;
		}
		result = current;
	}

	return result;
}