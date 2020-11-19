// Напишете програма, която прочита цяло положително число
// unsigned int - А и три числа показващи позиции на битове -
// а1, а2, а3 в интервала[0;31].Програмата да пресметне
// числото А’ получено от А, чрез вдигане на битовете
// на позиции а1, а2, а3 и да отпечата на екрана
// разликата А’ - А.


#include <iostream>

using std::cin;
using std::cout;


int main()
{
	unsigned int a;
	cout << "Enter number A :";
	cin >> a;

	unsigned int b1, b2, b3;
	cout << "Enter bit positions";
	cin >> b1 >> b2 >> b3;

	unsigned int aPrim = a;
	unsigned int mask = 1;

	mask = mask << b1;
	aPrim = aPrim | mask;

	mask = 1;
	mask = mask << b2;
	aPrim = aPrim | mask;

	mask = 1;
	mask = mask << b3;
	aPrim = aPrim | mask;

	//one row
	//aPrim = (a | (1 << b1) | (1 << b2) | (1 << b1));

	int result = aPrim - a;
	cout << "A = " << a << " A' = " << aPrim << '\n';
	cout << "A' - A = " << result;

}

