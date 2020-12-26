// 02. DrawFigureRecursive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::endl;

void WriteRow(unsigned length, char symbol);
int DrawFigure(bool flag, unsigned size, unsigned startSize);

int main()
{
	bool flag = 0;
	unsigned size = 4;
	unsigned startSize = size;

	DrawFigure(flag, size, startSize);
}

int DrawFigure(bool flag, unsigned size, unsigned startSize) {
	if (flag)
	{
		WriteRow(size, '#');
		size++;
	}
	else {
		
		WriteRow(size, '*');
		size--;
	}

	if (size ==0)
	{
		flag = 1;
	}

	if (size != startSize+1)
	{
		DrawFigure(flag, size, startSize);
	}
	else {
		return 1;
	}
}

void WriteRow(unsigned length, char symbol) {
	if (length > 0) {
		for (size_t i = 0; i < length; i++)
		{
			cout << symbol;
		}
		cout << std::endl;
	}
}
