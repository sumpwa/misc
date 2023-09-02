#include <iostream>
#include <string>

std::string leftPad(const std::string &input, int width) {
    if (width <= input.length()) {
        return input; // No padding needed
    }
    
    int paddingLength = width - input.length();
    std::string padding(paddingLength, ' '); // Create a string of spaces
    
    return padding + input; // Concatenate padding and input string
}

int main() {
    std::string input = "Hello, World!";
    int desiredWidth = 20;
    
    std::string paddedString = leftPad(input, desiredWidth);
    std::cout << paddedString << std::endl;
    
    return 0;
}
