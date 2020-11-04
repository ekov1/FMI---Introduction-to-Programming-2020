// От конзолата се прочитат две цели 4-байтови числа “p” и “q”.
// Да се изкара на конзолата цялата част и остатъка на частното, 
// получено при делението на „p“ с “q”.

#include <iostream>

using std::cout;
using std::cin;

int main()
{
	__int32 p;
	__int32 q;

	cout << "Enter number to divide p: " << '\n';
	cin >> p;

	cout << "Enter number to divide by q: " << '\n';
	cin >> q;

	__int32 quotient = p / q;
	__int32 remainder = p / q;


	cout << "quotient : " << quotient << ", ";
	cout << "remainder : " << remainder << '\n';
}

