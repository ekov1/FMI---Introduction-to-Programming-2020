#include <iostream>

// global stuff N shit
unsigned const MAX_COLS = 20;
unsigned const MAX_ROWS = 40;
unsigned const PLAYER_ONE_DISC = 1;
unsigned const PLAYER_TWO_DISC = 2;

int gameBoard[MAX_ROWS][MAX_COLS];

int gameBoardCols = 0;
int gameBoardRows = 0;

void InitializeGameBoard();
void PrintBoard(int board[][MAX_COLS]);
bool DropDisc(int playerDisc, int col);
bool IsGameOver(int row, int col);
void RunGame();
void WritePlayerName(bool playerOneTurn);

int main()
{
	RunGame();
}

// so called ENGINE
void RunGame() {
	InitializeGameBoard();
	bool playerOneTurn = 1;
	int rowIndex = -1;
	int playerMove;
	PrintBoard(gameBoard);

	while (true)
	{
		WritePlayerName(playerOneTurn);
		std::cout << "Enter col: ";
		std::cin >> playerMove;

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

		if (rowIndex)
		{
			if (IsGameOver(playerMove, rowIndex))
			{
				WritePlayerName(playerOneTurn);
				std::cout << "Wins!!!";
				std::cout << "Other player is a little girl! HAHA!";
				break;
			}

			playerOneTurn = !playerOneTurn;
		}
	}
}

void WritePlayerName(bool playerOneTurn) {
	std::cout << "Player ";
	if (playerOneTurn)
	{
		std::cout << "One";
	}
	else
	{
		std::cout << "Two";
	}
	std::cout << std::endl;
}

// Checks if GameOver condition is true
bool IsGameOver(int row, int col) {
	//check diagonals

	return true;
}

// checks is disc is at the end of the winning row
void CheckIfEndOFRow(int row, int col) {
	int counter = 1;
	int playerToken = gameBoard[row][col];
	int nextPosRow, nextPosCol;
	int currentPosRow, currentPosCol;

	//up-right
	currentPosRow = row;
	currentPosCol = col;
	while (true)
	{
		nextPosCol = currentPosCol++;
		nextPosRow = currentPosRow--;

		if (nextPosCol > gameBoardCols - 1 || nextPosRow <= 0)
		{
			break;
		}

		if (gameBoard[nextPosRow][nextPosCol] == playerToken) {
			counter++;
			if (counter == 4)
			{
				break;
			}
		}
		else {
			break;
		}

		currentPosCol = nextPosCol;
		currentPosRow = nextPosRow;
	}

	// right
	if (counter != 4)
	{
		currentPosRow = row;
		currentPosCol = col;
		counter = 1;
		nextPosRow = currentPosRow;

		while (true)
		{
			nextPosCol = currentPosCol++;

			if (nextPosCol > gameBoardCols - 1)
			{
				break;
			}

			if (gameBoard[nextPosRow][nextPosCol] == playerToken) {
				counter++;
				if (counter == 4)
				{
					break;
				}
			}
			else {
				break;
			}

			currentPosCol = nextPosCol;
		}
	}
}

// Drops disc for input player
// if move is valid returns col index
// if move is invalid(coll is full or invalid) returns -1
bool DropDisc(int playerDisc, int col) {
	if (col < 0 || col >gameBoardCols)
	{

	}
	int rowIndex;
	for (size_t row = 0; row < gameBoardRows; row++)
	{
		if (gameBoard[row][col])
		{
			if (row == 0)
			{
				std::cout << "Invalid move";
				rowIndex = -1;
			}
			else {
				rowIndex = row + 1;
				gameBoard[rowIndex][col] = playerDisc;
			}
			break;
		}
	}
	return rowIndex;
}

// Initializes Game Board before start of the game
void InitializeGameBoard() {
	std::cout << "Enter board width :";
	std::cin >> gameBoardRows;
	std::cout << "Enter board height :";
	std::cin >> gameBoardCols;

	for (size_t row = 0; row < gameBoardRows; row++)
	{
		for (size_t col = 0; col < gameBoardCols; col++)
		{
			gameBoard[row][col];
		}
	}
}

void PrintBoard(int board[][MAX_COLS]) {
	for (size_t i = 0; i < gameBoardRows; i++)
	{
		for (size_t j = 0; j < gameBoardCols; j++)
		{
			std::cout << "|";
			if (board[i][j] == 1)
			{
				std::cout << "X";
			}
			else if (board[i][j] == 2) {
				std::cout << "O";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "|" << std::endl;
	}
}