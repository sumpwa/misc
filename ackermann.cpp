#include <iostream>
using namespace std;

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
		
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    for (int m = 0; m <= 4; ++m) {
        for (int n = 0; n <= 1; ++n) {
            cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;
        }
    }

    return 0;
}
