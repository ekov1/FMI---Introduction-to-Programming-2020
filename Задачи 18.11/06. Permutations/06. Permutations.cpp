// Задача 6: Наишете функция, която приема масив с числа и 
// отпечатва всички възможни пермутации с тези стойности.

#include <iostream>

unsigned const MAX_SIZE = 1024;

unsigned arrDigits[MAX_SIZE];
unsigned permutationArr[MAX_SIZE];
bool used[MAX_SIZE];
unsigned arrSize;

void ReadArr(unsigned arr[], unsigned arrSize);
void PrintArr(unsigned arr[], unsigned arrSize);
unsigned Permutate(unsigned index);

int main()
{
	std::cin >> arrSize;
	ReadArr(arrDigits, arrSize);
	Permutate(0);
}

unsigned Permutate(unsigned index) {

	if (index >= arrSize) {
		PrintArr(permutationArr, arrSize);
		return 0;
	}

	for (size_t i = 0; i < arrSize; i++)
	{
		if (used[i] == false)
		{
			used[i] = true;

			permutationArr[index] = arrDigits[i];
			Permutate(index + 1);
			used[i] = false;
		}
	}

	return 0;
}

void ReadArr(unsigned arr[], unsigned arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cin >> arr[i];
		used[i] = false;
	}
}

void PrintArr(unsigned arr[], unsigned arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
}
