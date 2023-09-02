#include <stdio.h>



int main(){
int bills = 0;
int pennies = 0;
int nickels = 0;
int dimes = 0;
int quarters = 0;
float total = 0.0;


    printf("How many dollar bills do you have? ");
    if (scanf("%d", &bills) != 1 || bills < 0) {
        printf("Invalid input for dollar bills.\n");
        return 1;
    }

    printf("How many quarters do you have? ");
    if (scanf("%d", &quarters) != 1 || quarters < 0) {
        printf("Invalid input for quarters.\n");
        return 1;
    }

    printf("How many dimes do you have? ");
    if (scanf("%d", &dimes) != 1 || dimes < 0) {
        printf("Invalid input for dimes.\n");
        return 1;
    }

    printf("How many nickels do you have? ");
    if (scanf("%d", &nickels) != 1 || nickels < 0) {
        printf("Invalid input for nickels.\n");
        return 1;
    }

    printf("How many pennies do you have? ");
    if (scanf("%d", &pennies) != 1 || pennies < 0) {
        printf("Invalid input for pennies.\n");
        return 1;
    }

    total = bills + quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + pennies * 0.01;
    printf("Your total is: $%.2f", total);


    return 0;
}