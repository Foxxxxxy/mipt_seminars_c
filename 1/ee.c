#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long gcde(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    long long x1, y1;     
    long long gcd = gcde(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}


int main() {
    long long a, b, d, x, y;
    long long scanned;

    scanned = scanf("%lld %lld", &a, &b);
    if (scanned < 2) {
        printf("Less than 2 numbers in input!");
        abort();
    }
    assert(scanned == 2); 
    
    d = gcde(a, b, &x, &y);
    
    if (d < 0) {
        d *= -1;
        x *= -1;
        y *= -1;
    }

    printf("%lld %lld %lld\n", x, y, d);

    return 0;
}
