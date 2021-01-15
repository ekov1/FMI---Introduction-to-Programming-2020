//Напишете рекурсивно функция, която по подаден масив от цели числа
//да върне указател към нов масив(с точно заделена памет), чиито елементи са
//само числата, съставени само от нечетни цифри.
//
//Пример:
//
//Вход:   11 23 57 42 71 53
//Изход : 11 57 71 53

#include <iostream>

using std::cin;
using std::cout;

unsigned n;
unsigned* input;

void PrintArray(unsigned n);
void ReadInput(unsigned n);

int main()
{
	cin >> n;
	input = new unsigned[n];
	ReadInput(n);
	PrintArray(n);
	delete[] input;
}

unsigned* FilterOdd(unsigned* input, unsigned n) {

}

void ReadInput(unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		cin >> input[i];
	}
}

void PrintArray(unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << input[i] << " ";
	}
}


