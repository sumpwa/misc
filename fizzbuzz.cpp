/*
fizzbuzz.cpp
If your number is divisible by 3 say fizz
If your number is divisible by 5 say buzz
If both say fizzbuzz
Otherwise say your number
*/
#include <iostream>
int main(){
    int FIZZARG = 3;
    int BUZZARG = 5;
    int fizzcount = 0;
    int buzzcount = 0;
    int fbcount = 0;
    std::cout << "Let's play Fizzbuzz!\n";
    std::cout << "\nPress Enter to continue...\n";
    std::cin.get();

    for (int n = 1; n <= 100; n++){
        if((n%FIZZARG==0)&&(n%BUZZARG==0)){
            std::cout << n << " Fizzbuzz!\n";
            fbcount++;
        }
        else if(n%BUZZARG==0){
            buzzcount++;
            std::cout << n << " Buzz!\n";
        }
        else if(n%FIZZARG==0){
            fizzcount++;
            std::cout << n << " Fizz!\n";
        }
        else
            std::cout << n << "\n";
    }
    std::cout << "Fizz count: " << fizzcount;
    std::cout << "\nbuzz count: " << buzzcount;
    std::cout << "\nFizzbuzz count: " << fbcount;
    std::cout << "\n\nEnd of program";
    return 0;
}