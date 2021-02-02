//1. Да се напише функция, която приема две числа и проверява дали
//цифрите на 1то число се срещат във второто.
//Цифрите трябва да са в същия ред и да се използва само рекурсия(да няма цикли).
//Например:
//112331 123 -> true
//112331 121 -> true
//11331 121  -> false

#include <iostream>
#include <cmath>

using namespace std;
bool ContainsDigits(int a, int b);
bool ContainsDigitsRec(int b, int a, int digitA = 0, int digitB = 0, int toFind = 0, bool firstCall = true);
int main()
{
	int n;
	int m;
	//cin >> n >> m;

	cout << ContainsDigitsRec(112331, 123);
	cout << ContainsDigitsRec(112331, 121);
	cout << ContainsDigitsRec(11331, 121);

}

bool ContainsDigitsRec(int b, int a, int digitA, int digitB, int toFind, bool firstCall) {
	if (firstCall)
	{
		int lenA = log10(a) + 1;
		int lenB = log10(a) + 1;

		// length check
		if (lenB > lenA)
		{
			return false;
		}

		return ContainsDigitsRec(b / 10, a / 10, a % 10, b % 10, lenB, false);
	}

	if (digitA == digitB)
	{
		digitA = a % 10;
		a /= 10;
		toFind--;
	}

	if (b == 0)
	{
		if (toFind == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	return  ContainsDigitsRec(b / 10, a, digitA, b % 10, toFind, firstCall);

}

// returns true if second number contains digits of first number in current oreder
// else returns false
bool ContainsDigits(int b, int a) {
	bool result = false;

	int digitFirstNum = a % 10;
	a /= 10;

	while (true)
	{
		if (a == 0)
		{
			result = true;
			break;
		}

		if (b == 0)
		{
			break;
		}

		int digitSecondNum = b % 10;
		b /= 10;

		if (digitFirstNum == digitSecondNum)
		{
			digitFirstNum = a % 10;
			a /= 10;
		}
	}

	return result;
}


