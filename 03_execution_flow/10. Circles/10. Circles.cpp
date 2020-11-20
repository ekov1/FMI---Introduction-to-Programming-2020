// Нека определяме окръжност по 2 неща - точка и радиус.
// По въведени данни за 2 окръжности определете в какво състояние се намират те -
// дали се пресичат, допират или не се пресичат).
// 
// 0 0 5 и 12 9 10 се допират външно
// 0 0 5 и  12 9 8 не се допират
// 0 0 5 и 12 9 12 се пресичат
// 0 0 3 и  0 2 1 се допират върешно
// -1 0 3 и  3 -3 8 се допират върешно

#include <iostream>

int main()
{
    const float EPS = 1E-3; // 1 * 10^(-3);     0.001

    float x1, y1, x2, y2, r1, r2;
    std::cout << "enter x y r for first circle \n";
    std::cin >> x1 >> y1 >> r1;
    std::cout << "enter x y r for second circle \n";
    std::cin >> x2 >> y2 >> r2;

    float distX = abs(x2 - x1);
    float distY = abs(y2 - y1);
    float distAB = sqrt((distX * distX) + (distY * distY));

    float smallR, bigR;
    if (r1 > r2) {
        bigR = r1;
        smallR = r2;
    }
    else {
        bigR = r2;
        smallR = r1;
    }


    if (distAB == r1+r2)
    {
        std::cout << "circles touching externally!\n";
    }
    else if (distAB > r1 + r2) {
        std::cout << "circles are not touching !\n";
    }
    else if (distAB + smallR == bigR) {
        std::cout << "circles touching internally!\n";
    }
    else if (bigR - distAB < smallR) {
        std::cout << "circles are crossing !\n";
    }
    else if (distAB < r1 + r2 ) {
        std::cout << "circles are crossing !\n";
    }

    
}
