#include <iostream>

template<int N>
void Print(std::string val)
{
    for (int i = 0; i<N; i++)
    {
        std::cout << val << std::endl;
    }
}

template<typename U>
void PrintAgain(U val)
{
    std::cout << val << std::endl;
}

int main()
{
    Print<10> ("Hello");
    PrintAgain<int>(190);
    PrintAgain<std::string> ("Radhey Radhey");
    return 0;
}