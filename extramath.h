//extramath.h
//extra math functions

#include <stdio.h>
#include <math.h>

//function to estimate the perimeter of an ellipse using one of Ramanujan's formulas.
//takes in two inputs, a and b, which are the major and minor radii of the ellipse.

float ellipse_perimeter(float a, float b) {

    float result = 0.0;

    //swap a and b so that a is larger
    if (b > a) {
        float temp = a;
        a = b;
        b = temp;
    }

    //if a = b then this is a circle, use 2*pi*r instead
    if (a == b) {
        result = 2 * M_PI * a;
        return result;
    }
    
    result = M_PI*(3*(a+b)-sqrt((3*a+b)*(a+3*b)));
    return result;
}

