// Напишете функция, която връща индекса на началото на най-дългата последователност
// от еднакви числа в масив от цели числа.

#include <iostream>
void ReadInput(int arr[], unsigned& n);
void GetLongestSeq(int arr[], unsigned n);

int main()
{
	unsigned n;
	int arr[1024];

	ReadInput(arr, n);
	GetLongestSeq(arr, n);
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

void GetLongestSeq(int arr[], unsigned n) {
	int bestNum;
	int bestLength = 0;
	int currentNum = arr[0];
	int currentLength = 0;
	int currentIndex = 0;
	int bestIndex = 0;

	for (size_t i = 0; i < n - 1; i++)
	{
		if (arr[i] == currentNum)
		{
			currentLength++;
		}
		else {
			if (currentLength > bestLength)
			{
				bestLength = currentLength;
				bestNum = currentNum;
				bestIndex = currentIndex;
			}
			currentNum = arr[i];
			currentLength = 1;
			currentIndex = i;
		}
	}

	if (currentLength > bestLength)
	{
		bestLength = currentLength;
		bestNum = currentNum;
	}

	std::cout << "index = " << bestIndex << std::endl;
	std::cout << "best num = " << bestNum << " seqL = " << bestLength << std::endl;
}