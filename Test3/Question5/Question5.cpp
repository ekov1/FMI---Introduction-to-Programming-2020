// Question5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int X = 42;
    if (X % 2 && X < 100) X = 10;
    std::cout << X % 2 << '\n';

    if (X < 20) X += 25;
    else if (X < 0 || X > 50) X = 15;
    else X = 7;
    std::cout << X % 10 << '\n';
    X = X % 10;
  

    std::cout << X;
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
