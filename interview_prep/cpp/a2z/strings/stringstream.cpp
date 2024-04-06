#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::stringstream ss;
    ss << "Hello" << 23 << "World";
    std::string message;
    ss >> message;
    std::cout << message << std::endl;

    return 0;
}