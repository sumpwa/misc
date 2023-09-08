//calculator.cpp
//basic five function calculator to add, subtract, multiply, divide, and raise exponents

#include <iostream>
#include <cmath>
using std::cout, std::cin;

int main() {
    float firstnumber = 0.0;
    float secondnumber = 0.0;
    char operation;
    float result = 0.0;

    cout << "Enter the calculation you want to perform: " << '\n';
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
    
    default:
        cout << "Error: invalid operator!" << '\n';
        return 1;    
        break;
    }
    cout << "End of program" << '\n';
    return 0;
}
