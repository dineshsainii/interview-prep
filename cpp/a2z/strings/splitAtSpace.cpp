#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    // std::string input = "Hello world this is a test";
    std::string input;
    std::getline(std::cin , input);
    std::cout << input << std::endl;
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(input);

    while (std::getline(ss, token, ' ')) { // Using space (' ') as delimiter
        if (!token.empty()) { // Check if token is not empty
            tokens.push_back(token);
        }
    }

    // Output the tokens
    for (const auto& t : tokens) {
        std::cout << t << std::endl;
    }

    return 0;
}
