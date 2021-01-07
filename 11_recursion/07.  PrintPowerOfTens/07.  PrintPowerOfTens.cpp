
#include <iostream>
void PowersOfTen(unsigned k, unsigned numToPrint = 10);
int main()
{
	PowersOfTen(5);
}

void PowersOfTen(unsigned k, unsigned numToPrint) {
	if (k == 0)
	{
		return;
	}

	std::cout << numToPrint << " ";
	
	PowersOfTen(k - 1, numToPrint*10);
	std::cout << numToPrint << " ";

}
