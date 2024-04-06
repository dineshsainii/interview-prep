#include <iostream>
#include <functional>

void BindTestFunc(int x, int y, int z)
{
    std::cout << x << " " << y << " " << z << std::endl;
}

int main()
{

    auto fun1 = std::bind(BindTestFunc, std::placeholders::_1, std::placeholders::_3, 2);
    fun1(10, 20, 30);
    return 0;
}