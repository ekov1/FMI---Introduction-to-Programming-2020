// Напишете програма, която прочита 2 цели 
// числа num и n и слага стойност 0 на n - тия бит на num.

#include <iostream>

int main()
{
    int num, n;
    std::cin >> num >> n;

    int mask = 1 << n;

    num = num & (~mask);
    std::cout << num;
}