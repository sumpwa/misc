/*
Calculating pi with the Gauss-Legendere Formula
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
double a = 1.0;
double b = 1.0 / sqrt(2);
double t = 0.25;
double p = 1.0;
double anext = 0.0;
double bnext = 0.0;
double tnext = 0.0;
double pnext = 0.0;
double pie = 0.0;
int n = 0;
while(n<10){
    
    anext = (a + b)/2.0;
    bnext = sqrt(a * b);
    tnext = t - p * (a - anext)*(a - anext);
    pnext = 2.0 * p;
    pie = ((a + b)*(a + b)) / (4.0 * t);
    a = anext;
    b = bnext;
    t = tnext;
    p = pnext;

    n = n+1;
}
printf("pi: %.12lf\n", pie);
return 0;
}