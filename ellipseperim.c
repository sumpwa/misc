#include <stdio.h>
#include "extramath.h"

int main(int argc, char *argv[]) {
    float a, b, c, f;

    printf("Enter two numbers: ");

    scanf("%f %f", &a, &b);
    float perimeter = ellipse_perimeter(a, b);
    printf("Perimeter: %f\n", perimeter);

    printf("Enter degrees in C: ");
    scanf("%f", &c);
    float temp_c = ctof(c);
    printf("Temperature in F: %.2f\n", temp_c);


    printf("Enter degrees in F: ");
    scanf("%f", &f);
    float temp_f = ftoc(f);
    printf("Temperature in C: %.2f\n", temp_f);

    return 0;


}