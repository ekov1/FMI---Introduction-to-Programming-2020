// Напишете функция, която по въведени m, n инициализира елементите
// на матрица M(m x n) и функция, която изкарва стойностите на матрицата на екрана.
#include <iostream>

int main()
{
	const unsigned MAX_SIZE = 100;
	unsigned m, n;
	std::cout << "Enter  matrix MxN size(max 100): ";
	std::cin >> m >> n;

	unsigned matrix[MAX_SIZE][MAX_SIZE];
	unsigned counter = 0;

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			matrix[i][j] = counter++;
		}
	}

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
