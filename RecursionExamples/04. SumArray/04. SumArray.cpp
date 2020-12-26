#include <iostream>

using std::cout;
using std::endl;

int arr[5] = { 0,1,2,3,4 };// = 10

int SumL(int* arr, unsigned n);
int SumR(int* arr, unsigned n);
int SumAcc(int* arr, unsigned n, int res = 0);

int main()
{
	cout << SumL(arr, 5) << endl;
	cout << SumR(arr, 5) << endl;
	cout << SumAcc(arr, 5) << endl;

}

// three different functions to calculate te sum of an array
int SumL(int* arr, unsigned n) {
	if (n == 0)
	{
		return 0;
	}
	else {
		return arr[n - 1] + SumL(arr, n - 1);
	}
}

int SumR(int* arr, unsigned n) {
	if (n == 0)
	{
		return 0;
	}

	return *arr + SumR(arr + 1, n - 1);
}

int SumAcc(int* arr, unsigned n, int res) {
	if (!n)
		return res;

	return SumAcc(arr + 1, n - 1, res + *arr);
}