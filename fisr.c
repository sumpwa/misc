//Quake 3 FISR Algorithm With Printed Outputs
//This is my attempt to show in steps what happens in the Quake 3 FISR algorithm. Each time something is calculated, its result is printed. The source code has expanded comments as well.


#include <stdio.h>
#include <stdint.h>
#include <math.h>

float Q_rsqrt(float number) {

    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    printf("Input: %f\n\n", number);
    printf("Three Halves: %f\n\n", threehalfs);

    x2 = number * 0.5F;
    printf("x2: %f\n", x2);
    printf("x2 is your number divided by 2 \n\n");
    y = number;

    i = * (long *) &y;              // Evil floating point bit level hacking
    printf("Initial approximation: %lx\n", i);
    printf("This is your number's floating point values as stored in memory, reinterpreted as an integer. Note that it has hex values to shorthand the binary code from memory. \n\n");

    i = 0x5f3759df - (i >> 1);      // Magic number for approximation
    printf("Magic number: %lx\n", i);
    printf("The magic number is the difference between 0x5f375df and your number divided by 2 \n\n");

    y = * (float *) &i; // converts magic number back to a floating point number
    printf("y: %f\n", y);
    printf("y is the magic number converted back to a FPU. \n\n");

    y = y * (threehalfs - (x2 * y * y));   // 1st iteration
    printf("1st iteration of Newton's Method on y: %f\n\n", y);

    y = y * (threehalfs - (x2 * y * y));   // 2nd iteration
    printf("2nd iteration of Newton's method on y: %f\n", y);
    printf("Note: The original algorithm had this commented out. I uncommented it to show Newton's method getting closer to the actual inverse square root with each iteration. \n\n");

    return y;
}

int main(int argc, char *argv[]) {
    float result;
    float number;

    printf("Enter a number to calculate the inverse square root: ");
    scanf("%f", &number);

    result = Q_rsqrt(number);

    printf("Final result: %f\n", result);
    float SquareRoot = 1/sqrtf(number);
    printf("Compared to standard C inverse square root function: %f\n", SquareRoot);

    return 0;
}
