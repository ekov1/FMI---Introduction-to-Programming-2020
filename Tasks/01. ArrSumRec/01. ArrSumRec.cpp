#include <iostream>

using std::cout;

int Sum(int arr[], int sum, int i);

int main() {
	int numbers[5] = { 1,2,2,1,4 };
	int sum = 0;
	int i = 4;//num length-1
	sum = Sum(numbers, sum, i);
	cout << sum;
}

int Sum(int arr[], int sum, int i) {
	sum += arr[i];

	if (i == 0)
	{
		return sum;
	}

	i--;
	return Sum(arr, sum, i);
}