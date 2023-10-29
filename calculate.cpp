/*
I did my best to follow code_report's video on refactoring a C function to C++
This function takes two inputs, finds every even number, and adds them all together
*/

#include <iostream>
#include <ranges>
#include <numeric>

using std::cout;
using std::cin;
using std::accumulate;


namespace rv = std::views;

int calculate(int first, int last) {
    if (last < first) {
        return 0;
    }
    auto even = [](auto e) { return e % 2 == 0; };
    auto evens = rv::iota(first, last + 1)
                | rv::filter(even);
    return accumulate(evens.begin(), evens.end(), 0); 
}

int main(int argc, char *argv[]) {
    int in1 = 0;
    int in2 = 0;

    cout << "Enter the first in the range: \n";
    cin >> in1 ;

    cout << "Enter the second in the range: \n";
    cin >> in2 ;
    
    int result = calculate(in1, in2);
    cout << "Result: \n" << result;
    
    return 0;
}