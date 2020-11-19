// Имплементирайте програма, която получава едно двубайтово число 
// на стандартния си вход и го отпечатва с разменени байтове.
// Вход:  19006 // 0b01001010'00111110
// Изход: 15946 // 0b00111110'01001010

#include <iostream>

int main()
{
    short num;
    std::cin >> num;

    short firstByte = num & 255;
    short secondByte = num >> 8;

    short swappedBytes = ((firstByte << 8) | secondByte);
    std::cout << "New num: " << swappedBytes << std::endl;
}
