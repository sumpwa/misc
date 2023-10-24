//superfactorial.c
//Program to calculate the superfactorial of a number. Formula for Superfactorial is sf(n) = n! * (n-1)! * (n-2)! * ... * 2! * 1!

#include <stdio.h>
#include <math.h>
#include <stdint.h>

int fact(int input) {
        int sum = 1;
        for (int count = 1; count <=input; count++) {
            sum = sum * count;
        }
        return sum;
}

int sf(int input) {
        int sfsum = 1;
        for (int sfcount = 1; sfcount <= input; sfcount++) {
            sfsum = sfsum * fact(sfcount);
        }
        return sfsum;
}

int main() {
int64_t number = 0;
printf("Enter a number greater than 0: ");
scanf("%d", &number);
printf("Factorial: %lld \n", fact(number));
printf("Superfactorial: %lld", sf(number));
return 0;

}