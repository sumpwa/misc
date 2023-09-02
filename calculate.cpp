/*
I did my best to follow code_report's video on refactoring a C function to C++
This function takes two inputs, finds every even number, and adds them all together
*/

#include <iostream>
#include <ranges>
#include <numeric>
#include <cstdint>

namespace rv = std::views;
int calculate(int first, int last) {
    if (last >= first){
        auto even = [](auto e) { return e % 2 == 0; };
        auto evens = rv::iota(first, last + 1)
                   | rv::filter(even);
        return std::accumulate(evens.begin(), evens.end(), 0);
        
    } else {
        return 0;
    }
}

int main() {
    int in1 = 0;
    int in2 = 0;

    std::cout << "Enter the first in the range: \n";
    std::cin >> in1 ;

    std::cout << "Enter the second in the range: \n";
    std::cin >> in2 ;
    
    uint64_t result = calculate(in1, in2);
    std::cout << "Result: \n" << result;
    
    return 0;
}