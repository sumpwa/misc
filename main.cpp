#include <iostream>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <string>

using std::cout, std::cin, std::string, std::fixed, std::setprecision;



double picalc(int pi_in) {
double pie = 0.0;
double pi_a = 1.0;
double pi_b = 1.0 / sqrt(2);
double pi_t = 0.25;
double pi_p = 1.0;
double pi_anext = 0.0;
double pi_bnext = 0.0;
double pi_tnext = 0.0;
double pi_pnext = 0.0;
double pi_pie = 0.0;
while(pi_in<4){
    
    pi_anext = (pi_a + pi_b)/2.0;
    pi_bnext = sqrt(pi_a * pi_b);
    pi_tnext = pi_t - pi_p * (pi_a - pi_anext)*(pi_a - pi_anext);
    pi_pnext = 2.0 * pi_p;
    pie = ((pi_a + pi_b)*(pi_a + pi_b)) / (4.0 * pi_t);
    pi_a = pi_anext;
    pi_b = pi_bnext;
    pi_t = pi_tnext;
    pi_p = pi_pnext;

    pi_in++;
    }
    return pie;
}

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

    cout << '\n' << '\n' << "Input: " << number;
    cout << '\n' << "Three Halves: " << threehalfs;
    

    x2 = number * 0.5F;
    cout << '\n' << '\n' << "x2: " << x2;
    cout << '\n' << "x2 is your number divided by 2";
  
    y = number;

    i = * (long *) &y;              // Evil floating point bit level hacking
    cout << '\n' << '\n' << "Initial approximation: " << i;
    cout << '\n' << "This is your number's floating point values as stored in memory, reinterpreted as an integer. Note that it has hex values to shorthand the binary code from memory.";

    i = 0x5f3759df - (i >> 1);      // Magic number for approximation
    cout << '\n' << '\n' << "Magic number: " << i;
    cout << '\n' << "The magic number is the difference between 0x5f375df and your number divided by 2";

    y = * (float *) &i; // converts magic number back to a floating point number
    cout << '\n' << '\n' << "y: " << y;
    cout << '\n' << "y is the magic number converted back to a FPU.";

    y = y * (threehalfs - (x2 * y * y));   // 1st iteration
    cout << '\n' << '\n' << "1st iteration of Newton's Method on y: " << y;
    

    y = y * (threehalfs - (x2 * y * y));   // 2nd iteration
    cout << '\n' << '\n' << "2nd iteration of Newton's method on y: " << y;
    cout << '\n' << "Note: The original algorithm had this commented out. I uncommented it to show Newton's method getting closer to the actual inverse square root with each iteration.";

    return y;
    
}


int main() {
    cout << "Hello World!" << '\n' << '\n';

    float result;
    float number;

    cout << "Enter a number to calculate the inverse square root: " << '\n' << '\n';
    cin >> number;
    cin.get();

    result = Q_rsqrt(number);

    cout << fixed;
    cout << setprecision(12);
    cout << "Final result: " << result << '\n';
    float SquareRoot = 1/sqrtf(number);
    cout << fixed;
    cout << setprecision(12);
    cout << "Compared to standard C inverse square root function: " << SquareRoot << '\n' << '\n';

    cout << "What to do next..." << '\n';
    cout << "Press Enter to continue..." << '\n';
    cin.get();
    int fibiter = 0;
    cout << '\n' << "Enter how many iterations of the fibonacci sequence to calculate: " << '\n';
    cin >> fibiter;
    int count = 0;
    uint64_t first = 0;
    uint64_t last = 0;
    uint64_t fibo = 0;

while (fibiter >= count) 
{
    if (fibo == 0) {
        cout << '\n' << fibo;
        fibo = 1;
    }
    else {
    cout << '\n' << fibo;
    first = last;
    last = fibo;
    fibo = first + last;
    }
    count++;
}
    cout << '\n' << "Press Enter to continue..." << '\n';
    cin.get();
    cout << '\n' << "Now let's calculate Euler's number";
    int eulercount = 0;
    cout << '\n' << "Enter how many steps to perform:";
    cin >> eulercount;

    double euler = 0.0;
    int eulersteps = 1;
    while(eulersteps<=eulercount){
    euler = euler + 1.0 / tgamma(eulersteps);
    eulersteps = eulersteps+1;
    
    }

    cout << fixed;
    cout << setprecision(12);
    cout << '\n' << "Euler's Number: " << euler;
    cout << '\n' << "What to do next..." << '\n';
    cout << '\n' << "Press Enter to continue..." << '\n';
    cin.get();


    cout << '\n' << "Leftpad Demonstration" << '\n';
    string LeftInput = "hello";
    int desiredLength = 10;
    char paddingChar = '*';
    
    string output = leftpad(LeftInput, desiredLength, paddingChar);
    cout << output << '\n';

    cout << '\n' << "What to do next..." << '\n';
    cout << '\n' << "Press Enter to continue..." << '\n';
    cin.get();

    cout << "Let's play Fizzbuzz!" << '\n';
    cout << '\n' << "Press Enter to continue..." << '\n';
    cin.get();

    int FIZZARG = 3;
    int BUZZARG = 5;
    int fizzcount = 0;
    int buzzcount = 0;
    int fbcount = 0;

    for (int nFB = 1; nFB <= 100; nFB++){
        if((nFB%FIZZARG==0)&&(nFB%BUZZARG==0)){
            cout << nFB << " Fizzbuzz!" << '\n';
            fbcount++;
        }
        else if(nFB%BUZZARG==0){
            buzzcount++;
            cout << nFB << " Buzz!" << '\n';
        }
        else if(nFB%FIZZARG==0){
            fizzcount++;
            cout << nFB << " Fizz!" << '\n';
        }

    }
    cout << "Fizz count: " << fizzcount;
    cout << '\n' << "Buzz count: " << buzzcount;
    cout << '\n' << "Fizzbuzz count: " << fbcount;
  
    cout << '\n' << "What to do next..." << '\n';
    cout << '\n' << "Press Enter to continue..." << '\n';
    cin.get();

    cout << '\n' << "Let's calculate Pi with the Gauss-Legendere Algorithm..." << '\n';
    int pi_input = 0;
    cout << '\n' << "Pi is: " << picalc(pi_input) << '\n';
    cout << '\n' << "Compared to the built in pi function: " << M_PI << '\n';

    cout << '\n' << "End of program";
    return 0;
}
