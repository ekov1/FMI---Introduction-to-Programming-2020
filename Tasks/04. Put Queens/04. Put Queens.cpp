#include <iostream>

using std::cout;
using std::endl;

int const BOARD_SIZE = 8;
int board[BOARD_SIZE][BOARD_SIZE];

void InitializeBoard();
void PrintBoard();
bool PutQueens(int n);
bool PutQueen(int n);

int main()
{
	InitializeBoard();
	PrintBoard();
	PutQueens(BOARD_SIZE);
	PrintBoard();

}

void InitializeBoard() {
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = 0;
		}
	}
}

void PrintBoard() {
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

// n quens to put
bool PutQueens(int n) {
	bool havePutAllQueens;
	for (size_t i = 1; i <= n; i++)
	{
		havePutAllQueens = PutQueen(i);
		PrintBoard();

	}
	return havePutAllQueens;
}

// n number of queen
bool PutQueen(int n) {
	bool canPut = 0;
	int freeIndexRow;
	int freeIndexCol;

	// look for free space
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
			{
				canPut = 1;
				freeIndexRow = i;
				freeIndexCol = j;
				break;
			}
		}
	}

	int Row = freeIndexRow;
	int Col = freeIndexCol;

	// if freespace put queen
	if (canPut)
	{
		// up
		while (true)
		{
			if (Row - 1 < 0)
			{
				break;
			}
			Row--;
			board[Row][Col] = n;
		}

		Row = freeIndexRow;
		// down
		while (true)
		{
			if (Row + 1 == BOARD_SIZE)
			{
				break;
			}
			Row++;
			board[Row][Col] = n;
		}
	}

	return canPut;
}