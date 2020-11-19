// Напишете програма, която прочита цяло число n[1;7] и отпечатва деня от седмицата, на който съответства.

#include <iostream>

int main()
{
    unsigned short day;
    std::cin >> day;

    switch (day) {
    case 1:
        std::cout << "Monday" << std::endl;
        break;
    case 2:
        std::cout << "Tuesday" << std::endl;
        break;
    case 3:
        std::cout << "Wednesday" << std::endl;
        break;
    case 4:
        std::cout << "Thursday" << std::endl;
        break;
    case 5:
        std::cout << "Friday" << std::endl;
        break;
    case 6:
        std::cout << "Saturday" << std::endl;
        break;
    case 7:
        std::cout << "Sunday" << std::endl;
        break;
    default:
        std::cout << "number is not between 1 and 7!" << std::endl;
        break;
    }
}