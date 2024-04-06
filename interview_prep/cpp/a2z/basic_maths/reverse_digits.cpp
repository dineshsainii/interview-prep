#include <iostream>

void Reverse(int n)
{
    int rev = 0;
    while (n)
    {
        rev = rev*10 + n%10;
        n=n/10;
    }
    std::cout << rev << "\n";
}

int main()
{
    int number;
    std::cin >> number;

    Reverse(number);
    return 0;
}