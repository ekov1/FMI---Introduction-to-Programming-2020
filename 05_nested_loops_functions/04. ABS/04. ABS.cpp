// Да се напише функция, която връща абсолютната стойност на дадено число.
#include <iostream>

double ABS(double x);

int main()
{
	double n;
	std::cin >> n;
	std::cout << ABS(n) << std::endl;
}

double ABS(double x)
{
	if (x < 0) {
		x = -x;
	}
	return x;
}