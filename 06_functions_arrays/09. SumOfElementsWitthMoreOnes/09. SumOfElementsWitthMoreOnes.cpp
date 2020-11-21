// Напишете функция, която връща сумата на всички елементи на масива,
// които имат повече вдигнати битове(1ци) отколкото свалени(0ли).
// 0 1 2  3  4   5
// 0 1 10 11 100 101
// 1 + 3 + 5 = 9

#include <iostream>

void ReadInput(int arr[], unsigned& n);
bool HaveMoreOnes(int n);
void GetSum(int arr[], int n, int& sum);

int main()
{
	unsigned n;
	int sum = 0;
	int arr[1024];

	ReadInput(arr, n);
	GetSum(arr, n, sum);

	std::cout << "sum = " << sum << std::endl;
}

void GetSum(int arr[], int n, int& sum) {
	for (size_t i = 0; i < n; i++)
	{
		if (HaveMoreOnes(arr[i]))
		{
			sum += arr[i];
		}
	}
}

bool HaveMoreOnes(int n)
{
	bool correct = false;
	unsigned remainder;
	int flagNumberStart = 0;

	short i = 31;
	short bit, ones = 0, zeros = 0;
	while (i >= 0)
	{
		bit = (n & (1 << i)) >> i;
		if (bit == 1) {
			ones++;
			if (flagNumberStart == 0) {
				flagNumberStart = 1;
			}
		}
		else
		{
			if (flagNumberStart) {
				zeros++;

			}
		}
		i--;
	}

	if (ones > zeros)
	{
		correct = true;
	}

	return correct;
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