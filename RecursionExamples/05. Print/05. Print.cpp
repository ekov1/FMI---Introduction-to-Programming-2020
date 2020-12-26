#include <iostream>
using std::cout;
using std::endl;

void Print(int* arr, int n);

int arr[5] = { 0,1,2,3,4 };// = 10
int main()
{
	Print(arr,5);
}

void Print(int* arr, int n) {
	if (n != 0)
	{
		cout << *arr << " ";
		Print(arr + 1, n - 1);
	}
}