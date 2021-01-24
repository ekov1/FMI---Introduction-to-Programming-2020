#include <iostream>
#include <BullsAndCows.h>

void play();
const int* tryGuess(int x);
int CountCows(int a, int b, int NUMBER_LENGTH);
int CountBulls(int a, int b, int NUMBER_LENGTH);
void FilterList(int numberOfBull, int numberOfCows, int currentGuess, int NUMBER_LENGTH, int numbersListSize,int* numbersList,bool*possible);

bool IsValid(int n, int NUMBER_LENGTH);
int* GetDigits(int n, int NUMBER_LENGTH);

void play() {
	int* numbersList;
	bool* possible;

	const int NUMBER_LENGTH = 4;
	int numbersListSize;

	int validNumbersCount = 0;

	for (int i = 1000; i < 9999; ++i)
	{
		if (IsValid(i, NUMBER_LENGTH))
		{
			++validNumbersCount;
		}
	}

	numbersList = new int[validNumbersCount];
	numbersListSize = validNumbersCount;

	int writeIndex = 0;
	for (int i = 1000; i < 9999; ++i)
	{
		if (IsValid(i, NUMBER_LENGTH))
		{
			numbersList[writeIndex] = i;
			++writeIndex;
		}
	}

	possible = new bool[validNumbersCount];
	for (int i = 0; i < validNumbersCount; i++)
	{
		possible[i] = true;
	}


	const int* answer;

	for (int i = 0; i < 7; ++i)
	{
		int currentGuess = 0;
		for (int i = 0; i < numbersListSize; ++i)
		{
			if (possible[i])
			{
				currentGuess = numbersList[i];
				break;
			}
		}

		answer = tryGuess(currentGuess);

		int numberOfBulls = answer[0];
		int numberOfCows = answer[1];

		if (numberOfBulls == 4 && numberOfCows == 0)
		{
			break;
		}

		FilterList(numberOfBulls, numberOfCows, currentGuess, NUMBER_LENGTH,numbersListSize,numbersList,possible);
	}

	// free used memory
	delete[] answer;
	delete[] numbersList;
	delete[] possible;

	return;
}

// filters number list for invalid guesses
void FilterList(int numberOfBulls, int numberOfCows, int currentGuess, int NUMBER_LENGTH, int numbersListSize,int * numbersList,bool*possible) {
	for (int i = 0; i < numbersListSize; ++i)
	{
		if (!possible[i])
		{
			continue;
		}

		int num = numbersList[i];

		int numBulls = CountBulls(currentGuess, num, NUMBER_LENGTH);
		int numCows = CountCows(currentGuess, num, NUMBER_LENGTH);

		if (numBulls != numberOfBulls || numCows != numberOfCows)
		{
			possible[i] = false;
		}

	}
}

// checks if the given number is valid 
bool IsValid(int n, int NUMBER_LENGTH) {
	bool result = 1;

	// check if number is in correct range
	if (n < 1234 || n > 9876)
	{
		result = 0;
	}

	int* digits = GetDigits(n, NUMBER_LENGTH);

	// check if digits are correct
	for (int i = 0; i < NUMBER_LENGTH - 1; ++i)
	{
		if (digits[i] == 0)
		{
			result = 0;
			break;
		}

		for (int j = i + 1; j < NUMBER_LENGTH; ++j)
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

	// free used memory
	delete[]digits;

	return result;
}

// count the number of bulls between two numbers
int CountBulls(int a, int b, int NUMBER_LENGTH) {
	int counter = 0;
	int* digitsA = GetDigits(a, NUMBER_LENGTH);
	int* digitsB = GetDigits(b, NUMBER_LENGTH);

	for (int i = 0; i < NUMBER_LENGTH; ++i)
	{
		if (digitsA[i] == digitsB[i])
		{
			counter++;
		}
	}

	// free used memory
	delete[]digitsA;
	delete[]digitsB;

	return counter;
}

// count the number of cows between two numbers
int CountCows(int a, int b, int NUMBER_LENGTH) {
	int counter = 0;
	int* digitsA = GetDigits(a, NUMBER_LENGTH);
	int* digitsB = GetDigits(b, NUMBER_LENGTH);

	for (int i = 0; i < NUMBER_LENGTH; ++i)
	{
		for (int j = 0; j < NUMBER_LENGTH; ++j)
		{
			if ((digitsA[i] == digitsB[j]) && (i != j))
			{
				counter++;
			}
		}
	}

	// free used memory
	delete[] digitsA;
	delete[] digitsB;

	return counter;
}

// get number digits
int* GetDigits(int n, int NUMBER_LENGTH) {

	int* digits = new int[NUMBER_LENGTH];

	for (int i = 0; i < NUMBER_LENGTH; ++i)
	{
		int curDigit = n % 10;
		digits[i] = curDigit;
		n /= 10;
	}

	return digits;
}
