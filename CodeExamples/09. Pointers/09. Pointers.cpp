#include <iostream>

using std::cin;
using std::nothrow;

int main()
{
	std::cout << "Hello World!\n";
}

// reads size 
static int* ReadArrayDynamic(unsigned* size) {
	unsigned n;
	cin >> n;

	int* array = new (nothrow)int[n];
	if (!array)
	{
		return nullptr;
	}

	for (unsigned i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	*size = n;
	return array;
}
