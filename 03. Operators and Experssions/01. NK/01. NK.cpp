//Задача 1: K - та цифра на число
//Напишете програма, която при въведено число n и позиция k намира k - тата цифра в десетичния запис на n от дясно наляво.Считаме, че k е по - малко от дължината на n.
//
//Пример : Вход : 123456 4 Изход : 3 Вход : 1439 1 Изход : 9
#include <iostream>
using namespace std;
int NK(int n, int k);
int nk(int n, int k, int digit = 0);
int main()
{
	cout << NK(123456, 4) << endl;
	cout << nk(123456, 4) << endl;

}

int NK(int n, int k) {
	int digit;

	for (; k > 0; --k, n /= 10)
	{
		digit = n % 10;
	}

	//while (k > 0)
	//{
	//	digit = n % 10;
	//	n /= 10;
	//	--k;
	//}

	return digit;
}



int nk(int n, int k, int digit) {
	if (k == 0) {
		return digit;
	}

	return nk((n / 10), (k - 1), (n % 10));
}
