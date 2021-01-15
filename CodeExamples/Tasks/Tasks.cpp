#include <iostream>

using std::nothrow;
using std::cout;


double* CreateN(unsigned n);
double* Create10();

int main()
{
    int i = 1;
    int j = 1;
    cout << ++i << " " << j++;
}


// 1. Напишете функция Create10, която създава масив с 10 рационални числа.
double* Create10() {
    return CreateN(10);
}

// 2. Напишете функция CreateN, която създава масив с N рационални числа.
double* CreateN(unsigned n) {
    double* array = new (nothrow)double[n];
    if (!array)
    {
        return nullptr;
    }

    return  array;
}
// 3. Напишете функция DemoCreate, която ползва Create10 и CreateN по подходящ начин
void DemoCreate() {
    double* arrayOfTen = Create10();
    double* arrayOfN = CreateN(5);

    delete[]arrayOfTen;
    delete[]arrayOfN;
}

//4. Напишете функция Initialize15, която приема масив с 15 елемента и го инициализар с 0.
bool Initialize15(double* array, unsigned arraySize) {
    if (arraySize != 15 || array == nullptr)
    {
        return false;
    }

    for (unsigned i = 0; i < arraySize; i++)
    {
        array[i] = 0;
    }

    return true;
}

//5. Напишете функция Initialize11_42, която приема масив с 11 елемента и го инициализар с 42.42 .
bool Initialize11_42(double* array, unsigned arraySize) {

    if (arraySize != 11 || array == nullptr)
    {
        return false;
    }

    for (unsigned i = 0; i < arraySize; i++)
    {
        array[i] = 42.42;
    }

    return true;
}

//6  Напишете функция InitializeN, която приема масив с N елемента и го инициализира с 0.
bool InitializeN(double* array, unsigned arraySize) {
    if (array == nullptr)
    {
        return false;
    }

    for (unsigned i = 0; i < arraySize; i++)
    {
        array[i] = 0;
    }

    return true;
}

//7. Напишете функция InitializeN_X, която приема масив с N елемента и го инициализира с стойност подадена като аргумент.
void InitializeN_X(double* array, unsigned arraySize, double x) {
    for (unsigned i = 0; i < arraySize; i++)
    {
        array[i] = x;
    }
}
//8. Напишете функция InitializeN_F, която приема масив с N елемента и го инициализира с помоща на подадена функция от вид `float f(int index)`,
//която приема индекс и връща стойност с която трябва да бъде инициализарн елемент на този индекс.
//9. Напишете функция DemoInitialize, която ползва всички InitializeXXX фунцкии по подходящ начин.