//Работим в двумерна декартова координатна система.
//
//По дадени x и y координатите на две точки, да се намери разстоянието между тях.
//
//Пример: А(0, 0), B(3, 4)
//
//distance(A, B) = 5

#include <iostream>
using namespace std;
int main()
{
	// A
	double x1 = 0;
	double y1 = 0;

	// B
	double x2 = 3;
	double y2 = 4;

	double distAB = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	cout << distAB << endl;

	// A
	double c1 = 7;

	// B
	double c2 = 3;
	distAB = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((y2 - y1), 2));
	cout << distAB;
}