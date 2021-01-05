// Реализирайте функциите pushBack / popBack, които добавят / премахват елемент
// на последна позиция в динамичен масив.
// 
// Пример:
// 
// Вход: 9 11 42 12
// push_back 5 ->  9 11 42 12 5
// pop_back ->     9 11 42 12

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::nothrow;
using std::cout;
using std::endl;

bool ArrayPushBack(int*& array, size_t& size, int element);
int ArrayPopBack(int*& array, size_t& size);
bool ArrayResize(int*& array, size_t oldSize, size_t newSize);
void GenerateArray(int* array, unsigned size, int max = RAND_MAX);
void PrintArray(int array[], size_t size);



int main()
{
	size_t size = 5;
	// allocate memory
	int* arr = new int[size];

	GenerateArray(arr, size);
	PrintArray(arr, size);
	ArrayPushBack(arr, size, 42);
	PrintArray(arr, size);
	ArrayPopBack(arr, size);
	PrintArray(arr, size);

}

bool ArrayPushBack(int*& array, size_t& size, int element) {
	bool result = ArrayResize(array, size, size + 1);
	if (result)
	{
		array[size] = element;
		size++;
	}
	return result;
}

int ArrayPopBack(int*& array, size_t& size) {
	int lastElement;
	bool result;

	if (size > 0 && array[size - 1])
	{
		lastElement = array[size - 1];
		result = ArrayResize(array, size, size - 1);
	}

	if (result)
	{
		size--;
		return lastElement;
	}
}

bool ArrayResize(int*& array, size_t oldSize, size_t newSize) {
	int* tempArray = new(nothrow) int[newSize];
	if (tempArray == nullptr)
	{
		return false;
	}

	size_t size = oldSize < newSize ? oldSize : newSize;

	for (size_t i = 0; i < size; i++)
	{
		tempArray[i] = array[i];
	}

	delete[] array;

	array = tempArray;
}

// Generates random content of an array
void GenerateArray(int* array, unsigned size, int max)
{
	static bool initialized = false;
	if (!initialized) {
		initialized = true;
		srand(time(0));
	}

	for (unsigned i = 0; i < size; ++i) {
		array[i] = rand() % max + 0;
	}

}

void PrintArray(int array[], size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}