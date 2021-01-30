//Реализирайте функции insert_at(index, element) / remove_at(index), които
//добавят / премахват елемент на дадена позиция в динамичен масив.
//
//Пример:
//
//Вход: 8 12 92 32 4
//insert_at 4 123 ->  8 12 92 32 123 4
//remove_at 1 ->      8 92 32 123 4

#include <iostream>
using namespace std;

void PrintArray(int* array, int size);
bool InsertAt(int*& array, int& size, int index, int element);
bool RemoveAt(int*& array, int& size, int index);

int main()
{
	int size = 5;
	int* arr = new int[size] { 1, 2, 3, 4, 5 };
	PrintArray(arr, size);
	InsertAt(arr, size, 2, 7);
	PrintArray(arr, size);
	RemoveAt(arr, size, 0);
	PrintArray(arr, size);
}

bool RemoveAt(int*& array, int& size, int index) {
	int* tempArray = new (nothrow)int[size - 1];
	int writeIndex = 0;

	for (int i = 0; i < index; ++i, ++writeIndex)
	{
		tempArray[writeIndex] = array[i];
	}
	for (int i = index+1; i < size; ++i,++writeIndex)
	{
		tempArray[writeIndex] = array[i];
	}

	delete[]array;
	array = tempArray;
	--size;

	return true;
}

bool InsertAt(int*& array, int& size, int index, int element) {
	int* tempArray = new(nothrow) int[size + 1];
	if (!tempArray)
	{
		return false;
	}

	int writeIndex = 0;
	for (int i = 0; i < index; ++i, ++writeIndex)
	{
		tempArray[writeIndex] = array[i];
	}
	tempArray[index] = element;
	++writeIndex;
	for (int i = index; i < size; ++i, ++writeIndex)
	{
		tempArray[writeIndex] = array[i];
	}

	delete[]array;
	array = tempArray;

	++size;
	return true;

}


void PrintArray(int* array, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}



