//������ 2: ������
//�� �� ������ ��������, ����� �� ������ ������(���� �����) �� �������� �� ����� �������, ���, ������, ������ � ������� �� ��������.

#include <iostream>
using namespace std;
int main()
{
	int years;
	cin >> years;
	int days = years * 365;
	int weeks = days / 7;
	int hours = days * 24;
	int minutes = hours * 60;
	int seconds = minutes * 60;

	cout << years << " years are" << endl;
	cout << weeks << " weeks" << endl;
	cout << days << " days" << endl;
	cout << hours << " hours" << endl;
	cout << minutes << " minutes" << endl;
	cout << seconds << " seconds" << endl;

}
