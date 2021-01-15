#include <iostream>

using std::nothrow;

int main()
{
	std::cout << "Hello World!\n";
}

// Find the length of a string
unsigned StrLen(const char* text) {
	unsigned len = 0;
	while (text[len])
	{
		++len;
	}

	return len;
}

// Make a copy of a string - from src to dest
// Uses indexes
void StrCpy(char* dest, const char* src) {
	unsigned position = 0;
	while (src[position])
	{
		dest[position] = src[position];
		++position;
	}
	dest[position] = '\0';
}

// Make a copy of a string - from src to dest
// Uses pointers
void StrCpyPtr(char* dest, const char* src) {
	while (*dest++ = *src++);
}

// Comapres two strings in lexicographic order
// The result is 0 if the strings are equal,
// negative, if the first is before the second and positive
// if second is before first
int StrCmp(const char* text1, const char* text2) {
	while (*text1 && *text1 == *text2) {
		++text1;
		++text2;
	}
	return *text1 - *text2;
}

// Creates a duplicate of a string, using dynamic memory
char* StrDup(const char* text) {
	char* newText = new(nothrow) char[StrLen(text) + 1];
	if (newText)
	{
		StrCpy(newText, text);
	}
	return newText;
}