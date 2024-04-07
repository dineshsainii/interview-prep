#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main()
{
    std::string ip;
    std::getline(std::cin, ip);
    std::cout << "Input string: " << ip << std::endl;
    std::stringstream ss(ip);
    std::string token;
    std::vector<std::string> tokens;
    std::vector<std::string> two_tokens;
    while (std::getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    for (size_t i = 0; i<tokens.size(); i+=2)
    {
        std::string ans;
        if (i+1<tokens.size())
        {
            ans = tokens[i] + " " + tokens[i+1];
        }
        else
        {
            ans = tokens[i];
        }

        two_tokens.push_back(ans);
    }

    for (const auto &t: two_tokens)
    {
        std::cout << t << std::endl;
    }
    return 0;

}