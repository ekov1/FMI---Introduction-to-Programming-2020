#include <iostream>
using namespace std;
void PrintArrRec(int* arr, int arrSize, int index = 0);
bool IsSortedRec(int* arr, int arrSize, int index = 0);
void SortArrRec(int*& arr, int arrSize);
int main()
{
	int arrSize = 5;
	int* arr = new int[arrSize] { 1, 3, 2, 5, 4 };
	//int* arr = new int[arrSize] { 1, 3, 4, 5, 6 };
	PrintArrRec(arr, arrSize,0);
	SortArrRec(arr, arrSize);
	PrintArrRec(arr, arrSize);
	cout << IsSortedRec(arr, arrSize);
	delete[] arr;
	return 0;
}

void PrintArrRec(int* arr, int arrSize, int index) {
	if (index == arrSize)
	{
		cout << endl;
		return;
	}

	cout << arr[index] << " ";
	PrintArrRec(arr, arrSize, index + 1);
}

void SortArrRec(int*& arr, int arrSize) {
	if (IsSortedRec(arr, arrSize))
	{
		return;
	}

	for (int i = 0; i < arrSize - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	SortArrRec(arr, arrSize);
}

bool IsSortedRec(int* arr, int arrSize, int index) {
	if (index == arrSize - 1)
	{
		return true;
	}

	if (arr[index] > arr[index + 1])
	{
		return false;
	}

	return IsSortedRec(arr, arrSize, index + 1);
}

