//Да се напише функция, която връща резултата от повдигането на дадено
// число n на степен k. (две цели положителни числа) (функцията pow)

#include <iostream>

int Pow(int n, int pow);

int main()
{
	int k, n;
	std::cout << "enter num and pow" << std::endl;
	std::cin >> n >> k;
	std::cout << Pow(n, k);
}

int Pow(int n, int pow) {
	int result = n;
	for (size_t i = 1; i < pow; i++)
	{
		result *= n;
	}
	return result;
}