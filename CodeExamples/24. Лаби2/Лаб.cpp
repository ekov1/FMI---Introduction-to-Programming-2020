int** table;

int main() {

}

bool IsOutside(int row, int col) {

}

void PrintPath() {

}

bool IsExit(int row, int col) {
	bool result = false;
	if (table[row][col] == 'e')
	{
		result = true;
	}
	return result;
}

bool IsWall(int row, int col) {
	bool result = false;
	if (table[row][col] == '*')
	{
		result = true;
	}
	return result;
}

void FindAllPaths(int row, int col) {
	if (IsOutside(row, col))
	{

	}

	if (IsWall(row, col)) {

	}

	if (IsExit(row, col))
	{
		PrintPath();
	}
	else if(table[row][col]!='v'){
		table[row][col] = 'v';
		//Up
		FindAllPaths(row - 1, col);
		//Down
		FindAllPaths(row + 1, col);
		//Left
		FindAllPaths(row, col - 1);
		//Right
		FindAllPaths(row, col + 1);
	}
}