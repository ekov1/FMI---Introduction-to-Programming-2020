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


// 1. �������� ������� Create10, ����� ������� ����� � 10 ���������� �����.
double* Create10() {
    return CreateN(10);
}

// 2. �������� ������� CreateN, ����� ������� ����� � N ���������� �����.
double* CreateN(unsigned n) {
    double* array = new (nothrow)double[n];
    if (!array)
    {
        return nullptr;
    }

    return  array;
}
// 3. �������� ������� DemoCreate, ����� ������ Create10 � CreateN �� �������� �����
void DemoCreate() {
    double* arrayOfTen = Create10();
    double* arrayOfN = CreateN(5);

    delete[]arrayOfTen;
    delete[]arrayOfN;
}

//4. �������� ������� Initialize15, ����� ������ ����� � 15 �������� � �� ����������� � 0.
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

//5. �������� ������� Initialize11_42, ����� ������ ����� � 11 �������� � �� ����������� � 42.42 .
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

//6  �������� ������� InitializeN, ����� ������ ����� � N �������� � �� ������������ � 0.
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

//7. �������� ������� InitializeN_X, ����� ������ ����� � N �������� � �� ������������ � �������� �������� ���� ��������.
void InitializeN_X(double* array, unsigned arraySize, double x) {
    for (unsigned i = 0; i < arraySize; i++)
    {
        array[i] = x;
    }
}
//8. �������� ������� InitializeN_F, ����� ������ ����� � N �������� � �� ������������ � ������ �� �������� ������� �� ��� `float f(int index)`,
//����� ������ ������ � ����� �������� � ����� ������ �� ���� ������������ ������� �� ���� ������.
//9. �������� ������� DemoInitialize, ����� ������ ������ InitializeXXX ������� �� �������� �����.