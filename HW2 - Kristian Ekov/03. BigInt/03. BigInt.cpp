// 03. BigInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned const NUM_MAX_LENGTH = 8192;

char num1[NUM_MAX_LENGTH];
char num2[NUM_MAX_LENGTH];

char num1Reversed[NUM_MAX_LENGTH];
char num2Reversed[NUM_MAX_LENGTH];


unsigned num1Length, num2Length;
bool isNum1Bigger;
unsigned digitNum1, digitNum2;

// main functions
void Compare();
void Add(char big[], char small[], unsigned bigLength, unsigned smallLength);
void Subtract(char big[], char small[], unsigned bigLength, unsigned smallLenght);
void Multiply(char big[], char small[], unsigned bigLength, unsigned smallLength);

// interface
void ReadInput();

// utilities
bool ValidateInput();
bool IsNum(char num[], unsigned numLength);
unsigned NumLength(char num[]);
char DigitToChar(unsigned digitCharValue);
unsigned CharToDigit(char digitCharValue);
void InitializeLengths();
void ReverseNumber(char num[], unsigned numLength, char numReversed[]);
void ReverseNumbers();
void GetValueFromNextPossibleDigit(char arr[], unsigned length, unsigned currentIndex);

int main()
{
	ReadInput();
	InitializeLengths();
	bool validInput = ValidateInput();

	if (!validInput)
	{
		cout << "Invalid input";
	}
	else {

		cout << endl;
		Compare();
		ReverseNumbers();
		if (isNum1Bigger)
		{
			Add(num1Reversed, num2Reversed, num1Length, num2Length);
			Subtract(num1Reversed, num2Reversed, num1Length, num2Length);
		}
		else {
			Add(num2Reversed, num1Reversed, num2Length, num1Length);
			Subtract(num2Reversed, num1Reversed, num2Length, num1Length);
		}
		ReverseNumbers();
		Multiply(num1Reversed, num2Reversed, num1Length, num2Length);
	}
}

//checks if the input numbers are equal;or which one is bigger;
void Compare() {
	bool areEqual = 1;
	bool areSameLength = 1;

	if (num1Length != num2Length)
	{
		areSameLength = 0;
		areEqual = 0;
		if (num1Length > num2Length)
			isNum1Bigger = 1;
		else
			isNum1Bigger = 0;
	}

	if (areSameLength)
	{
		for (size_t i = 0; i < num1Length; i++)
		{
			if (num1[i] != num2[i])
			{
				areEqual = 0;
				for (size_t j = i; j < num1Length; j++)
				{
					digitNum1 = CharToDigit(num1[i]);
					digitNum2 = CharToDigit(num2[i]);

					if (digitNum1 > digitNum2)
					{
						isNum1Bigger = 1;
						break;
					}
					else if (digitNum1 < digitNum2) {
						isNum1Bigger = 0;
						break;
					}
				}
				break;
			}
		}
	}

	// print are equal
	cout << num1;
	cout << " ";
	cout << (areEqual ? "=" : "!=");
	cout << " ";
	cout << num2 << endl;

	if (!areEqual)
	{
		cout << num1;
		cout << " ";
		cout << (isNum1Bigger ? ">" : "<");
		cout << " ";
		cout << num2 << endl;;
	}
}

// subtracts small number from big one
void Subtract(char big[], char small[], unsigned bigLength, unsigned smallLenght) {
	char operationResult[NUM_MAX_LENGTH] = { 0 };
	unsigned digitsDifference = 0;
	unsigned resultLength = 0;

	for (size_t i = 0; i < bigLength; i++)
	{
		if (i < smallLenght)
		{
			digitNum1 = CharToDigit(big[i]);
			digitNum2 = CharToDigit(small[i]);

			if (digitNum1 < digitNum2)
			{
				GetValueFromNextPossibleDigit(big, bigLength, i);
				digitsDifference = (10 + digitNum1) - digitNum2;
			}
			else {
				digitsDifference = digitNum1 - digitNum2;
			}
			operationResult[i] = DigitToChar(digitsDifference);
			resultLength++;
		}
		else {
			if (i == (bigLength - 1) && big[i] == '0')
			{
				break;
			}
			else {
				operationResult[i] = big[i];
				resultLength++;
			}
		}
	}

	if (isNum1Bigger)
	{
		cout << num1 << " - " << num2 << " = ";
	}
	else {
		cout << num2 << " - " << num1 << " = ";
	}

	bool flag = 0;
	for (int i = bigLength-1; i >= 0; i--)
	{
		if (operationResult[i] != '0')
		{
			flag = 1;
		}
		if (flag)
		{
			cout << operationResult[i];

		}
	}
	if (!flag)
	{
		cout << " 0";
	}

	cout << endl;
}

// add two long nums
void Add(char big[], char small[], unsigned bigLength, unsigned smallLength) {
	char operationResult[NUM_MAX_LENGTH] = { 0 };
	unsigned remainder = 0;
	bool canAdd = 1;
	unsigned resultLength = 0;
	unsigned digitsSum = 0;

	// check for type overflow
	if (num1Length == NUM_MAX_LENGTH && num1Length == NUM_MAX_LENGTH)
	{
		digitNum1 = CharToDigit(num1[0]);
		digitNum2 = CharToDigit(num2[0]);

		if ((digitNum1 + digitNum2) > 9)
		{
			canAdd = 0;
		}
	}

	if (canAdd)
	{
		int digitsSum = 0;
		for (size_t i = 0; i < bigLength; i++)
		{
			digitNum1 = CharToDigit(big[i]);
			digitsSum = digitNum1;
			if (i < smallLength)
			{
				digitNum2 = CharToDigit(small[i]);
				digitsSum += digitNum2;
			}
			if (remainder)
			{
				digitsSum += remainder;
			}

			if (digitsSum > 9)
			{
				digitsSum -= 10;
				remainder = 1;
			}
			else {
				remainder = 0;
			}

			operationResult[i] = DigitToChar(digitsSum);
		}
		resultLength = bigLength - 1;
		if (remainder)
		{
			if (bigLength + 1 > NUM_MAX_LENGTH)
			{
				canAdd = 0;
			}
			else {
				operationResult[bigLength] = DigitToChar(remainder);
				resultLength++;
			}
		}
	}

	cout << num1 << " + " << num2 << " = ";
	for (int i = resultLength; i >= 0; i--)
	{
		cout << operationResult[i];
	}
	cout << endl;
}

void Multiply(char first[], char second[], unsigned firstLength, unsigned secondLength) {
	char operationResult[NUM_MAX_LENGTH] = { 0 };
	unsigned resultPosition;
	unsigned remainderP = 0;
	unsigned remainderA = 0;
	unsigned digitsProduct = 0;
	unsigned resultSum = 0;


	for (size_t i = 0; i < firstLength; i++)
	{
		resultPosition = i;
		digitNum1 = CharToDigit(first[i]);
		for (size_t j = 0; j < secondLength; j++)
		{
			digitNum2 = CharToDigit(second[j]);

			digitsProduct = (digitNum1 * digitNum2) + remainderP;
			if (digitsProduct > 9)
			{
				digitsProduct %= 10;
				remainderP = digitsProduct/10;
			}
			else {
				remainderP = 0;
			}

			resultSum = digitsProduct + remainderA;
			if (operationResult[resultPosition])
			{
				resultSum += CharToDigit(operationResult[resultPosition]);
			}
			if (resultSum > 9)
			{
				resultSum -= 10;
				remainderA = 1;
			}
			else {
				remainderA = 0;
			}
			operationResult[resultPosition] = DigitToChar(resultSum);
			resultPosition++;
		}
	}
	if (remainderP)
	{
		operationResult[resultPosition] = DigitToChar(remainderP);
	}

	cout << num1 << " * " << num2 << " = ";
	for (int i = resultPosition - 1; i >= 0; i--)
	{
		cout << operationResult[i];
	}
	cout << endl;
}

// initializes reversed numbers
void ReverseNumbers() {
	ReverseNumber(num1, num1Length, num1Reversed);
	ReverseNumber(num2, num2Length, num2Reversed);
}

void ReverseNumber(char num[], unsigned numLength, char numReversed[]) {
	unsigned counter = 0;
	unsigned numPosition = numLength - 1;

	while (counter < numLength) {
		numReversed[counter] = num[numPosition];
		counter++;
		numPosition--;
	}
	//cout << numReversed<<" ";
}

// reads input
void ReadInput() {

	cout << "Enter num1: " << endl;
	cin >> num1;

	cout << "Enter num2: " << endl;
	cin >> num2;

}

// validates if both inputs are integer numbers
bool ValidateInput() {
	bool result;

	result = IsNum(num1, num1Length);
	if (result)
		result = IsNum(num2, num2Length);

	return result;
}
// sets length of entered numbers
void InitializeLengths() {
	num1Length = NumLength(num1);
	num2Length = NumLength(num2);
}

// validates if a char[] contains a log num
bool IsNum(char num[], unsigned numLength) {
	bool result = 1;

	for (size_t i = 0; i < numLength; i++)
	{
		switch (num[i]) {
		case'0':break;
		case'1':break;
		case'2':break;
		case'3':break;
		case'4':break;
		case'5':break;
		case'6':break;
		case'7':break;
		case'8':break;
		case'9':break;
		default: {
			result = 0;
		}
		}
		if (!result)
		{
			break;
		}
	}

	// validate case: 14561664 666s654f
	for (size_t i = numLength; i < NUM_MAX_LENGTH; i++)
	{
		if (num[i] != '\0')
		{
			result = 0;
			break;
		}
	}

	return result;
}

// returns unsigned length of long num
unsigned NumLength(char num[]) {
	unsigned length = 0;
	for (size_t i = 0; i < NUM_MAX_LENGTH; i++)
	{
		if (num[i] != '\0')
		{
			length++;
		}
		else
		{
			break;
		}
	}
	return length;
}

// gets value from next digit when subtracting numbers
void GetValueFromNextPossibleDigit(char arr[], unsigned length, unsigned currentIndex) {
	for (size_t i = currentIndex + 1; i < length; i++)
	{
		if (arr[i] == '0')
		{
			arr[i] = '9';
		}
		else {
			unsigned digit = CharToDigit(arr[i]);
			digit--;
			arr[i] = DigitToChar(digit);
			break;
		}
	}
}

unsigned CharToDigit(char digitCharValue) {
	unsigned result;
	switch (digitCharValue) {
	case'0': {
		result = 0;
		break;
	}
	case'1': {
		result = 1;
		break;
	}
	case'2': {
		result = 2;
		break;
	}
	case'3': {
		result = 3;
		break;
	}
	case'4': {
		result = 4;
		break;
	}
	case'5': {
		result = 5;
		break;
	}
	case'6': {
		result = 6;
		break;
	}
	case'7': {
		result = 7;
		break;
	}
	case'8': {
		result = 8;
		break;
	}
	case'9': {
		result = 9;
		break;
	}
	}
	return result;
}

char DigitToChar(unsigned digitCharValue) {
	char result;
	switch (digitCharValue) {
	case 0: {
		result = '0';
		break;
	}
	case 1: {
		result = '1';
		break;
	}
	case 2: {
		result = '2';
		break;
	}
	case 3: {
		result = '3';
		break;
	}
	case 4: {
		result = '4';
		break;
	}
	case 5: {
		result = '5';
		break;
	}
	case 6: {
		result = '6';
		break;
	}
	case 7: {
		result = '7';
		break;
	}
	case 8: {
		result = '8';
		break;
	}
	case 9: {
		result = '9';
		break;
	}
	}
	return result;
}