#include <iostream>

using namespace std;

void ConWay(unsigned** table, int rows, int cols);

int main() {
	unsigned rows;
	unsigned cols;
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of cols: ";
	cin >> cols;

	// create table
	unsigned** table = new(nothrow) unsigned* [rows];
	if (!table)
	{
		cerr << "memory for **table could not be alocated";
		return 0;
	}

	for (unsigned i = 0; i < rows; i++)
	{
		table[i] = new(nothrow) unsigned[cols];
		if (!table[i])
		{
			cerr << "memory for row could not be alocated";
			return 0;
		}

	}

	ConWay(table, rows, cols);

	// free memory
	for (unsigned i = 0; i < rows; i++)
	{
		delete[] table[i];
	}
	delete[] table;
	table = nullptr;
	return 0;
}

int ConWay(unsigned** table, int rows, int cols) {
	// create temp table
	unsigned** temp = new(nothrow) unsigned* [rows];
	if (!temp)
	{
		cerr << "memory for **table could not be alocated";
		return 0;
	}

	for (unsigned i = 0; i < rows; i++)
	{
		temp[i] = new(nothrow) unsigned[cols];
		if (!temp[i])
		{
			cerr << "memory for row could not be alocated";
			return 0;
		}

	}

	// free memory
	for (unsigned i = 0; i < rows; i++)
	{
		delete[] temp[i];
	}
	delete[] temp;
	temp = nullptr;

	return 1;
}