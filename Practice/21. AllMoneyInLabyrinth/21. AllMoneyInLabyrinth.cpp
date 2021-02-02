#include <iostream>

using namespace std;

int n, m;
char** maze;
int cashToFind;
bool foundPath;

void PrintMaze();
int CountMoney();
bool IsValid(int row, int col);
bool ReadMaze();
void FindAllPaths(int row, int col);

int main()
{
	ReadMaze();
	cashToFind = CountMoney();

	int rowStart = 0;
	int colStart = 0;
	foundPath = false;
	FindAllPaths(rowStart,colStart);
	cout << foundPath;
	// free memory
	for (int i = 0; i < n; ++i)
	{
		delete[] maze[i];
	}
	delete[] maze;

	return 0;
}

void FindAllPaths(int row, int col) {
	if (foundPath)
	{
		return;
	}

	if (!IsValid(row, col))
	{
		return;
	}

	if (row == n - 1 && col == m - 1)
	{
		if (cashToFind==0)
		{
			foundPath = true;
		}
	}

	bool isCash = false;
	if (maze[row][col]=='$')
	{
		--cashToFind;
		isCash = true;
	}

	maze[row][col] = 'v';
	FindAllPaths(row - 1, col );
	FindAllPaths(row, col + 1 );
	FindAllPaths(row + 1, col );
	FindAllPaths(row, col - 1);

	if (isCash)
	{
		maze[row][col] = '$';
		++cashToFind;
	}
	else
	{
		maze[row][col] = '-';
	}
}

bool IsValid(int row, int col) {
	return row >= 0 && row < n&& col >= 0 && col < m&& maze[row][col] != '*' && maze[row][col] != 'v';
}


bool ReadMaze() {
	const int MAX_INPUT_SIZE = 1024;
	char* line = new char[MAX_INPUT_SIZE];

	cin >> n >> m;
	cin.getline(line, MAX_INPUT_SIZE);

	maze = new(nothrow) char* [n];
	if (!maze)
	{
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		cin.getline(line, MAX_INPUT_SIZE);
		maze[i] = new(nothrow)char[m];
		if (!maze[n])
		{
			return 0;
		}

		for (int j = 0; j < m; ++j)
		{
			maze[i][j] = line[j];
		}
	}
	delete[] line;
	return 1;
}

int CountMoney() {
	int cash = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (maze[i][j] == '$')
			{
				++cash;
			}
		}
	}

	return cash;
}

void PrintMaze() {
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

