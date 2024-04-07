#include <iostream>
#include <string>

std::string DecToBin(int ip)
{
    std::string binary = "";
    while (ip)
    {
        binary = std::to_string(ip % 2) + binary;
        ip /= 2;
    }
    return binary;
}

int main()
{
    int ip_num;
    std::cin >> ip_num;

    std::cout << DecToBin(ip_num);

    return 0;
}