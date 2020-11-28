// Нека имаме масив от цени, за който i - тия елемент е цената на дадена акция(stock)
// в ден i.Напишете функция, която намира максималната печалба, която можем да направим
// купувайки и продавайки тези акции.Можете да изпълните, колкото транзакции пожелаете(т.е да купите и
//     и продадете една акция няколко пъти), но задължително
//     трябва да продадете акцията преди отново да закупите.
// 
//     Пример 1:
// 
// Вход: [7, 1, 5, 3, 6, 4]
// Изход : 7
// Обяснение : Купуваме в ден 2(price = 1) и продаваме в ден 3(price = 5), profit = 5 - 1 = 4
// След това купуваме в ден 4(price = 3) и продаваме в ден 5(price = 6), profit = 6 - 3 = 3
// Пример 2 :
// 
//     Вход : [1, 2, 3, 4, 5]
//     Изход : 4
//     Обяснение : Купуваме в ден 1(price = 1) и продаваме в ден 5(price = 5), profit = 5 - 1 = 4
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
