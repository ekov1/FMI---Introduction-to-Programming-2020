//Под “седлова” точка на матрица M(n x m), 
//ще разбираме такъв елемент на матрицата, 
//който е с максимална стойност в реда и минимална 
//стойност на колоната, на които принадлежи.Напишете 
//функция, която по подадена матрица и нейните размери, 
//определя координатите на “седловата” си точка.Забележете, 
//че не всяка матрица притежава “седлова” точка,
//ако подадената матрица няма таква, то от програмата 
//ви се очаква да отпечата съобщение за грешка.
//
//Пример:
//
//Вход: 3 3  
//1 9 1
//4 3 2
//7 8 9
//Изход : *съобщение за грешка : няма такава точка”
//Пример :
//
//Вход: 3 3  
//1 6 3
//2 5 4
//3 7 6
//Изход : елементът с индекси(1, 1) е “седлова” точка на матрицата, неговата стойност е : 5
#include <iostream>

const unsigned MAX_SIZE = 100;
unsigned m, n;
int countOdd = 0;
int sum = 0;
int matrix[MAX_SIZE][MAX_SIZE];

void ReadMatrix();
void FindSaddlePoint();
bool CheckCol(int row, int col);

int main()
{
	setlocale(LC_ALL, "");
	ReadMatrix();
	FindSaddlePoint();
}

void ReadMatrix() {

	std::cout << "Enter matrix NxM size(max 100): ";
	std::cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

int GetBiggest(int row) {
	int big = matrix[row][0];
	int bigIndex = 0;
	for (size_t j = 1; j < m; j++)
	{
		if (matrix[row][j] > big)
		{
			big = matrix[row][j];
			bigIndex = j;
		}
	}
	return bigIndex;
}

void FindSaddlePoint() {
	bool isSaddlePoint = 0;
	size_t i = 0;
	int colCandidate;
	for (;i < n; i++)
	{
		colCandidate = GetBiggest(i);
		isSaddlePoint = CheckCol(i, colCandidate);

		if (isSaddlePoint)
		{
			break;
		}
	}

	if (isSaddlePoint)
	{
		std::cout << "елементът(" << i << ", " << colCandidate << ") е “седлова” точка на матрицата, неговата стойност е : " << matrix[i][colCandidate];
	}
	else {
		std::cout << "*съобщение за грешка : няма такава точка”";
	}
}

bool CheckCol(int row, int col) {
	bool isSaddlePoint = 1;
	int num = matrix[row][col];
	// check row
	for (size_t i = 0; i < n; i++)
	{
		if (matrix[i][col] < num)
		{
			isSaddlePoint = 0;
			break;
		}
	}

	return isSaddlePoint;
}