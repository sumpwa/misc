#include <stdio.h>
#include <math.h>

int main() {

    int a = 3-3*6+2;
    printf("stupid PEMDAS test: 3-3*6+2 = %d\n", a);
    
    float b = 0.1;
    float c = 0.2;
    float d = b + c;
    if (d != 0.3) {
        
        printf("b = %.20f\n", b);
        printf("c = %.20f\n", c);
        printf("b + c = %.20f\n", 0.1+0.2);
        printf("\nComputers can't do math. Press any key to quit.\n");

        while (getchar() != '\n'); // Clear the input buffer
    }
    return 0;
}