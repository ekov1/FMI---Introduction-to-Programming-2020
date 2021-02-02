// 22. CountOnesZeroes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int n=8;
int ones = 0;
int zeros = 0;
void CntOnesZeros(int index);

int main()
{
	CntOnesZeros(0);
	cout << "ones " << ones << endl;
	cout << "zeros " << zeros << endl;

}

void CntOnesZeros(int index) {
	if (index == 32)
	{
		return;
	}

	int mask = 1 << index;
	int bit = (mask & n)>>index;
	if (bit)
	{
		++ones;
	}else{
		++zeros;
	}

	CntOnesZeros(index + 1);
}
