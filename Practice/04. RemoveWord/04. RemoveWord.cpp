// 04. RemoveWord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

int main()
{
	std::cout << "Hello World!\n";
}

void RemoveWordV1(char* str, const char* word) {
	int len = strlen(str);
	int wordLen = strlen(word);

	for (int i = 0; i < len; i++)
	{
		if (strncmp(word, str + i, wordLen))
		{
			for (int j = i; j < len-wordLen; ++j)
			{
				str[j] = str[j + wordLen];
			}
			len -= wordLen;
		}
	}
	str[len] = '\0';
}


