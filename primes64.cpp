//Program to check if a 64 bit integer is a prime number.
#include <iostream>
#include <cmath>

bool is_prime(u_int64_t n) {
    if (n <= 1) {
        return false;
    }
    
    if (n <= 3) {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    for (u_int64_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    u_int64_t num;

    std::cout << "Enter a 64-bit integer: ";
    std::cin >> num;

    if (is_prime(num)) {
        std::cout << num << " is a prime number." << std::endl;
    } else {
        std::cout << num << " is not a prime number." << std::endl;
    }



    return 0;
}
