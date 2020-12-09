// Напишете функция, която намира сумата на всички елементи над
// главния диагонал на матрица M(n x m), умножава сумата по броя на нечетните
// елементи под главния диагонал и след това я отпечатва на екрана.
// 
// Пример:
// 
// Вход: 3 4   
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
// 
// сумата : 2 + 3 + 4 + 7 + 8 + 12 = 36
// броя на нечетните под диагонала : 2 (5 и 9)
// 
// Изход : 72
#include <iostream>

const unsigned MAX_SIZE = 100;
int m, n;
int countOdd = 0;
int sum = 0;
int matrix[MAX_SIZE][MAX_SIZE];

void ReadMatrix();
void CalculateSum();
void AddRowValues(unsigned row);
void CountOddElements();

int main()
{
	ReadMatrix();
	CalculateSum();
	std::cout << sum;
}

void ReadMatrix() {

	std::cout << "Enter matrix NxM size(max 100): ";
	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void CalculateSum() {
	for (size_t i = 0; i < n; i++)
	{
		AddRowValues(i);
	}

	 CountOddElements();

	sum *= countOdd;
}

void AddRowValues(unsigned row) {
	bool flag = 0;
	for (int j = 0; j < m; j++)
	{
		if (flag)
		{
			sum += matrix[row][j];
		}
		if (j == row)
		{
			flag = 1;
		}
	}
}

void CountOddElements() {
	for (int j = 0; j < m; j++)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (i == j)
			{
				break;
			}
			if (matrix[i][j] % 2 != 0) {
				countOdd++;
			}
		}
	}
}

