#include <iostream>

using std::cout;
using std::endl;

unsigned long long Fibonacci(unsigned n);
static unsigned long long FibRec(unsigned n, unsigned long long f1, unsigned long long f2);
unsigned long long FibWrapper(unsigned n);

int main()
{
    for (size_t i = 0; i < 7; i++)
    {
        cout << i << " = " << Fibonacci(i) << endl;
        cout << i << " = " << FibRec(i,0,1) << endl;
        cout << i << " = " << FibWrapper(i) << endl;

        cout << endl;
    }
}

// Fibonacci numbers
// basic example of direct, multiple recursion
unsigned long long Fibonacci(unsigned n) {
    if (n < 2) {
        return 1;
    }
    else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

// optimized version - tail and linear recursion
static unsigned long long FibRec(unsigned n, unsigned long long f1, unsigned long long f2) {
    if (n==0)
    {
        return f2;
    }
    else {
        return FibRec(n - 1, f2, f2 + f1);
    }
}

// wrapper
// hide additional parameters
unsigned long long FibWrapper(unsigned n) {
    return FibRec(n, 0, 1);
}

