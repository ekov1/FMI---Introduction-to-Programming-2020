// Напишете функция, която изтрива елемент от сортиран във възходящ ред масив, като
// след изтриването, масивът остава сортиран.
// 
// Пример:
// 
// Вход: 
// 6
// 1 4 7 12 32 59
// 7
// Изход : 1 4 12 32 59

#include <iostream>

int const MAX_SIZE = 1024;

void ReadArr(int arr[], int arrSize);
void PrintArr(int arr[], int arrSize);
void RemoveElement(int arr[], int& arrSize, int index);

int main()
{
	int arr[MAX_SIZE];
	int arrSize, index;
	std::cin >> arrSize;
	ReadArr(arr,arrSize);
	PrintArr(arr, arrSize);
	std::cin >> index;
	RemoveElement(arr, arrSize, index);
	PrintArr(arr, arrSize);
}

void RemoveElement(int arr[], int& arrSize, int index) {

	for (size_t i = index; i < arrSize-1; i++)
	{
			arr[i] = arr[i + 1];
	}

	--arrSize;
}

void ReadArr(int arr[], int arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cin >> arr[i];
	}
}

void PrintArr(int arr[], int arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}