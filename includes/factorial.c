#include <stdio.h>
#include "factorial.h"

int factorial (int input){
        int sum = 1;
        for (int count = 1; count <=input; count++){
            sum = sum * count;
        }
        return sum;
}