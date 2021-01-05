#include <iostream>

using std::cout;

bool IsAlpha(char ch);

int main()
{
	cout << IsAlpha(1);
	cout << IsAlpha('D');
	cout << IsAlpha('b');

}

// checks is char is letter returns true/false
bool IsAlpha(char ch) {
	bool result = ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
	return result;
}