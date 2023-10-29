//calculator.cpp
//basic five function calculator to add, subtract, multiply, divide, and raise exponents

#include <iostream>
#include <cmath>
using std::cout, std::cin;

int factorial (int input) {
    int sum = 1;
    for (int count = 1; count <=input; count++) {
        sum = sum * count;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    float firstnumber = 0.0;
    float secondnumber = 0.0;
    char operation;
    float result = 0.0;

    cout << "Enter the calculation you want to perform: " << '\n';
    if (operation = '!') {
        cin >> firstnumber >> operation;
    }

    cin >> firstnumber >> operation >> secondnumber;
 
    switch (operation) {
    case '+':
        result = firstnumber + secondnumber;
        cout << firstnumber << " + " << secondnumber << " = " << result << '\n';
        break;

    case '-':
        result = firstnumber - secondnumber;
        cout << firstnumber << " - " << secondnumber << " = " << result << '\n';
        break;

    case '*':
        result = firstnumber * secondnumber;
        cout << firstnumber << " * " << secondnumber << " = " << result << '\n';
        break;

    case '/':
        if(secondnumber == 0){
            cout << "Error: dividing by zero is undefined!" << '\n';
            return 1;
        }
        result = firstnumber / secondnumber;
        cout << firstnumber << " / " << secondnumber << " = " << result << '\n';
        break;  

    case '^':
        result = pow(firstnumber, secondnumber);
        cout << firstnumber << "^" << secondnumber << " = " << result << '\n';
        break;  

    case '!':
        if(firstnumber<0) {
            cout << "Error: Factorial cannot be used on negative numbers";
            return 1;
        }
        result = factorial(firstnumber);
        cout << firstnumber << "! = " << result << '\n';
        break;
    
    default:
        cout << "Error: invalid operator!" << '\n';
        return 1;    
        break;
    }
    cout << "End of program" << '\n';
    return 0;
}
