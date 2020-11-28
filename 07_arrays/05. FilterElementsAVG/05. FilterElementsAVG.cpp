//Въведете цяло число N, не по - голямо от 1000, следвано от N числа с плаваща точка.
//Съхранете ги в масив.Изведете го на екрана.След това премахнете всички числа от масива,
//по - малки от средно - аритметичното на всички въведени числа и отново изведете числата на екрана.
//
//Пример:
//
//Вход:
//10
//1 2 3 3 2 4 2 1 2 3
//Изход :
//    1 2 3 3 2 4 2 1 2 3
//    3 3 4 3

#include <iostream>

int const MAX_SIZE = 1024;

void ReadArr(float arr[], int arrSize);
void PrintArr(float arr[], int arrSize);
float CalculateAvg(float arr[], int arrSize);
void RemoveElement(float arr[], int& arrSize, float element);
void RemoveElements(float arr[], int& arrSize, float avg);

int main()
{
	float arr[MAX_SIZE];
	int n;
	std::cin >> n;
	ReadArr(arr, n);
	PrintArr(arr, n);
	float avg = CalculateAvg(arr, n);
	RemoveElements(arr, n, avg);
	PrintArr(arr, n);
}

void RemoveElements(float arr[], int& arrSize, float avg) {
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i] < avg)
		{
			RemoveElement(arr, arrSize, arr[i]);
			--i;
		}

	}
}

void RemoveElement(float arr[], int& arrSize, float element) {
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

float CalculateAvg(float arr[], int arrSize) {
	float sum = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		sum += arr[i];
	}
	float avg = sum / arrSize;
	return avg;
}

void ReadArr(float arr[], int arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cin >> arr[i];
	}
}

void PrintArr(float arr[], int arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}
