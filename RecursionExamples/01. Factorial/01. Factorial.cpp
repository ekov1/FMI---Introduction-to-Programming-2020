#include <iostream>

using std::cout;
using std::endl;

unsigned long long Factorial(unsigned n);

int main()
{
	for (size_t i = 0; i < 7; i++)
	{
		cout << i << " = " << Factorial(i) << endl;
	}
}

// a traditional factorial function
// basic example of direct, linear recursion
unsigned long long Factorial(unsigned n) {
	if (n == 0)
	{
		return 1;
	}
	else {
		return n * Factorial(n - 1);
	}
}