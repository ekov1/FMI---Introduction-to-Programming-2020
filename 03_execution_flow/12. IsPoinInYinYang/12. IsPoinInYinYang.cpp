#include <iostream>

int main()
{
	float x, y;
	std::cin >> x >> y;

	float distFromCenter = sqrt((x * x) + (y * y));
	if (distFromCenter == 4) {
		std::cout << "point is on contur";
	}

	// 2ри квадрант
	if ((-4 < x && x <= 0) && (0 <= y && y < 4)) {
		float distX = abs(0 - x);
		float distY = abs(2 - y);
		float distAB = sqrt((distX * distX) + (distY * distY));
		if (distAB >= 1) {
			std::cout << "point is in white space";
		}
		else {
			std::cout << "point is in black space";
		}
	}

	// 1ви квадрант

}


