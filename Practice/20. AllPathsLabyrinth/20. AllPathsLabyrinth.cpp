#include <iostream>

using namespace std;

void PrintLabyrinth(int n, int m, char** labyrinth);
bool IsValidCell(int row, int col, int rows, int cols, char** labyrinth);
void PrintPath();
void FindPaths(int row, int col, int rows, int cols, char** labyrinth);

int main()
{
	const int MAX_INPUT = 1024;
	char line[MAX_INPUT];

	int n;
	int m;

	cin >> n >> m;
	cin.getline(line, MAX_INPUT);

	char** labyrinth = new char* [n];
	for (int i = 0; i < n; i++)
	{
		labyrinth[i] = new char[m];
	}

	for (int i = 0; i < n; ++i)
	{
		cin.getline(line, MAX_INPUT);

		for (int j = 0; j < m; ++j)
		{
			labyrinth[i][j] = line[j];
		}
	}

	FindPaths(0, 0, n, m, labyrinth);

	for (int i = 0; i < n; i++)
	{
		delete[] labyrinth[i];
	}
	delete[] labyrinth;
}

void FindPaths(int row, int col, int rows, int cols, char** labyrinth) {
	if (!IsValidCell(row, col, rows, cols,labyrinth))
	{
		return;
	}

	if (labyrinth[row][col] == 'e')
	{
		PrintPath();
	}
	else {
		labyrinth[row][col] = 'v';
		FindPaths(row - 1, col, rows, cols, labyrinth);
		FindPaths(row, col + 1, rows, cols, labyrinth);
		FindPaths(row + 1, col, rows, cols, labyrinth);
		FindPaths(row, col - 1, rows, cols, labyrinth);
		labyrinth[row][col] = '-';
	}
}

void PrintPath() {
	cout << "found";
}

bool IsValidCell(int row, int col, int rows, int cols, char** labyrinth) {
	return row >= 0 && row < rows&& col >= 0 && col < cols&& labyrinth[row][col] != '*' && labyrinth[row][col] != 'v';
}

void PrintLabyrinth(int n, int m, char** labyrinth) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << labyrinth[i][j] << " ";
		}
		cout << endl;
	}
}

