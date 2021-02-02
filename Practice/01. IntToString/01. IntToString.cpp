#include <iostream>
#include <cmath>
#include <cstring>

int main()
{
	std::cout << "Hello World!\n";
}

//char* IntToString(unsigned num) {
//	unsigned numLength = log10(num) + 1;
//	char* str = new char[numLength + 1];
//	str[numLength] = '\0';
//	for (unsigned i = numLength - 1; i >= 0; --i)
//	{
//		str[i] = '0' + num % 10;
//		num /= 10;
//	}
//
//	return str;
//}

int StringToInt(const char* str) {
	int num = 0;

	for (int i = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; ++i)
	{
		num *= 10;
		num += str[i] - '0';
	}

	return num;
}
//
//char* GetFirstN(const char* str, int n) {
//	if (n > strlen(str)) {
//		return nullptr;
//	}
//	char* newStr = new char[n + 1];
//	strncpy(newStr, str, n);
//	newStr[n] = '\0';
//	return newStr;
//}
