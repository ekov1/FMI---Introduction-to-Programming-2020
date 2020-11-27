//Напишете функция, която проверява дали масив е сортиран в низходящ ред.
//
//Пример:
//Вход:
// 5
// 30 25 13 9 4
//Изход : The array is sorted in descending order

//5
// -2 -5 -10 -15 -20

//5
// -2 -5 3 -15 -20

#include <iostream>

int const MAX_SIZE = 1024;

void ReadArr(int arr[], int arrSize);
void PrintArr(int arr[], int arrSize);
bool IsSortedDescending(int arr[], int arrSize);

int main()
{
	int arr[MAX_SIZE];
	int arrSize;
	std::cin >> arrSize;

	ReadArr(arr, arrSize);
	bool isSortedDescending = IsSortedDescending(arr, arrSize);
	std::cout << (isSortedDescending ? "The array is sorted in descending order" : "The array is NOT sorted in descending order") << std::endl;

	//PrintArr(arr, arrSize);
}

bool IsSortedDescending(int arr[], int arrSize) {
	bool result = true;

	for (size_t i = 0; i < arrSize - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			result = false;
			break;
		}
	}

	return result;
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