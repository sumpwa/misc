//evens.c
//takes two input numbers, finds the sum of all even numbers between them (inclusive), and prints the result.

#include <stdio.h>

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
    int a, b;
    printf("Enter two whole numbers: ");
    scanf("%d %d", &a, &b);
    printf("The sum of all even numbers between %d and %d is %d.\n", a, b, evens(a, b));

    return 0;
}