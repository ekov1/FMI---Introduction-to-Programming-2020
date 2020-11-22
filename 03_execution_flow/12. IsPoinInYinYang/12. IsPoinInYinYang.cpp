#include <iostream>
// 00 е в 2те полета
int main()
{
	float x, y;
	std::cout << "enter point x y : ";
	std::cin >> x >> y;

	float distFromCenter = sqrt((x * x) + (y * y));
	if (distFromCenter == 4) {
		std::cout << "point is on contur";
	}
	if (distFromCenter > 4) {
		std::cout << "point is ouside";
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
	if ((0 < x && x < 4) && (0 <= y && y < 4)) {
		// small black circle
		float distX = abs(0 - x);
		float distY = abs(2 - y);
		float distAB = sqrt((distX * distX) + (distY * distY));
		if (distAB <= 1) {
			std::cout << "point is in black space";
		}
		else if (1 < distAB && distAB <= 2) {
			std::cout << "point is in white space";
		}
		else {
			std::cout << "point is in black space";
		}
	}

	// 3ти квадрант
	if ((-4 < x && x < 0) && (-4 < y && y < 0)) {
		// малък бял кръг
		float distX = abs(0 - x);
		float distY = abs(-2 - y);
		float distAB = sqrt((distX * distX) + (distY * distY));
		if (distAB <= 1) {
			std::cout << "point is in white space";
		}
		else if (1 < distAB && distAB <= 2) {
			std::cout << "point is in black space";
		}
		else {
			std::cout << "point is in white space";
		}
	}

	//4ти квадрант
	if ((0 <= x && x < 4) && (-4 < y && y <= 0)) {
		float distX = abs(0 - x);
		float distY = abs(-2 - y);
		float distAB = sqrt((distX * distX) + (distY * distY));
		if (distAB >= 1) {
			std::cout << "point is in black space";
		}
		else {
			std::cout << "point is in white space";
		}
	}
}


