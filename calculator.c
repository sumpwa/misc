//calculator.c
//basic six function calculator to add, subtract, multiply, divide, factorial, and raise exponents

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


long long factorial (int input) {
    long long sum = 1;
    for (int count = 1; count <=input; count++) {
        sum = sum * count;
    }
    return sum;
}


int main(int argc, char *argv[]) {

    double firstnumber = 0.0;
    double secondnumber = 0.0;
    char operation;
    double result = 0.0;
    
    printf("Enter the calculation you want to perform (+, -, *, /, ^, !): ");

    //quits the program if the user enters invalid inputs
    if((scanf("%lf %c", &firstnumber, &operation) != 2)) 
    {
        printf("Error: Invalid input\n");
        return 1;
    }
    else
    
    switch (operation) {
    case '+':
        scanf(" %lf", &secondnumber);
        result = firstnumber + secondnumber;
        printf("%.4lf + %.4lf = %.4lf\n", firstnumber, secondnumber, result);
        break;

    case '-':
        scanf(" %lf", &secondnumber);
        result = firstnumber - secondnumber;
        printf("%.4lf - %.4lf = %.4lf\n", firstnumber, secondnumber, result);
        break;

    case '*':
        scanf(" %lf", &secondnumber);
        result = firstnumber * secondnumber;
        printf("%.4lf * %.4lf = %.4lf\n", firstnumber, secondnumber, result);
        break;

    case '/':
        scanf(" %lf", &secondnumber);

        //disallow divide by zero
        if(secondnumber == 0) {
            printf("Error: dividing by zero is undefined! \n");
            return 1;
        }

        result = firstnumber / secondnumber;
        printf("%.4lf / %.4lf = %.4lf\n", firstnumber, secondnumber, result);
        break;  

    case '^':
        scanf(" %lf", &secondnumber);
        result = pow(firstnumber, secondnumber);
        printf("%.4lf ^ %.4lf = %.4lf\n", firstnumber, secondnumber, result);
        break;  

    case '!':
        
        //disallow factorial of negative numbers
        if(firstnumber < 0) {
            printf("Error: Factorial cannot be used on negative numbers \n");
            return 1;
        }

        printf("%ld! = %lld\n", (int)firstnumber, factorial((int)firstnumber));
        break;

    default:
        //quits the program if the user enters an invalid operation
        printf("Error: invalid operator! \n");

        return 1;    
        break;
    }

    printf("Calculation complete. Press any key to quit. \n");

    while (getchar() != '\n'); // Clear the input buffer
    getchar(); // Wait for Enter key press

    return 0;
}
