//Program to check if a 64 bit integer is a prime number.
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(uint64_t n) {
    if (n <= 1) {
        return false;
    }
    
    if (n <= 3) {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    for (uint64_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    uint64_t num;

    printf("Enter a 64-bit integer: ");
    scanf("%lld", &num);

    if (is_prime(num)) {
        printf("%lld is a prime number.\n", num);
    } else {
        printf("%lld is not a prime number.\n", num);
    }

    printf("End of program. Press any key to quit. \n");
    while (getchar() != '\n'); // Clear the input buffer
    getchar(); // Wait for key press

    return 0;
}
