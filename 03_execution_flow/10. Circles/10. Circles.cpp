// Нека определяме окръжност по 2 неща - точка и радиус.
// По въведени данни за 2 окръжности определете в какво състояние се намират те -
// дали се пресичат, допират или не се пресичат).

#include <iostream>

int main()
{
    const float EPS = 1E-3; // 1 * 10^(-3);     0.001

    double x1, y1, x2, y2, r1, r2;
    std::cout << "enter x y r for first circle \n";
    std::cin >> x1 >> y1 >> r1;
    std::cout << "enter x y r for second circle \n";
    std::cin >> x2 >> y2 >> r2;

    double distX = x1 - x2;


    std::cout << "Hello World!\n";
}
