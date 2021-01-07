// 08. EuclideanAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
unsigned NOD(unsigned a, unsigned b);
int main()
{
    std::cout << NOD(1071,1029);
}

unsigned NOD(unsigned a,unsigned b) {
    if (b == 0)
        return a;
    else
        return NOD(b, a % b);
}

