// 04. LeapYear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool IsLeap(int year);
int main()
{
	std::cout << IsLeap(2020);
	std::cout << IsLeap(1900);

}


bool IsLeap(int year) {
	bool result = false;

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                result = true;
            else
                result = false;
        }
        else
            result = true;
    }

	return result;
}
