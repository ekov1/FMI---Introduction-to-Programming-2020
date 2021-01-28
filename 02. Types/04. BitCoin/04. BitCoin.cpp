//������ ��� �� ������� � ��� ������� � ������ ��.�������� �������� ����� 
//�� �������� ����������� ����� � ������� ������� - ����� ������� ����� � 
//����� � ������� ������� � �������[-100, 100] - ��������� �� ������� � 
//�������� ��������� � ��������� ������ ���� ������� ����� ����������� 
//���� ��������� � ������ � ��������� ����� ������� � ������ ����.
//
//������:
//
//Input bitcoin : 1000
//Input change % : -10
//You now have 900 bitcoins!
//The change in your balance is - 100.
#include <iostream>
using namespace std;

int main()
{
	double bitcoin;
	//Input bitcoin 
	cin >> bitcoin;
	if (bitcoin < 0)
	{
		cerr << "bitcoin must be > 0";
	}

	double change;
	cin >> change;

	// ( part * 100 ) / whole = percent
	// part * 100 = whole * percent
	// part =  ( whole * percent ) / 100
	double part = (bitcoin * change) / 100;
	double result = bitcoin + part;
	cout << result;
}