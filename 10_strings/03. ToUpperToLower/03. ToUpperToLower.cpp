#include <iostream>

using std::cout;
using std::endl;


void ToLower(char* str);
bool IsUpper(char ch);
void ToUpper(char* str);
bool IsLow(char ch);

int main()
{
	char letters[] = "aN4$%fSsAsrgf";
	cout << letters << endl;
	ToLower(letters);
	cout << letters << endl;
	ToUpper(letters);
	cout << letters << endl;

}
// converts sting to all lower case CHARS
void ToLower(char* str) {
	if (str == nullptr)
	{
		return;
	}

	size_t i = 0;

	while (str[i] != '\0')
	{
		if (IsUpper(str[i]))
		{
			str[i] += 'a' - 'A';
		}
		i++;
	}
}

// converts sting to all UPPER CASE CHARS
void ToUpper(char* str) {
	if (str == nullptr)
	{
		return;
	}

	size_t i = 0;

	while (str[i] != '\0')
	{
		if (IsLow(str[i]))
		{
			str[i] += 'A' - 'a';
		}
		i++;
	}
}

// checks is char is uppercase letter returns true/false
bool IsUpper(char ch) {
	bool result = ('A' <= ch && ch <= 'Z');
	return result;
}

// checks is char is lower case letter returns true/false
bool IsLow(char ch) {
	bool result = ('a' <= ch && ch <= 'z');
	return result;
}