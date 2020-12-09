// Напишете функция, която по дадени число
// h и матрица М(m x n), умножава матрицата със скалара h.

// Пример:
// 
// Вход: 2  2 2  1 2
// 3 4
// Изход : 2 4
// 6 8

#include <iostream>

const unsigned MAX_SIZE = 100;
unsigned m, n;
int matrix[MAX_SIZE][MAX_SIZE];

void ReadMatrix();
void PrintMatrix();
void MultiplyMatrixWithScalar();

int main()
{
	ReadMatrix();
	MultiplyMatrixWithScalar();
	PrintMatrix();
}

void MultiplyMatrixWithScalar() {
	int h;
	std::cout << "Enter scalar value: ";
	std::cin >> h;

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] *= h;;
		}
	}
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