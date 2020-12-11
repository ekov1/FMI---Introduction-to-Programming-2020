
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

const int BAR_LENGTH_MIN = 1;
const int BAR_LENGTH_MAX = 100;

const std::string ERROR_MSG_WRONG_INPUT = "Wrong Input.";
const std::string ERROR_MSG_BAR_LENGTH = " Bar length must be between 1 and. 100.";

float currentProgress;
unsigned barlenght;
char endSymbolLeft, endSymbolRight;
bool showPercentSybolInBar = 0;
char filledSpaceSymbol, emptySpaceSymbol;
int wholePartsOfProgressBar;

bool InitializeBar();
void RunBar();
bool ValidateValueInInterval(int value, int start, int end, std::string message);

int main()
{
	bool initialized = 0;
	initialized = InitializeBar();

	if (initialized)
		RunBar();
	else
	{
		std::cout << "Initialization failed. Tyr again 1 exit 0;"

	}
}

void RunBar() {
	std::cout << endSymbolLeft;
	for (size_t i = 0; i < barlenght; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << filledSpaceSymbol;
	}
	std::cout << endSymbolRight;
}

bool InitializeBar() {
	bool result = 1;

	std::cout << "Enter current progrress value: ";
	std::cin >> currentProgress;


	if (result)
	{
		std::cout << "Enter progrress length: ";
		std::cin >> barlenght;
		result = ValidateValueInInterval(barlenght, BAR_LENGTH_MIN, BAR_LENGTH_MAX, );
	}


	std::cout << "Enter end Symbol Left: ";
	std::cin >> endSymbolLeft;

	std::cout << "Enter end Symbol Right: ";
	std::cin >> endSymbolRight;

	std::cout << "Do you want to show percent symbol in bar? (1/0 = y/n)";
	std::cin >> endSymbolRight;

	std::cout << "Enter filled Space char:";
	std::cin >> filledSpaceSymbol;

	std::cout << "Enter empty Space char:";
	std::cin >> emptySpaceSymbol;

	std::cout << "Enter whole Parts value Of Progress Bar:";
	std::cin >> wholePartsOfProgressBar;
}


bool ValidateValueInInterval(int value, int start, int end, std::string message) {
	bool result = 1;
	if (value < start || end < value)
	{
		std::cout << message;
		result = 0;
	}
	return result;
}


