#include <iostream>

using std::cout;
using std::endl;

int const BOARD_SIZE = 8;
int board[BOARD_SIZE][BOARD_SIZE];

void InitializeBoard();
void PrintBoard();
bool PutQueens(int n, bool havePutAllQueens = 0);
bool PutQueen(int n);

int main()
{
	InitializeBoard();
	PrintBoard();
	cout << "have put all queens = " << (PutQueens(BOARD_SIZE) ? "True" : "False");
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
bool PutQueens(int n, bool havePutAllQueens) {
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

// n number of queen
bool PutQueen(int n) {
	bool canPut = 0;
	int freeIndexRow;
	int freeIndexCol;

	// look for free space
	bool breakFlag = 0;
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
			{
				canPut = 1;
				freeIndexRow = i;
				freeIndexCol = j;
				breakFlag = 1;
				break;
			}
		}
		if (breakFlag)
		{
			break;
		}
	}

	// if freespace put queen
	if (canPut)
	{
		int Row = freeIndexRow;
		int Col = freeIndexCol;
		board[Row][Col] = n;

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

		// right
		Row = freeIndexRow;

		while (true)
		{
			if (Col + 1 == BOARD_SIZE)
			{
				break;
			}
			Col++;
			board[Row][Col] = n;
		}

		// left
		Col = freeIndexCol;

		while (true)
		{
			if (Col - 1 < 0)
			{
				break;
			}
			Col--;
			board[Row][Col] = n;
		}

		// main diagonal down left
		Row = freeIndexRow;
		Col = freeIndexCol;

		while (true)
		{
			if (Col + 1 == BOARD_SIZE || Row + 1 == BOARD_SIZE)
			{
				break;
			}
			Col++;
			Row++;
			board[Row][Col] = n;
		}
	}

	return canPut;
}