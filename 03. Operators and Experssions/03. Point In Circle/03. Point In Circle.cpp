//Задача 3: Точка в окръжност
//Напишете програма, която при въведен радиус r и координати на точка x y, определя, дали точката се намира в окръжност с център(0, 0) и радиус r.
//
//Пример : Вход : 3 2 2 Изход : true Вход : 2 1 - 2 Изход : false

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

