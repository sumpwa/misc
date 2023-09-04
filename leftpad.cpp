#include <iostream>
#include <string>

using namespace std;
string leftPad(const string &input, int width) {
    if (width <= input.length()) {
        return input; // No padding needed
    }
    
    int paddingLength = width - input.length();
    string padding(paddingLength, ' '); // Create a string of spaces
    
    return padding + input; // Concatenate padding and input string
}

int main() {
    string input = "Hello, World!";
    int desiredWidth = 20;
    
    string paddedString = leftPad(input, desiredWidth);
    cout << paddedString << endl;
    
    return 0;
}
