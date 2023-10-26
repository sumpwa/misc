/*
Calculating pi with Leibniz's Formula
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
double pie = 0.0;
int n = 1;
while(n<10000000){
    if(n %2 != 0){
    pie = pie + 4.0/((2*n)-1);
    }
    else {
    pie = pie - 4.0/((2*n)-1);
    }
    n = n+1;
}
printf("pi: %lf\n", pie);
return 0;
}