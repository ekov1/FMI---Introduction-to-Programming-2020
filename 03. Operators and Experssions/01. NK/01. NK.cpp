//������ 1: K - �� ����� �� �����
//�������� ��������, ����� ��� �������� ����� n � ������� k ������ k - ���� ����� � ���������� ����� �� n �� ����� ������.�������, �� k � �� - ����� �� ��������� �� n.
//
//������ : ���� : 123456 4 ����� : 3 ���� : 1439 1 ����� : 9
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
