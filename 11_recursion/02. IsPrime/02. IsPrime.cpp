// 02. IsPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool IsPrime(unsigned n, int numToCheckWith = 2);

int main()
{
	std::cout << IsPrime(13);
	std::cout << IsPrime(5);
	std::cout << IsPrime(121);
	std::cout << IsPrime(19);


}

bool IsPrime(unsigned n, int numToCheckWith) {
	if (n == 0 || n == 1)
	{
		return false;
	}

	if (n % numToCheckWith == 0)
	{
		return false;
	}

	if (numToCheckWith == sqrt(n)) {
		if (n % numToCheckWith == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}

	if (numToCheckWith > sqrt(n))
		return true;

	IsPrime(n, numToCheckWith + 1);
}