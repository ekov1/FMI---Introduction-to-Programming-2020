
#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

const unsigned BAR_LENGTH_MIN = 1;
const unsigned BAR_LENGTH_MAX = 100;
const unsigned CURRENT_PROGRESS_MIN = 0;
const unsigned CURRENT_PROGRESS_MAX = 1;

//" Current Progress must be from 0 to 1.";

float currentProgress;
unsigned barLenght;
char endSymbolLeft, endSymbolRight;
bool showPercentSybolInBar = 0;
char filledSpaceSymbol, emptySpaceSymbol;
unsigned wholePartsOfProgressBar;
float onePartOfBarInPercent;
float onePartOfBar;
unsigned partsWriten = 0;
unsigned millisecondsBreak;

bool InitializeBar();
void RunBar();
void UpdateBar(unsigned currentProgress);

unsigned main()
{
	bool initialized = 0;
	initialized = InitializeBar();
	if (initialized) {
		system("cls");
		RunBar();
	}

}

void RunBar() {
	for (size_t i = 0; i <= currentProgress; i++)
	{
		UpdateBar(i);
		sleep_for(milliseconds(millisecondsBreak));
		if (i < currentProgress)
		{
			system("cls");
		}
	}
	cout << endl;
}

void UpdateBar(unsigned currentProgress) {
	unsigned stepsToAdd = currentProgress / onePartOfBarInPercent;
	unsigned counter = 0;

	cout << endSymbolLeft;

	for (unsigned i = 0; i < stepsToAdd; i++)
	{
		for (size_t i = 0; i < onePartOfBar; i++)
		{
			if (showPercentSybolInBar)
			{

				if (currentProgress == 100 && counter == barLenght - 4)
				{
					break;
				}
				if (currentProgress == 99 && counter == barLenght - 3)
				{
					break;
				}
				if (currentProgress == 98 && counter == barLenght - 2)
				{
					break;
				}
			}
			else {
				if (currentProgress == 100 && counter == barLenght - 3)
				{
					break;
				}
				if (currentProgress == 99 && counter == barLenght - 2)
				{
					break;
				}
				if (currentProgress == 98 && counter == barLenght - 1)
				{
					break;
				}
			}

			cout << filledSpaceSymbol;
			counter++;
		}
	}

	if (stepsToAdd > partsWriten)
	{
		partsWriten = stepsToAdd;
	}

	cout << currentProgress;

	if (currentProgress < 10)
	{
		counter += 1;
	}
	else if (10 < currentProgress && currentProgress < 100) {
		counter += 2;
	}
	else if (currentProgress == 100) {
		counter += 3;
	}

	if (showPercentSybolInBar)
	{
		cout << '%';
		counter++;
	}

	while (counter < barLenght)
	{
		cout << emptySpaceSymbol;
		counter++;
	}

	cout << endSymbolRight;
}

bool InitializeBar() {
	bool result = 1;

	cout << "Enter current progrress value: ";
	cin >> currentProgress;
	if (currentProgress < 0 || 1 < currentProgress)
	{
		cout << "error! currentProgress must be in [0,1]";
		result = 0;
	}

	if (result)
	{
		cout << "Enter bar length: ";
		cin >> barLenght;
		if (barLenght < 1)
		{
			cout << "error! bar length must be >= 1";
			result = 0;
		}
	}

	if (result)
	{
		cout << "Enter end Symbol Left: ";
		cin >> endSymbolLeft;
	}
	if (result)
	{
		cout << "Enter end Symbol Right: ";
		cin >> endSymbolRight;
	}
	if (result)
	{
		cout << "Do you want to show percent symbol in bar? (1/0 = y/n): ";
		cin >> showPercentSybolInBar;
	}
	if (result)
	{
		cout << "Enter filled Space char: ";
		cin >> filledSpaceSymbol;
	}

	if (result)
	{
		cout << "Enter empty Space char: ";
		cin >> emptySpaceSymbol;
	}

	if (result) {
		cout << "Enter whole Parts Of Progress Bar: ";
		cin >> wholePartsOfProgressBar;
		if (wholePartsOfProgressBar < 0 || barLenght < wholePartsOfProgressBar)
		{
			cout << "whole Parts Of Progress Bar must be in [1,barlenght] = " << barLenght;
			result = 0;
		}
	}
	int sec;
	if (result)
	{
		cout << "Enter loading time interval in seconds:";
		cin >> sec;
		if (sec < 0)
		{
			cout << "sec must be > 0 ";
			result = 0;
		}
	}

	cout << endl;

	if (result)
	{
		currentProgress *= 100;
		onePartOfBar = barLenght / wholePartsOfProgressBar;
		onePartOfBarInPercent = (onePartOfBar / barLenght) * 100;
		millisecondsBreak = (sec * 1000) / currentProgress;
	}

	return result;
}


