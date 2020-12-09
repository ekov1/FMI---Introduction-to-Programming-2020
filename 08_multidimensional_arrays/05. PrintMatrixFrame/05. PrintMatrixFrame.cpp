//Напишете функция, която по дадена матрица М(m x n), 
//изкарва на екрана първите и последните редове и стълбове на матрицата.

//Пример:

//Вход: 4 3   3 6 8
//5 2 9
//6 8 2
//4 6 7

//Изход : 3 6 8
//5   9
//6   2
//4 6 7

#include <iostream>

const unsigned MAX_SIZE = 100;
unsigned m, n;
unsigned matrix[MAX_SIZE][MAX_SIZE];

void ReadMatrix();
void PrintNum(unsigned num);
void PrintMatrixFrame();
void PrintRow(unsigned row);

int main()
{
	ReadMatrix();
	PrintMatrixFrame();
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

void PrintMatrixFrame() {
	for (size_t i = 0; i < m; i++)
	{
		PrintRow(i);
	}
}

void PrintRow(unsigned row) {
	for (size_t j = 0; j < n; j++)
	{
		if (row == 0 || row == m - 1)
		{
			PrintNum(matrix[row][j]);
		}
		else {
			if (0 < j && j < n - 1)
			{
				std::cout << "   ";
			}
			else {
				PrintNum(matrix[row][j]);
			}
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