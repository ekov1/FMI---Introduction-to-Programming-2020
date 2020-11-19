// Задача 1: Степенуване на втора степен
// Напишете програма която получава две числа и и използвайки, x k
// побитови операции умножава числото по, x 2 ^ k.
// Вход : 5 3
// Изход : 40 (5 * 2 ^ 3 = 5 * 8 = 40)

#include <iostream>

using std::cout;
using std::cin;


// A method to multiply two numbers using Russian Peasant method
unsigned int russianPeasant(unsigned int a, unsigned int b)
{
    int res = 0;  // initialize result 

    // While second number doesn't become 1 
    while (b > 0)
    {
        // If second number becomes odd, add the first number to result 
        if (b & 1)
            res = res + a;

        // Double the first number and halve the second number 
        a = a << 1;
        b = b >> 1;
    }
    return res;
}

unsigned int TwoToPow(unsigned int pow)
{
    int res = 1;  // initialize result 

    for (int i = 0; i < pow; i++)
    {
        res = russianPeasant(res, 2);
    }
    
    return res;
}

int main()
{
    int x;
    cout << "enter x: ";
    cin >> x;

    int k;
    cout << "enter k: ";
    cin >> k;

    int result = russianPeasant(x, TwoToPow(k));

    cout << " x 2 ^ k" << '\n';
    cout << result << '\n';


}

