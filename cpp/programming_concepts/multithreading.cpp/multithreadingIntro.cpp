#include <iostream>
#include <thread>
#include <chrono>

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if ((i&1) == 0)
        {
            EvenSum+=i;
        }
    }
}

void findOdd(ull start, ull end)
{
    for (ull i = start; i<= end; i++)
    {
        if (i&1)
        {
            OddSum+=i;
        }
    }
}

int main()
{
    ull start = 0, end = 1900000000;
    auto startTime = std::chrono::high_resolution_clock::now();
    std::thread t1(findOdd, start, end);
    std::thread t2(findEven, start, end);
    t1.join();
    t2.join();
    // findOdd(start, end);
    // findEven(start, end);

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime-startTime);

    std::cout << "Odd Sum: " << OddSum << std::endl;
    std::cout << "Even Sum: " << EvenSum << std::endl;

    std::cout << "Duration is : " << duration.count()/1000000;
    return 0;
}   