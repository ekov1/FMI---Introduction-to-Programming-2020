#include <iostream>

using std::cout;
using std::endl;

double Power(unsigned x, unsigned n);

int main()
{
	for (size_t i = 0; i < 7; i++)
	{
		cout << i << " pow " << i << " = " << Power(i, i) << endl;
	}
}

// calculate x powered n
// classical linear reursive algorithm
double Power(unsigned x, unsigned n) {
	if (n == 0)
	{
		return 1;
	}
	else {
		return x * Power(x, n - 1);
	}
}