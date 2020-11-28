// Напишете фунцкия, която приема два масива arr_1 и arr_2, като
// "филтрира" всички четни елементи от arr_1 в arr_2 в сортиран вид.
// 
// Пример:
// 
// arr_1: 7{ 3 12 5 2 3 8 4 }
// arr_2: 5{ 2 4 8 12 5}

// arr1 6{ 1 6 3 4 5 2}
// arr2 8{ 1 8 3 5 4 6 7 2}

#include <iostream>

int const MAX_SIZE = 1024;

void ReadArr(int arr[], int arrSize);
void PrintArr(int arr[], int arrSize);
void GetEvenElements(int arr[], int arrSize, int evenElements[], int& evenElementsSize);
void RemoveElement(int arr[], int& arrSize, int element);
void RemoveElements(int arr[], int& arrSize, int evenElements[], int evenElementsSize);

int main()
{
	int arr_1[MAX_SIZE], arr_2[MAX_SIZE], arr_evenElements[MAX_SIZE];
	int arrSize1, arrSize2, evenElementsSize = 0;
	std::cin >> arrSize1;
	ReadArr(arr_1, arrSize1);
	std::cin >> arrSize2;
	ReadArr(arr_2, arrSize2);
	GetEvenElements(arr_1, arrSize1, arr_evenElements, evenElementsSize);
	//PrintArr(arr_evenElements, evenElementsSize);
	RemoveElements(arr_2, arrSize2, arr_evenElements, evenElementsSize);
	PrintArr(arr_2, arrSize2);
}

void RemoveElements(int arr[], int& arrSize, int evenElements[], int evenElementsSize) {
	for (size_t i = 0; i < evenElementsSize; i++)
	{
		RemoveElement(arr, arrSize, evenElements[i]);
	}
}

void RemoveElement(int arr[], int& arrSize, int element) {
	int index = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i] == element) {
			index = i;
			break;
		}
	}

	for (size_t i = index; i < arrSize - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	--arrSize;
}

void GetEvenElements(int arr[], int arrSize, int evenElements[], int& evenElementsSize) {
	int indexEven = 0;

	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i] % 2 == 0)
		{
			evenElements[indexEven] = arr[i];
			indexEven++;
			evenElementsSize++;
		}
	}
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