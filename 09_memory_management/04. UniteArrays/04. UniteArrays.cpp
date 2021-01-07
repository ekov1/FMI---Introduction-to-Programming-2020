//Реализирайте функция, която обединява два сортирани динамични масива,
//като резултатния масив остава сортиран.
//
//Пример:
//
//Вход:   1 3 5 10 21
//2 7 12 32
//Изход : 1 2 3 5 7 10 12 21 32

#include <iostream>

using std::cout;
using std::endl;

void PrintArray(unsigned array[], unsigned size);
void UniteSortedArrays(unsigned* arr1, unsigned* arr2, unsigned*& arrUnited, unsigned sizeArr1, unsigned sizeArr2, unsigned& sizeUnited);

int main()
{
	unsigned sizeArr1 = 5;
	unsigned* arr1 = new unsigned [] {1, 3, 5, 10, 21};
	unsigned sizeArr2 = 4;
	unsigned* arr2 = new unsigned [] {2, 7, 12, 32};
	unsigned sizeUnited = 0;
	unsigned* arrUnited = new unsigned[sizeUnited];
	PrintArray(arr1, sizeArr1);
	PrintArray(arr2, sizeArr2);
	UniteSortedArrays(arr1, arr2, arrUnited, sizeArr1, sizeArr2, sizeUnited);
	PrintArray(arrUnited, sizeUnited);

	delete[] arr1;
	delete[] arr2;
	delete[] arrUnited;

}

void UniteSortedArrays(unsigned* arr1, unsigned* arr2, unsigned*& arrUnited, unsigned sizeArr1, unsigned sizeArr2, unsigned& sizeUnited) {

	sizeUnited = sizeArr1 + sizeArr2;

	unsigned* tempArr = new unsigned[sizeUnited];

	unsigned tempIndex = 0;
	unsigned i = 0, j = 0;

	for (; i < sizeArr1 && j < sizeArr2;)
	{
		if (arr1[i] <= arr2[j])
		{
			tempArr[tempIndex++] = arr1[i++];
		}
		else {
			tempArr[tempIndex++] = arr2[j++];
		}
	}

	while (i < sizeArr1)
	{
		tempArr[tempIndex++] = arr1[i++];
	}
	while (j < sizeArr2)
	{
		tempArr[tempIndex++] = arr2[j++];
	}

	delete[] arrUnited;
	arrUnited = tempArr;
}

void PrintArray(unsigned array[], unsigned size) {
	for (unsigned i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
