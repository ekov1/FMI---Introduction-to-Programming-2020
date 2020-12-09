//Напишете функция, която по дадени две матрици М(m x n) и T(m x n)
//cъбира двете матрици и резултата го записва в М(m x n).
//
//Пример:
//
//Вход: 2 2   3 6     5 7
//5 2     9 6
//Изход : 8 13
//14 8

#include <iostream>

const unsigned MAX_SIZE = 100;
unsigned m, n;
int M[MAX_SIZE][MAX_SIZE];
int T[MAX_SIZE][MAX_SIZE];

void ReadMatrix(int matrix[][MAX_SIZE]);
void ReadMatrices();
void PrintMatrix(int matrix[][MAX_SIZE], char matrixName);
void AdDTwoMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE]);

int main()
{
	ReadMatrices();
	AdDTwoMatrices(M, T);
	PrintMatrix(M, 'M');
	PrintMatrix(T, 'T');
}

void ReadMatrices() {
	std::cout << "Enter  matrix MxN size(max 100): ";
	std::cin >> m >> n;

	std::cout << "Enter  first matrix" << std::endl;
	ReadMatrix(M);
	std::cout << "Enter  second matrix" << std::endl;
	ReadMatrix(T);
}

void ReadMatrix(int matrix[][MAX_SIZE]) {
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void PrintMatrix(int matrix[][MAX_SIZE], char matrixName) {
	std::cout << matrixName << " = " << std::endl;;
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

void AdDTwoMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE]) {
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			A[i][j] += B[i][j];
		}
	}
}