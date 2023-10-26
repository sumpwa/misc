#include <stdio.h>

int ackermann(int m, int n){
    if (m == 0){
        return n + 1;
		
    } else if (m > 0 && n == 0){
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main(int argc, char *argv[]){
    for (int m = 0; m <= 6; m++){
        for (int n = 0; n <= 6; n++){
        printf("Ackermann(%i, %i): %i\n", m, n, ackermann(m, n));
        }
    }

    return 0;
}
