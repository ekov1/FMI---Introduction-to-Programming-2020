#include <iostream>

using namespace std;


void PrintIToN(int i, int n);
int* GetEvenNumbers(int* arr, int n, int* evenCount);

int main() {
	PrintIToN(15, 20);

	char str[64];
	//cin >> str;
	cin.getline(str, 64, ' ');
	cout << str;

}

void PrintIToN(int i, int n) {
	cout << i << " ";
	if (i == n)
	{
		cout << endl;
		return;
	}
	PrintIToN(i + 1, n);
}

int MainFacade1()
{
	int a = 15;
	int* pointer = &a;
	cout << &a << endl;
	cout << pointer << endl;
	cout << *pointer << endl;

	int arr[5];
	arr[0] = 15;
	arr[1] = 2;
	arr[2] = 7;
	arr[3] = 8;
	arr[4] = 6;


	cout << arr << " = " << *arr << *(arr + 1) << endl;
	// *(arr+i) <==> arr[i]

	//int n;
	//cin >> n;
	//int* dynamic = new int[n];


	int evenCount = 0;

	int* evenNumbers = GetEvenNumbers(arr, 5, &evenCount);

	for (int i = 0; i < evenCount; i++)
	{
		cout << evenNumbers[i];
	}

	int rows = 10;
	int cols = 20;

	int** table = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		table[i] = new int[cols];
	}

	//free used memory

	for (int i = 0; i < rows; i++)
	{
		delete[] table[i];
	}
	delete[] table;
	table = nullptr;

	delete[] evenNumbers;
	evenNumbers = nullptr;
	//delete[] dynamic;
	return 0;
}

int* GetEvenNumbers(int* arr, int n, int* evenCount) {
	*evenCount = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			++(*evenCount);
		}
	}

	int* result = new(nothrow) int[*evenCount];
	if (!result)
	{
		cerr << "could not alocate memory" << endl;
		return nullptr;

	}

	int index = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			result[index] = arr[i];
			index++;
		}
	}

	return result;
}

