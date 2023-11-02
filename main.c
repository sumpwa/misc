#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>



float Q_rsqrt(float number) {

    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    printf("\nInput: %f", number);
    printf("\nThree Halves: %f", threehalfs);
    

    x2 = number * 0.5F;
    printf("\n\nx2: %f", x2);
    printf("\nx2 is your number divided by 2");
  
    y = number;

    i = * (long *) &y;              // Evil floating point bit level hacking
    printf("\n\nInitial approximation: %ld", i);
    printf("\nThis is your number's floating point values as stored in memory, reinterpreted as an integer. Note that it has hex values to shorthand the binary code from memory.");

    i = 0x5f3759df - (i >> 1);      // Magic number for approximation
    printf("\n\nMagic number: %ld", i);
    printf("\nThe magic number is the difference between 0x5f375df and your number divided by 2");

    y = * (float *) &i; // converts magic number back to a floating point number
    printf("\n\ny: %.15f", y);
    printf("\ny is the magic number converted back to a FPU.");

    y = y * (threehalfs - (x2 * y * y));   // 1st iteration
    printf("\n\n1st iteration of Newton's Method on y: %.15f\n", y);
    

    y = y * (threehalfs - (x2 * y * y));   // 2nd iteration
    printf("\n2nd iteration of Newton's method on y: %.15f", y);
    printf("\nNote: The original algorithm had this commented out. I uncommented it to show Newton's method getting closer to the actual inverse square root with each iteration.\n\n");

    return y;
    
}

uint64_t fibonacci(int input) {
    int count = 1;
    uint64_t first = 0;
    uint64_t last = 0;
    uint64_t fibo = 1;

    while (count < input) {

        printf("%llu ", fibo);
        first = last;
        last = fibo;
        fibo = first + last;
        count++;
        }
    
    return fibo;
}

double euler(int input) {
    int eulercount = 0;
    double eulerresult = 0.0;
    while( eulercount <= input ) {
        eulerresult = eulerresult + 1.0 / tgamma(eulercount);
        eulercount++;
    }
    return eulerresult;
}

void fizzbuzz(int fizzarg, int buzzarg) {
    printf("\nRunning Fizzbuzz...\n\n");
    int fizzcount = 0;
    int buzzcount = 0;
    int fbcount = 0;

    for (int steps = 1; steps <= 100; steps++) {

        if((steps % fizzarg==0) && (steps % buzzarg==0)) {
            printf("Fizzbuzz! ");
            fbcount++;
        } else if(steps % buzzarg == 0) {
            buzzcount++;
            printf("Buzz! ");
        } else if(steps % fizzarg == 0) {
            fizzcount++;
            printf("Fizz! ");
        } else {
            printf("%d ", steps);
        }
    }

    printf("\nFizz count: %d", fizzcount);
    printf("\nBuzz count: %d", buzzcount);
    printf("\nFizzbuzz count: %d\n", fbcount);
    printf("End of Fizzbuzz\n");
}

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

    while(pi_in < 5) {
        
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

int evens (int first, int last) {
    int sum = 0;
    
    if (first > last) {
        return evens(last, first);
    }

    for (int i = first; i <= last; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    printf("Hello World!\n\n");

    int option;
    printf("Select an option or press any other key to quit.\n1.) Sum even numbers\n2.) Quake 3 Fast Inverse Square Root\n3.) Fibonacci Sequence\n4.) Estimate Euler's number\n5.) Estimate Pi\n6.) Play Fizzbuzz\n");
    scanf("%d", &option);
    switch(option) {

    case 1:
        int a, b;
        
        printf("Enter two whole numbers: ");
        scanf("%d %d", &a, &b);
        printf("The sum of all even numbers between %d and %d is %d.\n\n", a, b, evens(a, b));
        
        break;

    case 2:
        float result = 0.0;
        float number = 0.0;

        printf("Enter a number to calculate the inverse square root: ");
        scanf_s("%f", &number);
        result = Q_rsqrt(number);
        printf("Final result: %.15f\n", result);
        float SquareRoot = 1/sqrtf(number);
        printf("Compared to standard C inverse square root function: %.15f\n\n", SquareRoot);
        
        break;

    case 3:
        int fibiter = 0;

        printf("\nEnter how many iterations of the fibonacci sequence to calculate: ");
        scanf_s("%llu", &fibiter);
        printf("%llu \n", fibonacci(fibiter));
        
        break;

    case 4:
        int eulersteps = 0;

        printf("\n\nNow let's calculate Euler's number");
        printf("\nEnter how many steps to perform: ");
        scanf_s("%i", &eulersteps);
        printf("Euler's Number: %.15lf\n", euler(eulersteps));
        printf("\nCompared to the built in e function: %.15lf\n", M_E);
        printf("Press any key to continue. \n");
        while (getchar() != '\n'); // Clear the input buffer
        getchar(); // Wait for Enter key press

        break;
 
    case 5:
        int pi_input = 0;
        
        printf("\nCalculating pi with the Gauss-Legendere Algorithm with 5 steps");
        printf("\nPi is: %.15lf", picalc(pi_input));
        printf("\nCompared to the built in pi function: %.15lf\n", M_PI);
        break;

    case 6:
        int aFizz = 0;
        int aBuzz = 0;

        printf("\nEnter values for Fizz and Buzz: ");
        scanf_s("%d %d", &aFizz, &aBuzz);
        fizzbuzz(aFizz, aBuzz);
        
        break;

    default:

    }

    printf("End of program. Press any key to quit. \n");
    while (getchar() != '\n'); // Clear the input buffer
    getchar(); // Wait for Enter key press
    
    return 0;
} 