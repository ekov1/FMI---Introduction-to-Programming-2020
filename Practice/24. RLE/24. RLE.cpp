// 24. RLE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
char* rleEncode(const char* text);
int main()
{
	const char* text = new char[10]{ 'e','e','s','e','e','e','e','e' };
	const char* result = rleEncode(text);

	for (int i = 0; result[i] != '\0'; ++i)
	{
		cout << result[i] << " ";
	}
}

char* rleEncode(const char* text) {
	char* result = new char[0];
	int resultSize = 0;

	char curChar = text[0];
	int curCharCnt = 0;

	for (int i = 0; text[i] != '\0'; ++i)
	{
		if (text[i] == curChar)
		{
			++curCharCnt;
		}
		else {
			int newResultSize;
			int curCntDigitsCnt = 0;
			int cpy = curCharCnt;
			int reverce = 0;
			while (cpy > 0) {
				reverce *= 10;
				int digit = cpy % 10;
				reverce += digit;
				++curCntDigitsCnt;
				cpy /= 10;
			}

			if (curCharCnt > 3)
			{
				newResultSize = resultSize + 2 + curCntDigitsCnt;
				char* temp = new char[newResultSize];
				int i = 0;
				for (; i < resultSize; i++)
				{
					temp[i] = result[i];
				}

				if (curCntDigitsCnt > 9)
				{
					
				}
				else {
					i = resultSize;
					temp[i] = '(';
					++i;
					temp[i] = '0' + curCharCnt;
					++i;
					temp[i] = curChar;
					++i;
					temp[i] = ')';
				}
				delete[] result;
				resultSize = newResultSize;
				result = temp;
			}
			else {
				newResultSize = resultSize + curCharCnt;
				char* temp = new char[newResultSize];
				int i = 0;
				for (; i < resultSize; i++)
				{
					temp[i] = result[i];
				}
				for (; i < newResultSize; i++)
				{
					temp[i] = curChar;
				}

				delete[] result;
				resultSize = newResultSize;
				result = temp;
			}
			curChar = text[i];
		}
	}
	return result;
}

void AddDigits(char*& arr, int index, int num) {
	int digit = num % 10;

}
