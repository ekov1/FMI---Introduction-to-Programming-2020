
#include <iostream>

int main()
{
	double x, y;
	std::cin >> x >> y;

	float distFromCenter = sqrt((x * x) + (y * y));

	if ((distFromCenter <= 2 && y >= 0)|| ((-1 <= x && x <= 1) && (0 <= y && y >= -4))) {
		std::cout << "point inside figure \n";
	}
	else {
		std::cout << "point outside figure \n";
	}

		
}

