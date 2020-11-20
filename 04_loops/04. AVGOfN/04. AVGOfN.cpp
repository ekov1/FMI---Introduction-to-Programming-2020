// По въведено цяло положително число n програмата 
// да прочита n на брой цели числа, а след това да отпечатва тяхното средно аритметично.

#include <iostream>

int main()
{
	int n, counter;
	float sum = 0, num;
	std::cin >> n;
	counter = n;
	while (counter > 0)
	{
		std::cin >> num;
		sum += num;
		counter--;
	}

	float avg = sum / n;
	std::cout << avg << "\n";
}

