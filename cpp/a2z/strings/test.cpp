#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main()
{
    std::string ip;
    std::getline(std::cin, ip);
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(ip);

    while (std::getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }


    std::vector<std::string> sets_of_twos;
    
    for (size_t i = 0; i<tokens.size(); i +=2)
    {
        std::string ans;
        if (i+1 < tokens.size())
            ans = tokens[i] + " " + tokens[i+1];
        else ans = tokens[i];
        sets_of_twos.push_back(ans);
    }

    for (const auto &t : sets_of_twos)
    {
        std::cout << t << std::endl;
    }

    return 0;

}