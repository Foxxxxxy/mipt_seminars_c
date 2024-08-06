#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int mod_pow(unsigned int a, unsigned int b, unsigned int n) {
    unsigned int prod, mod;
    
    mod = a % n;
    prod = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            prod = (prod * mod) % n;
        }
        mod = (mod * mod) % n;
        b = b / 2;
    }

    return prod;
}

unsigned int super_power(unsigned int a, unsigned int b, unsigned int n) {
    unsigned int prod = a % n, mod = a % n;
    
    while (b > 0) {
        if (b % 2 == 1) {
            prod = mod_pow(prod, mod, n);
        }
        mod = mod_pow(mod, a, n);
        b /= 2;
    }

    return prod;
}


int main() {
    unsigned int a, b, n, ans;
    int scanned;

    scanned = scanf("%u%u%u", &a, &b, &n);
    if (scanned != 3) {
        printf("Program requires 3 numbers!");
        abort();
    }
    assert(scanned == 3);
    assert(n > 0);

    ans = super_power(a, b, n);
    printf("%u\n", ans);

    return 0;
}

