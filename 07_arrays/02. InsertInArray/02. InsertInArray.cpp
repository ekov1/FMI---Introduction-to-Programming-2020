// Напишете функция, която вмъква елемент в сортиран във възходящ ред масив, като след
// вмъкването, масивът остава сортиран.
// Ако напълним целия масив, при следващо добавяне изваждаме съобщение за грешка.
// 
// Пример:
// 
// Вход: 
// 6
// 1 4 7 12 32 59
// 15 4
// Изход : 1 4 7 12 15 32 59

#include <iostream>

int const MAX_SIZE = 1024;

void ReadArr(int arr[], int arrSize);
void PrintArr(int arr[], int arrSize);
bool InsertElement(int arr[], int& arrSize, int element, int index);

int main()
{
	int arrSize, element, index;
	std::cin >> arrSize;
	int arr[MAX_SIZE];
	ReadArr(arr, arrSize);
	//PrintArr(arr, arrSize);
	std::cin >> element >> index;
	bool result = InsertElement(arr, arrSize, element, index);
	PrintArr(arr, arrSize);

}

bool InsertElement(int arr[], int& arrSize, int element, int index) {
	bool result = true;

	if (arrSize + 1 > MAX_SIZE)
	{
		result = false;
	}

	if (result)
	{
		for (size_t i = arrSize - 1; i >= index; i--)
		{
			arr[i + 1] = arr[i];
		}

		arr[index] = element;
		++arrSize;
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