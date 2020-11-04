// Да се прочете число от конзолата и да се изведе числото получено 
// при премахването на последната му цифра.
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int x;
	cin >> x;
	x = x / 10;
	cout << x;
}

