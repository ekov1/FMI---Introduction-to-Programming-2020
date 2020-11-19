// Напишете програма, която прочита 2 цели числа num 
// и n и принтира стойността на n - тия бит на num.
// Вход:  19006 // 0b01001010'00111110
// 5
// Изход : 1

#include <iostream>

int main()
{
    int num, n;
    std::cin >> num >> n;

    int mask = 1 << n;

    int bit = (num & mask) >> n;
    std::cout << bit;

}