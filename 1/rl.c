#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long iabs(long long x) {
    return (x >= 0) ? x : -x;
}

long long eu_mod(long long x, long long y) {
    long long r;
    assert(y != 0);
    r = x % y;
    if (r < 0) {
        r += iabs(y);
    }
    return r;
}

long long gcd(long long x, long long y) { 
    long long q;
    q = eu_mod(x, y);
    while (q > 0) {
        x = y;
        y = q;
        q = eu_mod(x, y);
    }
    return y;
}

int main() {
    long long x = 0, y = 0, g;
    long long scanned;

    scanned = scanf("%lld %lld", &x, &y);
    if (scanned < 2) {
        printf("Less than 2 numbers in input!");
        abort();
    }
    assert(scanned == 2); 

    g = gcd(x, y);
    printf("%lld\n", g);
    return 0;
}
