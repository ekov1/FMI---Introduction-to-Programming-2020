// Напишете функция, която изкарва на конзолата само простите числа,
// които са елементи на масив с размер n, предварително попълнен
// с числа, прочетени от клавиатурата.

#include <iostream>

void ReadInput(int arr[], unsigned& n);
bool IsPrime(int x);
void GetPrimes(int arr[], unsigned n);

int main()
{
	unsigned n;
	int arr[1024];

	ReadInput(arr, n);
	GetPrimes(arr, n);
}

void GetPrimes(int arr[], unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		if (IsPrime(arr[i]))
		{
			std::cout << arr[i] << " ";
		}
	}
}

bool IsPrime(int x) {
	bool isPrime = true;

	for (size_t i = 2; i < sqrt(x + 1); i++)
	{
		if (x % i == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
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