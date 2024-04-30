#include <iostream>
#include <string>
std::string DecToBin(int num)
{
    std::string binary = "";
    while (num)
    {
        binary = std::to_string(num % 2) + binary;
        num /= 2;
    }
    return binary;
}

int main()
{
    int num;
    std::cin >> num;
    std::cout << DecToBin(num);

    return 0;
}