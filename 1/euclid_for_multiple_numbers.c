#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned iabs(unsigned x) {
    return (x >= 0) ? x : -x;
}

unsigned eu_mod(unsigned x, unsigned y) {
    unsigned r;
    assert(y != 0);
    r = x % y;
    if (r < 0) {
        r += iabs(y);
    }
    return r;
}

unsigned bin_gcd(unsigned x, unsigned y) { 
    unsigned q;
    q = eu_mod(x, y);
    while (q > 0) {
        x = y;
        y = q;
        q = eu_mod(x, y);
    }
    return y;
}


unsigned multiple_gcd(unsigned n, unsigned numbers[]) {
    unsigned gcd, first = numbers[0], second = numbers[1];

    gcd = bin_gcd(first, second);

    for (int i = 0; i < n - 2; ++i) {
        first = gcd;
        second = numbers[i + 2];
        gcd = bin_gcd(first, second);
    }
    
    return gcd;
}


int main() {
    unsigned n, scanned, numbers[100];
    int i;

    scanned = scanf("%u", &n);
    if (scanned != 1) {
        printf("Amount of numbers required!\n");
        abort();
    }
    assert(scanned == 1);
    if (n < 2 || n > 100) {
        printf("Programm works only for 2 <= n <= 100");
        abort();
    }
    assert(n >= 2);
    assert(n <= 100);

    for (i = 0; i < n; ++i) {
        printf("Number %d: ", i + 1);
        scanf("%u", &numbers[i]);
    }

    unsigned res = multiple_gcd(n, numbers);
    printf("gcd: %u\n", res);
    return 0;
}
