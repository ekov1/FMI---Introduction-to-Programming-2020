//Да се въведат две цели числа и да се разменят техните стойности.
#include <iostream>

using std::cout;
using std::cin;

int main() {
	int x;
	int y;

	cout << "Enter first number" << '\n';
	cin >> x;
	cout << "Enter second number" << '\n';
	cin >> y;

	int temp;
	temp = x;
	x = y;
	y = temp;
	cout << "swapped numbers are" << '\n';
	cout << x << " " << y;
}