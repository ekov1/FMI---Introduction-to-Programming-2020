// Реализирайте функции insertAt(index, element) / removeAt(index), които
// добавят / премахват елемент на дадена позиция в динамичен масив.
// 
// Пример:
// 
// Вход: 8 12 92 32 4
// insert_at 4 123 ->  8 12 92 32 123 4
// remove_at 1 ->      8 92 32 123 4

#include <iostream>

using std::cout;
using std::endl;

void PrintArray(int array[], unsigned size);
void ArrayInsertAt(int*& array, unsigned& size, unsigned position, int element);
void ArrayRemoveAt(int*& array, unsigned& size, unsigned position);

int main()
{
	unsigned size = 4;
	int* arr = new int[] {1, 2, 3, 4};
	PrintArray(arr, size);
	ArrayInsertAt(arr, size, 2, 42);
	PrintArray(arr, size);
	ArrayRemoveAt(arr, size, 2);
	PrintArray(arr, size);

	delete[]arr;
	return 0;
}

// inserts element in array at given position
void ArrayInsertAt(int*& array, unsigned& size, unsigned position, int element) {
	int* tempArr = new int[size + 1];

	for (unsigned i = 0; i < position; i++)
	{
		tempArr[i] = array[i];
	}

	tempArr[position] = element;

	for (unsigned i = position; i < size; i++)
	{
		tempArr[i + 1] = array[i];
	}

	delete[] array;
	array = tempArr;
	size++;
}

// removes element from array at given position
void ArrayRemoveAt(int*& array, unsigned& size, unsigned position) {
	int* tempArr = new int[size - 1];

	for (unsigned i = 0; i < position; i++)
	{
		tempArr[i] = array[i];
	}

	for (unsigned i = position + 1; i < size; i++)
	{
		tempArr[i - 1] = array[i];
	}

	delete[] array;
	array = tempArr;
	size--;
}

void PrintArray(int array[], unsigned size) {
	for (unsigned i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}