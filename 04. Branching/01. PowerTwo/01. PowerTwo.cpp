//Задача 1: Степенуване на втора степен
//Напишете програма, която получава две числа x и k и използвайки побитови операции, умножава числото x по 2 ^ k.
//
//Вход : 5 3
//
//Изход : 40 (5 * 2 ^ 3 = 5 * 8 = 40)

#include <iostream>

using namespace std;

int Multiply(int a, int b);
int PowerOfTwo(int power);
int PowTwo(int power);

int main()
{
	cout << Multiply(2, 3) << endl;
	cout << PowerOfTwo(3) << endl;
	cout << PowTwo(3) << endl;
	cout << PowTwo(0) << endl;
	cout << PowTwo(5) << endl;

}

int PowTwo(int power) {
	int result = 1;
	for (int i = 0; i < power; ++i)
	{
		result = result << 1;
	}
	return result;
}

int PowerOfTwo(int power) {
	int result = 1;

	for (int i = 0; i < power; i++)
	{
		result = Multiply(2, result);
	}

	return result;
}


// russsian pesant
int Multiply(int a, int b) {
	int result = 0;
	while (b > 0)
	{
		if (b & 1) {
			result += a;
		}

		a = a << 1;
		b = b >> 1;
	}

	return result;
}


