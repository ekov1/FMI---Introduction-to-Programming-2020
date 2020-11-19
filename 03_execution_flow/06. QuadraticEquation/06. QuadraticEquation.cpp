// От конзолата се прочитат 3 цели числа, а,b и c, които представляват
// коефициенти на квадратно уравнение.Да се намерят неговите корени,
// и да се отпечатат на екрана.
// 2.5 -5 6 no roots
// 1 -2 1 d=0
// 1 -5 -6

#include <iostream>

int main()
{
	double a, b, c;
	std::cin >> a >> b >> c;

	// calculate the discriminant 
	double D = (b * b) - (4 * a * c);

	if (D >= 0) {
		double x1, x2;
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		std::cout << "The equation has roots" << std::endl;
		std::cout << "x1 = " << x1 << " x2 = " << x2 << std::endl;

	}
	else {
		std::cout << "The equation has no real roots!" << std::endl;
	}
}