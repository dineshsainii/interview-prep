#include <iostream>
#include <cmath>
#include <string>

int Count_Digits(long long number)
{
    if (number/10 == 0)
        return 1;
    return 1 + Count_Digits(number/10);
}

long long Log_Count_Digits(long long number)
{
    return floor(log10(number) + 1);
}

int String_Count_Digits(int n)
{
    std::string num = std::to_string(n);
    return num.size();
}

int main()
{
    long long number;
    std::cin >> number;
    // std::cout << Count_Digits(number);
    // std::cout << Log_Count_Digits(number);
    std::cout << String_Count_Digits(number);
    return 0;
}