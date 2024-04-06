#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int main()
{
    std::string ip;
    std::cin >> ip;
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(ip);

    while(std::getline(ss, token, ','))
    {
        tokens.push_back(token);
    }

    for (auto &x : tokens)
    {
        std::cout << x << std::endl;
    }
    return 0;
}