#include <iostream>

using std::endl;
using std::cout;
using std::cin;

// global stuff N shit
unsigned const MAX_COLS = 20;
unsigned const MAX_ROWS = 40;
unsigned const PLAYER_ONE_DISC = 1;
unsigned const PLAYER_TWO_DISC = 2;

int gameBoard[MAX_ROWS][MAX_COLS];
int gameBoardEmptySpaces;

int gameBoardCols = 0;
int gameBoardRows = 0;

bool InitializeGameBoard();
void PrintBoard(int board[][MAX_COLS]);
int DropDisc(int playerDisc, int col);
bool IsGameOver(int row, int col);
void RunGame();
void WritePlayerName(bool playerOneTurn);

int main()
{
	bool gameboardinitialized = InitializeGameBoard();
	if (gameboardinitialized)
	{
		RunGame();
	}
	else {
		cout << "Invalid input! Thank you come agin!" << endl;
	}

}

// so called ENGINE
void RunGame() {

	bool playerOneTurn = 1;
	int rowIndex = -1;
	int playerMove;
	PrintBoard(gameBoard);

	while (true)
	{
		WritePlayerName(playerOneTurn);
		cout << "Enter col: ";
		cin >> playerMove; // col in which player drops disc
		system("cls");
		// reduce player col by 1 because game board arr starts from 0
		playerMove--;

		if (playerOneTurn)
		{
			rowIndex = DropDisc(PLAYER_ONE_DISC, playerMove);
		}
		else
		{
			rowIndex = DropDisc(PLAYER_TWO_DISC, playerMove);
		}

		PrintBoard(gameBoard);

		if (rowIndex != -1)
		{
			// check if game can continiue
			if (gameBoardEmptySpaces == 0)
			{
				cout << "No more spaces, nobody Wins!!!" << endl;
				cout << "GAME OVER!!!";
				cout << endl;

				break;
			}

			bool isGameOver = IsGameOver(rowIndex, playerMove);
			if (isGameOver)
			{
				WritePlayerName(playerOneTurn);
				cout << "Wins!!!" << endl;;
				cout << "Other player is a little girl! HAHA!";
				cout << endl;

				break;
			}

			playerOneTurn = !playerOneTurn;
		}
	}
}

void WritePlayerName(bool playerOneTurn) {
	cout << "Player ";
	if (playerOneTurn)
	{
		cout << "One";
	}
	else
	{
		cout << "Two";
	}
	cout << " ";
}

// Checks if GameOver condition is true
bool IsGameOver(int row, int col) {
	bool isGameOver = 0;

	int winCounter = 1;
	int playerToken = gameBoard[row][col];

	int PRow = row;
	int PCol = col;

	int checkCounter = 0;

	while (checkCounter < 7)
	{
		//go up right
		while (true) {
			// are we out?
			if ((PRow - 1 < 0) || (PCol + 1 == gameBoardCols))
			{
				break;
			}
			else {
				PRow--;
				PCol++;

				if (gameBoard[PRow][PCol] != playerToken)
				{
					break;
				}

				winCounter++;

				if (winCounter == 4)
				{
					break;
				}
			}

		}

		// win ckeck
		if (winCounter == 4)
		{
			break;
		}
		checkCounter++;

		// go down left
		PRow = row;
		PCol = col;
		while (true)
		{
			// are we out?
			if ((PRow + 1 == gameBoardRows) || (PCol - 1 < 0))
			{
				break;
			}
			else {
				PRow++;
				PCol--;

				if (gameBoard[PRow][PCol] != playerToken)
				{
					break;
				}

				winCounter++;

				if (winCounter == 4)
				{
					break;
				}
			}
		}

		// win ckeck
		if (winCounter == 4)
		{
			break;
		}
		checkCounter++;

		// go right
		PRow = row;
		PCol = col;
		winCounter = 1;

		while (true)
		{
			// are we out?
			if (PCol + 1 == gameBoardCols)
			{
				break;
			}
			else {
				PCol++;

				if (gameBoard[PRow][PCol] != playerToken)
				{
					break;
				}

				winCounter++;

				if (winCounter == 4)
				{
					break;
				}
			}
		}

		// win ckeck
		if (winCounter == 4)
		{
			break;
		}
		checkCounter++;

		// go left
		PRow = row;
		PCol = col;

		while (true)
		{
			// are we out?
			if (PCol - 1 < 0)
			{
				break;
			}
			else {
				PCol--;

				if (gameBoard[PRow][PCol] != playerToken)
				{
					break;
				}

				winCounter++;

				if (winCounter == 4)
				{
					break;
				}
			}
		}

		// win ckeck
		if (winCounter == 4)
		{
			break;
		}
		checkCounter++;

		//go down right
		PRow = row;
		PCol = col;
		winCounter = 1;
		while (true) {
			// are we out?
			if ((PRow + 1 == gameBoardRows) || (PCol + 1 == gameBoardCols))
			{
				break;
			}
			else {
				PRow++;
				PCol++;

				if (gameBoard[PRow][PCol] != playerToken)
				{
					break;
				}

				winCounter++;

				if (winCounter == 4)
				{
					break;
				}
			}
		}

		// win ckeck
		if (winCounter == 4)
		{
			break;
		}
		checkCounter++;

		// go up left
		PRow = row;
		PCol = col;
		while (true)
		{
			// are we out?
			if ((PRow - 1 < 0) || (PCol - 1 < 0))
			{
				break;
			}
			else {
				PRow--;
				PCol--;

				if (gameBoard[PRow][PCol] != playerToken)
				{
					break;
				}

				winCounter++;

				if (winCounter == 4)
				{
					break;
				}
			}
		}

		// win ckeck
		if (winCounter == 4)
		{
			break;
		}
		checkCounter++;

		// go down
		PRow = row;
		PCol = col;
		winCounter = 1;
		while (true) {
			// are we out?
			if (PRow + 1 == gameBoardRows)
			{
				break;
			}
			else {
				PRow++;

				if (gameBoard[PRow][PCol] != playerToken)
				{
					break;
				}

				winCounter++;

				if (winCounter == 4)
				{
					break;
				}
			}
		}

		// win ckeck
		if (winCounter == 4)
		{
			break;
		}
		checkCounter++;
	}

	if (winCounter == 4)
	{
		isGameOver = 1;
	}

	return isGameOver;
}

// Drops disc for input player
// if move is valid returns col index
// if move is invalid(coll is full or invalid) returns -1
int DropDisc(int playerDisc, int col) {
	int rowIndex;
	if (col < 0 || gameBoardCols < col)
	{
		cout << "Invalid move" << endl;;
		rowIndex = -1;
	}
	else {
		for (int row = 0; row < gameBoardRows; row++)
		{
			if (gameBoard[row][col])
			{
				if (row == 0)
				{
					cout << "Invalid move" << endl;
					rowIndex = -1;
				}
				else {
					rowIndex = row - 1;
					gameBoard[rowIndex][col] = playerDisc;
				}
				break;
			}

			if (row == gameBoardRows - 1)
			{
				rowIndex = row;
				gameBoard[rowIndex][col] = playerDisc;
			}
		}
	}

	if (rowIndex != -1)
	{
		gameBoardEmptySpaces--;
	}
	return rowIndex;
}

// Initializes Game Board before start of the game
bool InitializeGameBoard() {
	bool result = 1;
	cout << "Enter board width :";
	cin >> gameBoardCols;
	cout << "Enter board height :";
	cin >> gameBoardRows;

	if (gameBoardCols < 4 && gameBoardRows < 4)
	{
		result = 0;
	}

	if (result) {
		gameBoardEmptySpaces = gameBoardRows * gameBoardCols;
		for (int row = 0; row < gameBoardRows; row++)
		{
			for (int col = 0; col < gameBoardCols; col++)
			{
				gameBoard[row][col];
			}
		}
	}

	return result;
}

void PrintBoard(int board[][MAX_COLS]) {
	for (int i = 0; i < gameBoardRows; i++)
	{
		for (int j = 0; j < gameBoardCols; j++)
		{
			cout << "|";
			if (board[i][j] == 1)
			{
				cout << "X";
			}
			else if (board[i][j] == 2) {
				cout << "O";
			}
			else {
				cout << " ";
			}
		}
		cout << "|" << std::endl;
	}
}