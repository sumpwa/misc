#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int a = 3-3*6+2;
    printf("%d", a);
    

    float b = 0.1;
    float c = 0.2;
    float d = b + c;
    if (d != 0.3) {
        printf("\nI can't do math");
        printf("\n%.20f", b);
        printf("\n%.20f", c);
        printf("\n%.20f", 0.1+0.2);
    }
    return 0;
}