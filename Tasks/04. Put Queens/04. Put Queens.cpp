#include <iostream>

using std::cout;
using std::endl;

int const BOARD_SIZE = 8;
int board[BOARD_SIZE][BOARD_SIZE];
int boardQueens[BOARD_SIZE][BOARD_SIZE];

int counter = 0;

void InitializeBoard();
void PrintBoard(int board[][BOARD_SIZE]);
bool PutQueens(int n, int numOfQueensOnBoard = 0, bool havePutAllQueens = 0);
void PutQueen(int queenToken, int freeIndexRow, int freeIndexCol);
void CleanTry(int n);

int main()
{
	InitializeBoard();
	cout << "have put all queens = " << (PutQueens(BOARD_SIZE) ? "True" : "False");
	cout << counter;
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

void PrintBoard(int board[][BOARD_SIZE]) {
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// n quens to put
bool PutQueens(int n, int numOfQueensOnBoard, bool havePutAllQueens) {
	

	if (n == numOfQueensOnBoard)
	{
		return true;
	}

	// look for free space
	bool breakFlag = 0;
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 0)
			{
				int queenToken = numOfQueensOnBoard + 1;
				PutQueen(queenToken, i, j);
				numOfQueensOnBoard += 1;
				havePutAllQueens = PutQueens(n, numOfQueensOnBoard, havePutAllQueens);

				if (havePutAllQueens)
				{
					/*PrintBoard(board);
					PrintBoard(boardQueens);*/
					counter++;
				}

				// clean try
				CleanTry(queenToken);
				numOfQueensOnBoard -= 1;
				havePutAllQueens = false;
			}
		}
	}

	return havePutAllQueens;
}

void CleanTry(int token) {
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == token)
			{
				board[i][j] = 0;
			}
			if (boardQueens[i][j] == token)
			{
				boardQueens[i][j] = 0;
			}
		}
	}
}

// n number of queen
void PutQueen(int queenToken, int freeIndexRow, int freeIndexCol) {
	int Row = freeIndexRow;
	int Col = freeIndexCol;
	board[Row][Col] = queenToken;
	boardQueens[Row][Col] = queenToken;

	// up
	while (true)
	{
		if (Row - 1 < 0)
		{
			break;
		}
		Row--;
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
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
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
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
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
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
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
	}

	// main diagonal down right
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
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
	}

	// main diagonal up left
	Row = freeIndexRow;
	Col = freeIndexCol;
	while (true)
	{
		if (Col - 1 < 0 || Row - 1 < 0)
		{
			break;
		}
		Col--;
		Row--;
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
	}

	// secodary diagonal up right
	Row = freeIndexRow;
	Col = freeIndexCol;

	while (true)
	{
		if (Col + 1 == BOARD_SIZE || Row - 1 < 0)
		{
			break;
		}
		Col++;
		Row--;
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
	}

	// secodary diagonal down left
	Row = freeIndexRow;
	Col = freeIndexCol;

	while (true)
	{
		if (Col - 1 < 0|| Row + 1 == BOARD_SIZE)
		{
			break;
		}
		Col--;
		Row++;
		if (board[Row][Col] == 0)
		{
			board[Row][Col] = queenToken;
		}
	}
}