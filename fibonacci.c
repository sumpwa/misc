#include <stdio.h>
#include <stdint.h>
/*
f = first number to add
l = second number to add
s = f + l summed together
*/
int main() {
    uint64_t f = 0;
    uint64_t l = 0;
    uint64_t s = 0;

while (s < 9223372036854775807) 
{
    if (s == 0) {
        printf("\n %lu", s);
        s = 1;
    }
    else {
    printf("\n %lu", s);
    f = l;
    l = s;
    s = f + l;
    }
}
    return 0;
}