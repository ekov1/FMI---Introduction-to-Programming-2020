// Задача 1
// Дадена е декартова координатна система.Всеки правоъгълник със страни успоредни на
// координатните оси в нея може да се определи с четири числа с плаваща точка : координатите
// на долния си ляв ъгъл(x, y), ширината и дължината си.
// Напише програма, която прочита от стандартния вход данни за два правоъгълника и извежда
// на екрана лицето на общата им част.Ако правоъгълниците нямат обща част, приемаме
// лицето за нула.

#include <iostream>

using std::cin;
using std::cout;

float calcSide(float leftX, float leftWidth, float rightX, float rightWidth) {
	float leftX1 = leftX + leftWidth;
	float rightX1 = rightX + rightWidth;
	float side = 0;

	if (rightX < leftX1 && leftX1 < rightX1) {
		side = leftX1 - rightX;
	}
	else if (rightX < leftX1 && rightX1 <= leftX1) {
		side = rightWidth;
	}

	return side;
}

int main()
{
	float aX, aY, aWidth, aHeight;
	//cout << "Enter x y w h" << '\n';
	cin >> aX >> aY >> aWidth >> aHeight;

	float bX, bY, bWidth, bHeight;
	cin >> bX >> bY >> bWidth >> bHeight;

	if (!cin) {
		cout << "Your input was invalid.";
		return 0;
	}

	// S = a * b
	float a, b;
	if (aX < bX) {
		a = calcSide(aX, aWidth, bX, bWidth);
	}
	else {
		a = calcSide(bX, bWidth, aX, aWidth);
	}
	//std::cout << "a = " << a << '\n';

	if (aY < bY) {
		b = calcSide(aY, aHeight, bY, bHeight);
	}
	else {
		b = calcSide(bY, bHeight, aY, aHeight);
	}
	//std::cout << "b = " << b << '\n';

	float S;
	if (a > 0 && b > 0) {
		S = a * b;
	}
	else {
		S = 0;
	}

	//cout << "S = " << S;
	cout << S;

}