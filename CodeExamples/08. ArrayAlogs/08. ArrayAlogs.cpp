// Tabale of Contents:
// minElement
// index of min element
// index of min element in range

#include <iostream>

using std::cerr;
using std::endl;
using std::cout;

int MinElement(int array[], unsigned size);
unsigned MinIndexInRange(int array[], unsigned from, unsigned to);
unsigned MinIndex(int array[], unsigned size);

int main() {

	for (size_t i = 0; i < 5; i++)
	{
		cout << i;
	}

	cout << endl;

	for (size_t i = 0; i < 5; ++i)
	{
		cout << i;
	}

	return 0;
}

#pragma region MinElement

// Find the minimum value in the array
int MinElement(int array[], unsigned size) {
	// first approximation;
	int min = array[0];

	for (unsigned i = 0; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	return min;
}

// Find the index of the minimal element in a range 
unsigned MinIndexInRange(int array[], unsigned from, unsigned to) {
	unsigned min = ++from;
	for (unsigned i = from; i < to; i++)
	{
		if (array[i] < array[min])
		{
			min = i;
		}
	}
	return min;
}

// Find the index of the array
unsigned MinIndex(int array[], unsigned size) {
	return MinIndexInRange(array, 0, size);
}

#pragma endregion


// Removes all negative elements in an array
// Return the size of the result array
unsigned FilterNegative(int array[], unsigned size) {
	unsigned read = 0; // read Index
	unsigned write = 0; // write Index

	for (; read < size; ++read)
	{
		if (array[read] >= 0)
		{
			array[write] == array[read];
			write++;
		}
	}

	return write;
}

// Insert an element into array at a given position
// Preserves the order of the elements
// Returns true if the operation is successful
bool InsertAt(int array[], unsigned position, int x, unsigned n) {

	// check if possition is valid
	if (position > n)
	{
		cerr << "Position outside array" << endl;
		return false;
	}

	// shift the elemts twords the end to free space
	for (unsigned i = n; i > position; i--)
	{
		array[i] = array[i - 1];
	}

	// put element at the freed position
	array[position] = x;

	return true;
}

// Inserts elemt at given position
// Doesnt preserve order in the array
// return true if successful
bool InsertAtDirect(int array[], unsigned position, int x, unsigned n) {
	// check if possition is valid
	if (position > n)
	{
		cerr << "Position outside array" << endl;
		return false;
	}

	// put element at the freed position
	array[position] = x;

	return true;
}

// Remove an element at a given position.
// Preserves the order of the elements.
// Returns true if the operation is successful
bool DeleteAt(int array[], unsigned position, unsigned arraySize) {
	// check if possition is valid
	if (position >= arraySize)
	{
		cerr << "Position outside array" << endl;
		return false;
	}

	// shift elements twords the beggining if the array
	for (unsigned i = position; i < arraySize - 1; i++)
	{
		array[i] == array[i + 1];
	}
}