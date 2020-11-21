// Напишете функции, които намират най-големия/най-малкия
// елемент в масив, отпечатвайки индекса и стойността му.
#include <iostream>

void ReadInput(int arr[], unsigned& n);
void BigAndSmall(int arr[], unsigned n);

int main()
{
	unsigned n;
	int arr[1024];

	ReadInput(arr, n);
	BigAndSmall(arr, n);
}

void BigAndSmall(int arr[], unsigned n) {
	int big = arr[0];
	int small = arr[0];
	int bigIndex = 0, smallIndex = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] > big)
		{
			big = arr[i];
			bigIndex = i;
		}

		if (arr[i] < small)
		{
			small = arr[i];
			smallIndex = i;
		}
	}

	std::cout << "big = " << big << " index = " << bigIndex << std::endl;
	std::cout << "small = " << small << " index = " << smallIndex << std::endl;

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