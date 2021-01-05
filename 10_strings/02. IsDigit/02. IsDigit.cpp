#include <iostream>

using std::cout;

bool IsDigit(char ch);

int main()
{
	cout << IsDigit('a');
	cout << IsDigit('N');
	cout << IsDigit('7');
}

bool IsDigit(char ch) {
	bool result = ('0' <= ch && ch <= '9');
	return result;
}