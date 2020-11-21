// Напишете функция, която прочита масив от цели числа с размер n
// и връща сумата от елементите, които се намират на четна позиция.

#include <iostream>
void ReadArrReturnSumOfEvenElemnts(int arr[], unsigned& n);

int main()
{
	unsigned n;
	int arr[1024];

	ReadArrReturnSumOfEvenElemnts(arr, n);
}

void ReadArrReturnSumOfEvenElemnts(int arr[], unsigned& n) {
	int sum = 0;
	std::cout << "Enter arr size : ";
	std::cin >> n;

	std::cout << "Enter arr elements" << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		if (i % 2 == 0) {
			sum += arr[i];
		}
	}

	std::cout << "sum = " << sum;
}

