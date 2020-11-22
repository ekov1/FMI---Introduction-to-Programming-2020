// Нека е дадена стандартна колода от карти съдържаща всички 
// карти от всички бои - общо 52 на брой. Приемаме, че картите 
// са подредени както в неразопаковано ново тесте - за всяка боя 
// имаме [А, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K], а боите съответно 
// са подредени - спатия, каро, купа, пика. Целта на вашата програма 
// е по подадено цяло положително число к в интервала [0; 51] да 
// изведе картата (картинка и боя), която се намира на к-та позиция ю
// в тестето, подредено по дефинирания по-горе начин. При невалиден 
// вход програмата дава възможност за избор: ново въвеждане или 
// приключване на програмата.

// Пример:
// Вход:  13
// Изход : A Diamonds
// 16 -> 4 Diamonds
// 36 -> J Hearts

#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	n++;

	int cardPosition = n;
	if (14 <= n && n <= 26) {
		cardPosition = n - 13;
	}
	else if (27 <= n && n <= 39) {
		cardPosition = n - 26;
	}
	else {
		cardPosition = n - 39;
	}

	switch (cardPosition)
	{
		case 1: {
			std::cout << "A ";
			break;
		}case 11: {
			std::cout << "J ";
			break;
		}case 12: {
			std::cout << "Q ";
			break;
		}case 13: {
			std::cout << "K ";
			break;
		}
		default: {
			std::cout << cardPosition << " ";
			break;
		}
	}

	if (1 <= n && n <= 13) {
		std::cout << "Clubs";
	}
	else if (14 <= n && n <= 26) {
		std::cout << "Diamonds";
	}
	else if (27 <= n && n <= 39) {
		std::cout << "Hearts";
	}
	else {
		std::cout << "Spades";
	}

}