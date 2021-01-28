// Намерете корените на уравнението x^2 + 3x - 4 = 0
#include <iostream>
using namespace std;
int main()
{
	double a = 1;
	double b = 3;
	double c = 4;

	// D = b^2 - 4ac
	double D = pow(b, 2) + 4 * a * c;

	if (D >=0)
	{
		// x1,2 = ( -b +- sqrt(D) ) / 2a
		double x1 = (-b + sqrt(D)) / 2 * a;
		double x2 = (-b - sqrt(D)) / 2 * a;
		cout << x1 << " " << x2 << endl;
	}
	else
	{
		// no real roots
	}

}

