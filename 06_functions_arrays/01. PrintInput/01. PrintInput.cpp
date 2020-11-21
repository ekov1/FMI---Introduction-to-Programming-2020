// Напишете функция, която прочита елементите от конзолата на едномерен
// масив с дължина n(отново въведена от конзолата) и функция,
// която изкарва въведените елементите на конзолата.

#include <iostream>
void ReadInput(int arr[], unsigned& n);
void PrintArr(int arr[], unsigned n);

int main()
{
	unsigned n;
	int arr[1024];

	ReadInput(arr, n);
	PrintArr(arr, n);
}

void ReadInput(int arr[], unsigned& n) {
	std::cout << "Enter arr size : ";
	std::cin >> n;

	std::cout << "Enter arr elements" << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

void PrintArr(int arr[], unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
}