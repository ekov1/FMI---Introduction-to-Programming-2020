//Реализирайте функциите pushBack / popBack, които добавят / премахват елемент
//на последна позиция в динамичен масив.
//
//Пример:
//
//Вход: 9 11 42 12
//push_back 5 ->  9 11 42 12 5
//pop_back ->     9 11 42 12

#include <iostream>

using namespace std;

bool Resize(int*& arr, int oldSize, int newSize);
void PrintArray(int* array, int size);
void PushBack(int*& array, int& size, int element);
void PopBack(int*& arr, int& size);

int main() {
	int size = 1;
	int* arr = new int[size];
	arr[0] = 2;
	PrintArray(arr, size);
	PushBack(arr, size, 3);
	PrintArray(arr, size);
	PopBack(arr, size);
	PrintArray(arr, size);

	delete[] arr;
}


void PopBack(int*& arr, int& size) {
	if (Resize(arr, size, size - 1))
	{
		--size;
	}
}

void PushBack(int*& array, int& size, int element) {
	if (Resize(array, size, size + 1))
	{
		array[size] = element;
		++size;
	}
}

bool Resize(int*& arr, int oldSize, int newSize) {
	int* tempArray = new(nothrow) int[newSize];
	if (!tempArray)
	{
		return false;
	}

	int size = oldSize < newSize ? oldSize : newSize;

	for (int i = 0; i < size; i++)
	{
		tempArray[i] = arr[i];
	}

	delete[] arr;
	arr = tempArray;

	return true;
}

void PrintArray(int* array, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
