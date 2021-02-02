//2. Да се намери функция, която връща най - голямата 
//редица от повтарящи числа в подаден като аргумент масив.Да се използва само рекурсия.

#include <iostream>

using namespace std;

int* GetLongestSeqRec(int* numbers, int numbersLen, int index, int bestNum, int& bestSeqLen, int curSeqLen, int curNum);
int* GetLongestSeq(int* numbers, int numbersLen, int& bestSeqLen);

int main()
{
	int bestSeqLen = 0;
	int numbersLen = 9;
	int* numbers = new int[numbersLen] { 1, 1, 2, 3, 3, 3, 3, 5, 5 };
	int* bestSeq = GetLongestSeq(numbers, numbersLen, bestSeqLen);

	for (int i = 0; i < bestSeqLen; i++)
	{
		cout << bestSeq[i] << " ";
	}
	cout << endl;

	delete[] numbers;
	delete[] bestSeq;
	return 0;
}

int* GetLongestSeq(int* numbers, int numbersLen, int& bestSeqLen) {
	int curSeqLen = 1;
	int curNum = numbers[0];
	int* bestSeq;
	int index = 1;
	int bestNum = -1;

	return GetLongestSeqRec(numbers, numbersLen, index, bestNum, bestSeqLen, curSeqLen, curNum);
}

int* GetLongestSeqRec(int* numbers, int numbersLen, int index, int bestNum, int& bestSeqLen, int curSeqLen, int curNum) {
	if (index == numbersLen || numbers[index] != curNum)
	{
		if (curSeqLen > bestSeqLen)
		{
			bestSeqLen = curSeqLen;
			bestNum = curNum;
		}

		if (index < numbersLen)
		{
			curSeqLen = 1;
			curNum = numbers[index];
		}
	}
	else {
		++curSeqLen;
	}

	if (index == numbersLen)
	{
		int* bestSeq = new int[bestSeqLen];
		for (int i = 0; i < bestSeqLen; ++i)
		{
			bestSeq[i] = bestNum;
		}

		return bestSeq;
	}

	return GetLongestSeqRec(numbers, numbersLen, index + 1, bestNum, bestSeqLen, curSeqLen, curNum);

}