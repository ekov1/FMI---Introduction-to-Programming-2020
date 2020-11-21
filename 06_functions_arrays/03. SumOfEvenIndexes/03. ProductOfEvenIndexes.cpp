// Напишете функция, която връща произведението на всички индекси,
// на които има нечетни числа.

#include <iostream>
void ReadInput(int arr[], unsigned& n);
int GetProduct(int arr[], unsigned n);

int main()
{
	unsigned n;
	int arr[1024];

	ReadInput(arr, n);
	int product =GetProduct(arr, n);
	std::cout << "product = " << product << std::endl;
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

int GetProduct(int arr[], unsigned n) {
	int product = 1;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0) {
			product *= i;
		}
	}

	return product;
}