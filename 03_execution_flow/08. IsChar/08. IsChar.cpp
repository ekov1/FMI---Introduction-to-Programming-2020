// Напишете програма, която прочита символ и казва дали той е малка, главна
// или изобщо не е буква.

#include <iostream>

int main()
{
    char x;
    std::cin >> x;

    if ('a' <= x && x <= 'z') {
        std::cout << "lower case letter \n";
    }
    else if ('A' <= x && x <= 'Z') {
        std::cout << "Capital letter \n";
    }
    else {
        std::cout << "not a letter \n";
    }
}