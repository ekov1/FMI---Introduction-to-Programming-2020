// Нека имаме масив от цени, за който i - тия елемент е цената на дадена акция(stock)
// в ден i.Напишете функция, която намира максималната печалба, която можем да направим
// купувайки и продавайки тези акции.Можете да изпълните, колкото транзакции пожелаете(т.е да купите и
//     и продадете една акция няколко пъти), но задължително
//     трябва да продадете акцията преди отново да закупите.
// 
//     Пример 1:
// 
// Вход: [7, 1, 5, 3, 6, 4]
// Изход : 7
// Обяснение : Купуваме в ден 2(price = 1) и продаваме в ден 3(price = 5), profit = 5 - 1 = 4
// След това купуваме в ден 4(price = 3) и продаваме в ден 5(price = 6), profit = 6 - 3 = 3
// Пример 2 :
// 
//     Вход : [1, 2, 3, 4, 5]
//     Изход : 4
//     Обяснение : Купуваме в ден 1(price = 1) и продаваме в ден 5(price = 5), profit = 5 - 1 = 4
#include <iostream>

int const MAX_SIZE = 1024;

void ReadArr(double arr[], int arrSize);

int main()
{
	double arr[MAX_SIZE];
	int arrSize;
	std::cin >> arrSize;
	ReadArr(arr, arrSize);
}

void GetProfit(double arr[], int arrSize) {
	double profit = 0;
	double firstElementSeq = arr[0];
	int firstElemntIndex = 0;
	double lastElementSeq;
	int lastElemntIndex = 0;
	int seqSize = 0;
	double currentElement = arr[0];

	for (size_t i = 1; i < arrSize; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			lastElementSeq = arr[i];
			lastElemntIndex = i;

			if (seqSize > 1)
			{
				double seqProfit = lastElementSeq - firstElementSeq;
				double investmentValue = profit - firstElementSeq;
				if (abs(investmentValue)  > seqProfit)
				{

				}
			}
		}
		else {
			seqSize++;
		}
	}
}

void ReadArr(double arr[], int arrSize) {
	for (size_t i = 0; i < arrSize; i++)
	{
		std::cin >> arr[i];
	}
}