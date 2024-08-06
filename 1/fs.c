#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


int to_factorial(unsigned int x, int buffer[]) {
    int mod, digits = 0, k = 2;
    while (x > 0) {
        mod = x % k;
        x /= k;
        buffer[digits++] = mod;
        k++;
    }
    return digits;
}


int main() {
    unsigned int x, scanned, digits;   
    int i, buffer[32];

    scanned = scanf("%u", &x);
    if (scanned != 1) {
        printf("Program requires 1 number!");
        abort();
    }
    assert(scanned == 1);
    assert(x > 0);

    digits = to_factorial(x, buffer);

    for (i = digits - 1; i >= 0; --i) {
        if (i > 0) {
            printf("%d.", buffer[i]);
        } else {
            printf("%d\n", buffer[i]);
        }
    }

    return 0;
}
