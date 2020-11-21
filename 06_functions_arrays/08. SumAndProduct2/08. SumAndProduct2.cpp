// Напишете функция, която връща разликата на произведението на елементите
// с четни индекси(P) и сумата на елементите с нечетни индекси(S).
// (P - S) = ?

//Пример :
//
//    Вход : 5
//    4 2 7 4 1
//    Изход : 22
#include <iostream>

void ReadInputAdCalculate(int arr[], unsigned& n, int& sum, int& product);

int main()
{
	unsigned n;
	int arr[1024];
	int sum = 0, product = 1;

	ReadInputAdCalculate(arr, n, sum, product);
}

void ReadInputAdCalculate(int arr[], unsigned& n, int& sum, int& product) {
	std::cout << "Enter arr size : ";
	std::cin >> n;

	std::cout << "Enter arr elements" << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];

		if (i % 2 == 0) {
			product *= arr[i];
		}
		else {
			sum += arr[i];
		}
	}

	std::cout << "(P - S) =" << (product - sum);
}