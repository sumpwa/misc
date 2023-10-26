/*
Formula to calculate Euler's number
*/
#include <stdio.h>
#include <math.h>

// have to write my own factorial algo since C doesn't include one and I can't be bothered to rewrite this in Python
/*edit: using the gamma function instead. Keeping the factorial algo here in case I need it later.
long fact(int a){
    if (a == 0 || a == 1){
        return 1;
    } else {
        long result = 1;
        for (int i = 2; i <= a; ++i){
            result *= i;
        }
        return result;
    }
}
*/
int main(int argc, char *argv[]){
double euler = 0.0;
int n = 1;
while(n<20){
    euler = euler + 1.0 / tgamma(n);
    n = n+1;
    
}
    printf("Euler's Number: %.12lf\n", euler);
return 0;
}