// Да се въведе цяло трицифрено число. 
// Да се изведе сумата, произведението 
// и средноаритметичното на цифрите му.
// Да се въведе цяло трицифрено число. Да се изведе сумата, произведението и средноаритметичното на цифрите му.
#include <iostream>

using std::cout;
using std::cin;

int main() {
	int x;
	cout << "Enter a three-digit number: ";
	cin >> x;

	int ones = x % 10;
	int tens = x % 100 / 10;
	int hundreds = x / 100;

	int sum = ones + tens + hundreds;
	cout << "Sum of digits is : " << sum << '\n';

	int product = ones * tens * hundreds;
	cout << "Product of digits is : " << product << '\n';

	int average = (ones + tens + hundreds) / 3;
	cout << "Average of digits is : " << average << '\n';

}