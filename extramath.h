//extramath.h
//extra math functions

#include <stdio.h>
#include <math.h>

//function to estimate the perimeter of an ellipse using one of Ramanujan's formulas.
//takes in two inputs, a and b, which are the major and minor radii of the ellipse.

float ellipse_perimeter(float a, float b) {

    float result = 0.0;

    //swap a and b so that a is larger
    if (a < b) {
        float temp = a;
        a = b;
        b = temp;
    }

    //if either a or b is zero, return 4a or 4b
    if (a == 0.0 || b == 0.0) {
        result = 4.0 * (a + b);
        return result;
    }


    //if a = b then this is a circle, use 2*pi*r instead
    if (a == b) {
        result = 2 * M_PI * a;
        return result;
    }

    //if a < 0 or b < 0, a = a * -1 and b = b * -1
    if (a < 0.0) {
        a = a * -1.0;
    }
    if (b < 0.0) {
        b = b * -1.0;
    }
    
    
    result = M_PI*(3*(a+b)-sqrt((3*a+b)*(a+3*b)));
    return result;
}

//convert from Celsius to Fahrenheit
float ctof(float c) {
    return c * 9.0 / 5.0 + 32.0;
}

//convert from Fahrenheit to Celsius
float ftoc(float f) {
    return (f - 32.0) * 5.0 / 9.0 ;
}
