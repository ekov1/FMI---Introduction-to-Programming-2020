//������ 3: ����� � ���������
//�������� ��������, ����� ��� ������� ������ r � ���������� �� ����� x y, ��������, ���� ������� �� ������ � ��������� � ������(0, 0) � ������ r.
//
//������ : ���� : 3 2 2 ����� : true ���� : 2 1 - 2 ����� : false

#include <iostream>
using namespace std;
int main()
{
	double r;
	cin >> r;

	// circle
	double x1 = 0;
	double y1 = 0;

	// point
	double x2;
	double y2;
	cin >> x2 >> y2;

	double d = sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));

	bool result = false;
	if (pow(d, 2) < pow(r, 2))
	{
		result = true;
	}
	cout << (result ? "true" : "false");
}

