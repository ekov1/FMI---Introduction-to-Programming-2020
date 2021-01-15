#include <iostream>

using std::cout;
using std::endl;


const unsigned NUMBER_LENGTH = 4;

bool IsValid(unsigned n);
unsigned* GetDigits(unsigned n);
unsigned CountCows(unsigned a, unsigned b);
unsigned CountBulls(unsigned a, unsigned b);

int main()
{
	cout << CountBulls(1234, 4321) << endl;
	cout << CountBulls(1234, 1739) << endl;



	cout << CountCows(1234, 4321)<<endl;
	cout << CountCows(1254, 4321);



}

// checks if the given number is valid 
bool IsValid(unsigned n) {
	bool result = 1;

	// check if number is in correct range
	if (n < 1234 || n > 9876)
	{
		result = 0;
	}

	unsigned* digits = GetDigits(n);

	// check if digits are correct
	for (unsigned i = 0; i < NUMBER_LENGTH - 1; i++)
	{
		if (digits[i] == 0)
		{
			result = 0;
			break;
		}

		for (unsigned j = i + 1; j < NUMBER_LENGTH; j++)
		{
			if (digits[i] == digits[j])
			{
				result = 0;
				break;
			}
		}

		if (!result)
		{
			break;
		}
	}

	delete[]digits;

	return result;
}

// count the number of bulls between two numbers
unsigned CountBulls(unsigned a, unsigned b) {
	unsigned counter = 0;
	unsigned* digitsA = GetDigits(a);
	unsigned* digitsB = GetDigits(b);

	for (size_t i = 0; i < NUMBER_LENGTH; i++)
	{
		if (digitsA[i] == digitsB[i])
		{
			counter++;
		}
	}

	delete[]digitsA;
	delete[]digitsB;

	return counter;
}

// count the number of cows between two numbers
unsigned CountCows(unsigned a, unsigned b) {
	unsigned counter = 0;
	unsigned* digitsA = GetDigits(a);
	unsigned* digitsB = GetDigits(b);

	for (size_t i = 0; i < NUMBER_LENGTH; i++)
	{
		cout << digitsA[i];

	}
	cout << std::endl;
	for (size_t i = 0; i < NUMBER_LENGTH; i++)
	{
		cout << digitsB[i];

	}
	cout << std::endl;

	for (unsigned i = 0; i < NUMBER_LENGTH; i++)
	{
		for (unsigned j = 0; j < NUMBER_LENGTH; j++)
		{
			if ((digitsA[i] == digitsB[j]) && (i != j))
			{
				counter++;
			}
		}
	}

	delete[]digitsA;
	delete[]digitsB;

	return counter;
}

unsigned* GetDigits(unsigned n) {
	// get number digits
	unsigned* digits = new unsigned[NUMBER_LENGTH];

	for (unsigned i = 0; i < NUMBER_LENGTH; i++)
	{
		unsigned curDigit = n % 10;
		digits[i] = curDigit;
		n /= 10;
	}

	return digits;
}