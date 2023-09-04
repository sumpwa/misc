#include <iostream>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <string>

using namespace std;

string leftpad(string str, int len, char ch = ' ') {
    if (ch == 0) ch = ' '; // Using space as default padding character
    len -= str.length();
    
    while (len-- > 0) {
        str = ch + str;
    }
    
    return str;
}

float Q_rsqrt(float number) {

    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    cout << "\n\nInput: " << number;
    cout << "\nThree Halves: " << threehalfs;
    

    x2 = number * 0.5F;
    cout << "\n\nx2: " << x2;
    cout << "\nx2 is your number divided by 2";
  
    y = number;

    i = * (long *) &y;              // Evil floating point bit level hacking
    cout << "\n\nInitial approximation: " << i;
    cout << "\nThis is your number's floating point values as stored in memory, reinterpreted as an integer. Note that it has hex values to shorthand the binary code from memory.";

    i = 0x5f3759df - (i >> 1);      // Magic number for approximation
    cout << "\n\nMagic number: " << i;
    cout << "\nThe magic number is the difference between 0x5f375df and your number divided by 2";

    y = * (float *) &i; // converts magic number back to a floating point number
    cout << "\n\ny: " << y;
    cout << "\ny is the magic number converted back to a FPU.";

    y = y * (threehalfs - (x2 * y * y));   // 1st iteration
    cout << "\n\n1st iteration of Newton's Method on y: " << y;
    

    y = y * (threehalfs - (x2 * y * y));   // 2nd iteration
    cout << "\n\n2nd iteration of Newton's method on y: " << y;
    cout << "\nNote: The original algorithm had this commented out. I uncommented it to show Newton's method getting closer to the actual inverse square root with each iteration.";

    return y;
    
}


int main(){
    cout << "Hello World!";

    float result;
    float number;

    cout << "\n\nEnter a number to calculate the inverse square root: ";
    cin >> number;

    result = Q_rsqrt(number);

    cout << std::fixed;
    cout << std::setprecision(12);
    cout << "\n\nFinal result: " << result;
    float SquareRoot = 1/sqrtf(number);
    cout << std::fixed;
    cout << std::setprecision(12);
    cout << "\nCompared to standard C inverse square root function: " << SquareRoot;

    cout << "\n\nWhat to do next...";
    cout << "\nPress any key to continue...\n";
    system("read");
    int fibiter = 0;
    cout << "\n\nEnter how many iterations of the fibonacci sequence to calculate: \n";
    cin >> fibiter;
    int count = 0;
    uint64_t first = 0;
    uint64_t last = 0;
    uint64_t fibo = 0;

while (fibiter >= count) 
{
    if (fibo == 0) {
        cout << "\n " << fibo;
        fibo = 1;
    }
    else {
    cout << "\n " << fibo;
    first = last;
    last = fibo;
    fibo = first + last;
    }
    count++;
}
    cout << "\nPress any key to continue...\n";
    system("read");
    cout << "\n\nNow let's calculate Euler's number";
    int eulercount = 0;
    cout << "\nEnter how many steps to perform:";
    cin >> eulercount;

    double euler = 0.0;
    int eulersteps = 1;
    while(eulersteps<=eulercount){
    euler = euler + 1.0 / tgamma(eulersteps);
    eulersteps = eulersteps+1;
    
    }

    cout << std::fixed;
    cout << std::setprecision(12);
    cout << endl << "Euler's Number: " << euler;
    cout << endl << "Press any key to continue..." << endl;
    system("read");

    cout << endl << "Leftpad Demonstration" << endl;
    string input = "hello";
    int desiredLength = 10;
    char paddingChar = '*';
    
    string output = leftpad(input, desiredLength, paddingChar);
    cout << output << endl;

    return 0;
}
