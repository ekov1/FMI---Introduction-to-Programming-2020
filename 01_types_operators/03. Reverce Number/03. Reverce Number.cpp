// Да се въведе цяло трицифрено число. Обърнете цифрите му.
#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int x;
	cout << "Enter a three-digit number: ";
	cin >> x;

	int ones = x % 10;
	int tens = x % 100 / 10;
	int hundreds = x / 100;

	cout << "Your reversed number is : ";
	cout << ones << tens << hundreds;
}
