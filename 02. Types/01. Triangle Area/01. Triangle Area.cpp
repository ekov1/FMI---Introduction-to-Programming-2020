//�� ������ 3 ������ �� ���������� �������� ���������� � ������ ��.
#include <iostream>

int main()
{
	// triangle sides
	int a = 5, b = 4, c = 3;

	// triangle perimeter
	int	P = a + b + c;

	int S = sqrt(P * (P - a) * (P - b) * (P - c));

}

