// Напишете програма, която прочита цяло число 
// и казва дали то е нечетно(използвайки само побитови операции).

#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int mask = 1;

    int bit = num & mask;
    //std::cout << bit << std::endl;
    std::cout << (bit ? "No" : "Yes") << std::endl;
}
