// Напишете функция, която връща най-големия елемент на двумерен масив
// с големина m x n.

/*
4 4
  2	8  9 32
  5	3 15 25
  2	7 99  1
100 5  9  6

100;
 */

#include <iostream>

const unsigned MAX_SIZE = 100;
unsigned m, n;
unsigned matrix[MAX_SIZE][MAX_SIZE];

void ReadMatrix();
void SearchRow(unsigned row, unsigned& biggest);
unsigned FindBiggestElement();

int main()
{
	ReadMatrix();
	std::cout << "biggest elemment = " << FindBiggestElement();
}

void ReadMatrix() {

	std::cout << "Enter  matrix MxN size(max 100): ";
	std::cin >> m >> n;

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

unsigned FindBiggestElement() {
	unsigned biggest = 0;
	for (size_t i = 0; i < m; i++)
	{
		SearchRow(i, biggest);
	}
	return biggest;
}

void SearchRow(unsigned row, unsigned& biggest) {
	for (size_t i = 0; i < n; i++)
	{
		if (matrix[row][i] > biggest) {
			biggest = matrix[row][i];
		}
	}
}

void PrintMatrix() {
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (matrix[i][j] < 10)
			{
				std::cout << " " << matrix[i][j] << " ";
			}
			else {
				std::cout << matrix[i][j] << " ";

			}
		}
		std::cout << std::endl;
	}
}