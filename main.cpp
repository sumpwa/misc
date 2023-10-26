#include <iostream>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <string>

using std::cout, std::cin, std::string, std::fixed, std::setprecision;

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
        
        pi_anext = (pi_a + pi_b) / 2.0;
        pi_bnext = sqrt(pi_a * pi_b);
        pi_tnext = pi_t - pi_p * (pi_a - pi_anext) * (pi_a - pi_anext);
        pi_pnext = 2.0 * pi_p;
        pie = ((pi_a + pi_b) * (pi_a + pi_b)) / (4.0 * pi_t);
        pi_a = pi_anext;
        pi_b = pi_bnext;
        pi_t = pi_tnext;
        pi_p = pi_pnext;

        pi_in++;
        }
    return pie;
}

float Q_rsqrt(float number){

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
    cout << '\n' << "Note: The original algorithm had this commented out. I uncommented it to show Newton's method getting closer to the actual inverse square root with each iteration." << '\n';

    return y;
    
}

uint64_t fibonacci(int input){
    int count = 1;
    uint64_t first = 0;
    uint64_t last = 0;
    uint64_t fibo = 1;

    while (count < input){

        cout << fibo << '\n';
        first = last;
        last = fibo;
        fibo = first + last;
        count++;
        }
    
    return fibo;
}

double euler(int input){
    int eulercount = 0;
    double eulerresult = 0.0;
    while( eulercount <= input ){
        eulerresult = eulerresult + 1.0 / tgamma(eulercount);
        eulercount++;
    }
    return eulerresult;
}

string fizzbuzz(int fizzin, int buzzin){

    int fizzcount = 0;
    int buzzcount = 0;
    int fbcount = 0;
    int nFB = 1;

    for (nFB; nFB <= 100; nFB++){

        if((nFB % fizzin==0) && (nFB %buzzin==0)){
            cout << "Fizzbuzz!" << '\n';
            fbcount++;
        }
        else if(nFB % buzzin == 0){
            buzzcount++;
            cout << "Buzz!" << '\n';
        }
        else if(nFB % fizzin == 0){
            fizzcount++;
            cout << "Fizz!" << '\n';
        }
        else{
            cout << nFB << '\n';
        }
    }

    cout << "Fizz count: " << fizzcount;
    cout << '\n' << "Buzz count: " << buzzcount;
    cout << '\n' << "Fizzbuzz count: " << fbcount << '\n';
    return "End of Fizzbuzz";
}

int main(int argc, char *argv[]){
    cout << "Hello World!" << '\n' << '\n';

    float result;
    float number;

    cout << "Enter a number to calculate the inverse square root: " << '\n' << '\n';
    cin >> number;
    
    result = Q_rsqrt(number);

    cout << fixed;
    cout << setprecision(12);
    cout << "Final result: " << result << '\n';
    float SquareRoot = 1/sqrtf(number);
    cout << fixed;
    cout << setprecision(12);
    cout << "Compared to standard C inverse square root function: " << SquareRoot << '\n' << '\n';
    
    int fibiter = 0;
    cout << '\n' << "Enter how many iterations of the fibonacci sequence to calculate: " << '\n';
    cin >> fibiter;
    cout << fibonacci(fibiter) << '\n';
    
    cout << '\n' << "Now let's calculate Euler's number";
    int eulersteps = 0;
    cout << '\n' << "Enter how many steps to perform:";
    cin >> eulersteps;
    cout << fixed;
    cout << setprecision(12);
    cout << "Euler's Number: " << euler(eulersteps) << '\n';

    int FIZZARG = 0;
    int BUZZARG = 0;

    cout << '\n' << "Enter values for Fizz and Buzz: " << '\n';
    cin >> FIZZARG >> BUZZARG;
    cout << '\n' << "Running Fizzbuzz..." << '\n';
    cout << fizzbuzz(FIZZARG, BUZZARG);

    int pi_input = 0;
    cout << '\n';
    cout << '\n' << "Caclulating pi with the Gauss-Legendere Algorithm with 4 steps";
    cout << '\n' << "Pi is: " << picalc(pi_input);
    cout << '\n' << "Compared to the built in pi function: " << M_PI << '\n';

    cout << '\n' << "End of program";
    return 0;
}