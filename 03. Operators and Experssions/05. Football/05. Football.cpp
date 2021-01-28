//Задача 5: Футбол
//Ботев(Пловдив) са участвали втв футболно първенство.Напишете програма, 
//която по подадени победи, равенства и загуби отпечатва точките,
//които отбора е спечелил.За подбеда се дават 3 точки, за равенство - 1, а за загуба - 0.
//
//Примери
//
//Вход : 5 0 2 Изход : 15
//
//Вход : 0 0 1 Изход : 0
#include <iostream>
using namespace std;
int main()
{
	int wins, remi, loss;
	cin >> wins >> remi >> loss;
	wins *= 3;

	cout << (wins + remi);
	cout << "Size of float : " << sizeof(float) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
