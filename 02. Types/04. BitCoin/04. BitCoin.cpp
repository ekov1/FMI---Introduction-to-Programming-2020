// упили сте си Ѕиткойн и има пром€на в цената му.Ќапишете програма ко€то 
//по подадени положително число с плаваща запета€ - колко биткойн имате и 
//число с плаваща запета€ в граници[-100, 100] - пром€ната на биткойн в 
//проценти изчисл€ва и отпечатва новата сума биткойн ко€то притежавате 
//след пром€ната в цената и разликата между старата и новата сума.
//
//ѕример:
//
//Input bitcoin : 1000
//Input change % : -10
//You now have 900 bitcoins!
//The change in your balance is - 100.
#include <iostream>
using namespace std;

int main()
{
	double bitcoin;
	//Input bitcoin 
	cin >> bitcoin;
	if (bitcoin < 0)
	{
		cerr << "bitcoin must be > 0";
	}

	double change;
	cin >> change;

	// ( part * 100 ) / whole = percent
	// part * 100 = whole * percent
	// part =  ( whole * percent ) / 100
	double part = (bitcoin * change) / 100;
	double result = bitcoin + part;
	cout << result;
}