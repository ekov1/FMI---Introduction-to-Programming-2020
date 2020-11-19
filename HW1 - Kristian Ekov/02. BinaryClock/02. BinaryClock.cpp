// 02. BinaryClock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <stdio.h> 
using std::cin;
using std::cout;

int getMinutes(int x) {
	int minutes = 0;

	int b0, b1, b2, b3, b4, b5;
	int mask = 1;

	b0 = x & mask;
	//cout << "b0 = " << b0 << '\n';

	mask = 1 << 1;
	b1 = (x & mask) >> 1;
	//cout << "b1 = " << b1 << '\n';

	mask = 1 << 2;
	b2 = (x & mask) >> 2;
	//cout << "b2 = " << b2 << '\n';

	mask = 1 << 3;
	b3 = (x & mask) >> 3;
	//cout << "b3 = " << b3 << '\n';

	mask = 1 << 4;
	b4 = (x & mask) >> 4;
	//cout << "b4 = " << b4 << '\n';

	mask = 1 << 5;
	b5 = (x & mask) >> 5;
	//cout << "b5 = " << b5 << '\n';

	minutes = (b5 * 32) + (b4 * 16) + (b3 * 8) + (b2 * 4) + (b1 * 2) + b0;

	return minutes;
}

int getHours(int x) {
	int hours = 0;

	int b6, b7, b8, b9, b10, b11;
	int mask = 1 << 6;

	b6 = (x & mask) >> 6;
	//cout << "b6 = " << b6 << '\n';

	mask = 1 << 7;
	b7 = (x & mask) >> 7;
	//cout << "b7 = " << b7 << '\n';

	mask = 1 << 8;
	b8 = (x & mask) >> 2;
	//cout << "b8 = " << b8 << '\n';

	mask = 1 << 9;
	b9 = (x & mask) >> 9;
	//cout << "b9 = " << b9 << '\n';

	mask = 1 << 10;
	b10 = (x & mask) >> 10;
	//cout << "b10 = " << b10 << '\n';

	mask = 1 << 11;
	b11 = (x & mask) >> 11;
	//cout << "b11 = " << b11 << '\n';

	int secondDigit = b9 * 8 + b8 * 4 + b7 * 2 + b6;
	//cout << "secondDigit = " << secondDigit << '\n';

	int firstDigit = b11 * 2 + b10;
	//cout << "firstDigit = " << firstDigit << '\n';

	mask = 1 << 12;
	int	b12 = (x & mask) >> 12;
	//cout << "b11 = " << b11 << '\n';

	hours = 10 * firstDigit + secondDigit;
	//cout << "hours = " << hours << '\n';

	if (b12 == 0) {
		if (hours > 12) {
			hours -= 12;
		}
		if (hours == 0) {
			hours = 12;
		}
	}
	return hours;
}

void PrintTime(int h, int m) {

	if (h > 24 || m > 60) {
		cout << "invalid time" << '\n';
		return;
	}

	if (h < 10) {
		cout << '0' << h;
	}
	else {
		cout << h;
	}

	cout << ":";

	if (m < 10) {
		cout << '0' << m;
	}
	else {
		cout << m;
	}

	cout << '\n';
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	if (!cin) {
		cout << "Your input was invalid.";
		return 0;
	}

	int minutes1 = getMinutes(num1);
	//cout << "minutes = " << minutes << '\n';

	int minutes2 = getMinutes(num2);
	//cout << "minutes = " << minutes << '\n';

	int hours1 = getHours(num1);

	int hours2 = getHours(num2);

	//cout << "time1 = " << hours1 << " : " << minutes1 << '\n';
	//cout << "time2 = " << hours2 << " : " << minutes2 << '\n';
	
	PrintTime(hours1, minutes1);
	PrintTime(hours2, minutes2);

	minutes1 += hours1 * 60;
	minutes2 += hours2 * 60;

	int diff;
	if (minutes1 > minutes2) {
		diff = minutes1 - minutes2;
	}
	else
	{
		diff = minutes2 - minutes1;
	}

	int diffH = diff / 60;
	int diffM = diff % 60;

	cout << "diff ";
	PrintTime(diffH, diffM);
}



