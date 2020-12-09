//Напишете функция, която изкарва на екрана стойностите на двата
//диагонала на матрица M(n x n).
//
//Пример:
//
//Вход: 
//4 4   
//3 6 5 7
//5 2 9 6
//8 1 4 8
//3 6 1 8
//
//Изход :
//3   7
// 2 9
// 1 4
//3   8

#include <iostream>

const unsigned MAX_SIZE = 100;
unsigned n;
unsigned matrix[MAX_SIZE][MAX_SIZE];

void ReadMatrix();
void PrintMarixDiagonals();
void PrintRow(unsigned row);
void PrintNum(unsigned num);

int main()
{
	ReadMatrix();
	PrintMarixDiagonals();
}

void ReadMatrix() {

	std::cout << "Enter  matrix MxN size(max 100): ";
	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void PrintMarixDiagonals() {
	for (size_t i = 0; i < n; i++)
	{
		PrintRow(i);
	}
}

void PrintRow(unsigned row) {
	for (size_t j = 0; j < n; j++)
	{
		if ((row == j) || (row + j == n - 1))
		{
			PrintNum(matrix[row][j]);
		}
		else {
			std::cout << "   ";
		}
	}
	std::cout << std::endl;
}

void PrintNum(unsigned num) {
	if (num < 10)
	{
		std::cout << " " << num << " ";
	}
	else {
		std::cout << num << " ";
	}
}