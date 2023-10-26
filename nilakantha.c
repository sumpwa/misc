/*
Calculating pi with Nilakantha's Formula
This algorithm diverges from pi at large numbers of n due to floating point errors.
*/
#include <stdio.h>

int main(int argc, char *argv[]){
double pie = 3.0;
int n = 2;
int sign = 1;

while ( n <= 1000){
   
    pie = pie + sign * (4.0/((n)*(n+1)*(n+2)));
    sign = -sign;
    printf("pi: %lf\n", pie);
    n = n+2;
}

printf("\nFinal Result: %lf", pie);
return 0;
}
