// 03. DateTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cin;
using std::cout;

bool IsLeap(int year) {
	bool isLeap = false;

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		isLeap = true;
	}

	return isLeap;
}

// returns number of days past since the beggining of the year
int MonthToDays(int currentMonth, int year) {
	int days = 0;
	//get privious month
	int previousMonth = currentMonth - 1;

	switch (previousMonth)
	{
	case 1: {
		days = 31;
		break;
	}
	case 2: {
		days = 59;
		break;
	}case 3: {
		days = 90;
		break;
	}case 4: {
		days = 120;
		break;
	}case 5: {
		days = 151;
		break;
	}case 6: {
		days = 181;
		break;
	}case 7: {
		days = 212;
		break;
	}case 8: {
		days = 243;
		break;
	}case 9: {
		days = 273;
		break;
	}case 10: {
		days = 304;
		break;
	}case 11: {
		days = 334;
		break;
	}
	}
	bool isLeap = IsLeap(year);

	if (isLeap && previousMonth >= 2) {
		days++;
	}

	return days;

}

void PrintTime(int h, int m, int s) {

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

	cout << ":";

	if (s < 10) {
		cout << '0' << s;
	}
	else {
		cout << s;
	}

	cout << '\n';
}

bool ValidateData(int d, int month, int year, int hours, int min, int sec) {
	bool isValid = true;

	if (year < 0) {
		isValid = false;
	}

	if (isValid) {
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
			if (d < 0 || d > 31) {
				isValid = false;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11: {
			if (d < 0 || d > 30) {
				isValid = false;
			}
			break;
		}
		case 2: {
			bool isLeap = IsLeap(year);
			if (isLeap) {
				if (d < 0 || d > 29) {
					isValid = false;
				}
			}
			else {
				if (d < 0 || d > 28) {
					isValid = false;
				}
			}
			break;
		}default: {
			// will set value to false for invalid months >12 <1
			isValid = false;
			break;
		}
		}
	}

	if (isValid) {
		if (hours > 24 || hours < 0) {
			isValid = false;
		}
	}

	if (isValid) {
		if (min > 59 || min < 0) {
			isValid = false;
		}
	}

	if (isValid) {
		if (sec > 59 || sec < 0) {
			isValid = false;
		}
	}

	return isValid;
}

// Function to calculate the number  of leap years in range of (1, year) 
int NumLeaps(int year)
{
	return (year / 4) - (year / 100) + (year / 400);
}

int main()
{
	//dd.mm.yyyy HH:MM:SS
	int days1, m, year1, h, min, s;
	cin >> days1;
	cin.ignore(1, '.');
	cin >> m;
	cin.ignore(1, '.');
	cin >> year1;
	cin.ignore(1, ' ');
	cin >> h;
	cin.ignore(1, ':');
	cin >> min;
	cin.ignore(1, ':');
	cin >> s;

	int days2, m2, year2, h2, min2, s2;
	cin >> days2;
	cin.ignore(1, '.');
	cin >> m2;
	cin.ignore(1, '.');
	cin >> year2;
	cin.ignore(1, ' ');
	cin >> h2;
	cin.ignore(1, ':');
	cin >> min2;
	cin.ignore(1, ':');
	cin >> s2;

	bool validInput = cin && ValidateData(days1, m, year1, h, min, s) && ValidateData(days2, m2, year2, h2, min2, s2);
	if (!validInput) {
		cout << "Invalid date/time";
		return 0;
	}

	// cout << d << "." << m << "." << y << " " << h << ":" << min << ":" << s;

	int numLeapsDate1 = NumLeaps(year1);
	int numLeapsDate2 = NumLeaps(year2);

	days1 = days1 + year1 * 365 + MonthToDays(m, year1) + numLeapsDate1;
	days2 = days2 + year2 * 365 + MonthToDays(m2, year2) + numLeapsDate2;

	int dDiff;
	int sDiff;

	s += h * 3600 + min * 60;
	s2 += h2 * 3600 + min2 * 60;

	if (days1 > days2) {

		dDiff = days1 - days2;
		sDiff = 24 * 3600 - s2 + s;
	}
	else
	{
		dDiff = days2 - days1;
		sDiff = 24 * 3600 - s + s2;
	}

	// case <24h passed 
	if (dDiff == 1 && sDiff < 24*3600) {
		if (days1 > days2) {

			dDiff = 0;
		}
		else
		{
			dDiff = 0;
		}
	}
	else {
		if (s > s2) {
			sDiff = s - s2;
		}
		else
		{
			sDiff = s2 - s;
		}
	}



	if (dDiff > 0) {
		cout << dDiff << "-";
	}

	int hDiff = (sDiff / 60) / 60;
	int minDiff = (sDiff - hDiff * 3600) / 60;
	sDiff = (sDiff % 3600) % 60;

	PrintTime(hDiff, minDiff, sDiff);
}

