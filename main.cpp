#include <iostream>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;


double picalc(int pi_in){
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

    cout << endl << endl << "Input: " << number;
    cout << endl << "Three Halves: " << threehalfs;
    

    x2 = number * 0.5F;
    cout << endl << endl << "x2: " << x2;
    cout << endl << "x2 is your number divided by 2";
  
    y = number;

    i = * (long *) &y;              // Evil floating point bit level hacking
    cout << endl << endl << "Initial approximation: " << i;
    cout << endl << "This is your number's floating point values as stored in memory, reinterpreted as an integer. Note that it has hex values to shorthand the binary code from memory.";

    i = 0x5f3759df - (i >> 1);      // Magic number for approximation
    cout << endl << endl << "Magic number: " << i;
    cout << endl << "The magic number is the difference between 0x5f375df and your number divided by 2";

    y = * (float *) &i; // converts magic number back to a floating point number
    cout << endl << endl << "y: " << y;
    cout << endl << "y is the magic number converted back to a FPU.";

    y = y * (threehalfs - (x2 * y * y));   // 1st iteration
    cout << endl << endl << "1st iteration of Newton's Method on y: " << y;
    

    y = y * (threehalfs - (x2 * y * y));   // 2nd iteration
    cout << endl << endl << "2nd iteration of Newton's method on y: " << y;
    cout << endl << "Note: The original algorithm had this commented out. I uncommented it to show Newton's method getting closer to the actual inverse square root with each iteration.";

    return y;
    
}


int main(){
    cout << "Hello World!" << endl << endl;

    float result;
    float number;

    cout << "Enter a number to calculate the inverse square root: " << endl << endl;
    cin >> number;
    cin.get();

    result = Q_rsqrt(number);

    cout << fixed;
    cout << setprecision(12);
    cout << "Final result: " << result << endl;
    float SquareRoot = 1/sqrtf(number);
    cout << fixed;
    cout << setprecision(12);
    cout << "Compared to standard C inverse square root function: " << SquareRoot << endl << endl;

    cout << "What to do next..." << endl;
    cout << "Press Enter to continue..." << endl;
    cin.get();
    int fibiter = 0;
    cout << endl << "Enter how many iterations of the fibonacci sequence to calculate: " << endl;
    cin >> fibiter;
    int count = 0;
    uint64_t first = 0;
    uint64_t last = 0;
    uint64_t fibo = 0;

while (fibiter >= count) 
{
    if (fibo == 0) {
        cout << endl << fibo;
        fibo = 1;
    }
    else {
    cout << endl << fibo;
    first = last;
    last = fibo;
    fibo = first + last;
    }
    count++;
}
    cout << endl << "Press Enter to continue..." << endl;
    cin.get();
    cout << endl << "Now let's calculate Euler's number";
    int eulercount = 0;
    cout << endl << "Enter how many steps to perform:";
    cin >> eulercount;

    double euler = 0.0;
    int eulersteps = 1;
    while(eulersteps<=eulercount){
    euler = euler + 1.0 / tgamma(eulersteps);
    eulersteps = eulersteps+1;
    
    }

    cout << fixed;
    cout << setprecision(12);
    cout << endl << "Euler's Number: " << euler;
    cout << endl << "What to do next..." << endl;
    cout << endl << "Press Enter to continue..." << endl;
    cin.get();


    cout << endl << "Leftpad Demonstration" << endl;
    string LeftInput = "hello";
    int desiredLength = 10;
    char paddingChar = '*';
    
    string output = leftpad(LeftInput, desiredLength, paddingChar);
    cout << output << endl;

    cout << endl << "What to do next..." << endl;
    cout << endl << "Press Enter to continue..." << endl;
    cin.get();

    cout << "Let's play Fizzbuzz!" << endl;
    cout << endl << "Press Enter to continue..." << endl;
    cin.get();

    int FIZZARG = 3;
    int BUZZARG = 5;
    int fizzcount = 0;
    int buzzcount = 0;
    int fbcount = 0;

    for (int nFB = 1; nFB <= 100; nFB++){
        if((nFB%FIZZARG==0)&&(nFB%BUZZARG==0)){
            cout << nFB << " Fizzbuzz!" << endl;
            fbcount++;
        }
        else if(nFB%BUZZARG==0){
            buzzcount++;
            cout << nFB << " Buzz!" << endl;
        }
        else if(nFB%FIZZARG==0){
            fizzcount++;
            cout << nFB << " Fizz!" << endl;
        }

    }
    cout << "Fizz count: " << fizzcount;
    cout << endl << "Buzz count: " << buzzcount;
    cout << endl << "Fizzbuzz count: " << fbcount;
  
    cout << endl << "What to do next..." << endl;
    cout << endl << "Press Enter to continue..." << endl;
    cin.get();

    cout << endl << "Let's calculate Pi with the Gauss-Legendere Algorithm..." << endl;
    int pi_input = 0;
    cout << endl << "Pi is: " << picalc(pi_input) << endl;
    cout << endl << "Compared to the built in pi function: " << M_PI << endl;


    char testarray[] = {'q','w','e','r','t','y'};

    cout << testarray['6,7,3,6'] << endl;

    cout << endl << "End of program";
    return 0;
}
