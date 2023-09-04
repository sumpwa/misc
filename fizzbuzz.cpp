/*
fizzbuzz.cpp
If your number is divisible by 3 say fizz
If your number is divisible by 5 say buzz
If both say fizzbuzz
Otherwise say your number
*/
#include <iostream>
using namespace std;

int main(){
    int FIZZARG = 3;
    int BUZZARG = 5;
    int fizzcount = 0;
    int buzzcount = 0;
    int fbcount = 0;
    cout << "Let's play Fizzbuzz!\n";
    cout << "\nPress Enter to continue...\n";
    cin.get();

    for (int n = 1; n <= 100; n++){
        if((n%FIZZARG==0)&&(n%BUZZARG==0)){
            cout << n << " Fizzbuzz!\n";
            fbcount++;
        }
        else if(n%BUZZARG==0){
            buzzcount++;
            cout << n << " Buzz!\n";
        }
        else if(n%FIZZARG==0){
            fizzcount++;
            cout << n << " Fizz!\n";
        }
        else
            cout << n << "\n";
    }
    cout << "Fizz count: " << fizzcount;
    cout << "\nbuzz count: " << buzzcount;
    cout << "\nFizzbuzz count: " << fbcount;
    cout << "\n\nEnd of program";
    return 0;
}