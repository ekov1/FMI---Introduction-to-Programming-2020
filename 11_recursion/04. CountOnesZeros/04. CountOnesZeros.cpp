// 03. PrintBits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;


void CountOnesAndZeros(unsigned n, unsigned position = 31, unsigned countOnes = 0, unsigned countZeros = 0);

int main()
{
	CountOnesAndZeros(8);
	CountOnesAndZeros(10);

}

void CountOnesAndZeros(unsigned n, unsigned position, unsigned countOnes, unsigned countZeros) {

	unsigned bit = (n & (1 << position)) >> position;

	if (bit)
	{
		countOnes++;
	}
	else {
		countZeros++;
	}

	if (position == 0)
	{
		std::cout << "In number: "<<n<<" we have " << countZeros <<" zeroes and "<< countOnes << " ones!"<<std::endl;
		return;
	}
	CountOnesAndZeros(n, position - 1, countOnes, countZeros);
}
