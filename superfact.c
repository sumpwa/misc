//superfact.c
//Program to calculate the superfactorial of a number. Formula for Superfactorial is sf(n) = n! * (n-1)! * (n-2)! * ... * 2! * 1!

#include <stdio.h>
#include <math.h>
#include <stdint.h>

int factorial (int input) {
    int sum = 1;
    for (int count = 1; count <=input; count++) {
        sum = sum * count;
    }
    return sum;
}

int64_t sf(int input) {
    int64_t sfsum = 1;
    for (int sfcount = 1; sfcount <= input; sfcount++) {
        sfsum = sfsum * factorial(sfcount);
    }
    return sfsum;
}

int main(int argc, char *argv[]) {

    int64_t number = 0;
    printf("Enter a number greater than 0: ");
    scanf_s("%d", &number);
    printf("Factorial: %d \n", factorial(number));
    printf("Superfactorial: %lld \n", sf(number));
    printf("End of program. Press any key to quit. \n");
    while (getchar() != '\n'); // Clear the input buffer
    getchar(); // Wait for key press
    return 0;

}