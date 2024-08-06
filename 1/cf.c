#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long iabs(long long x) {
    return (x >= 0) ? x : -x;
}

long long eu_div(long long x, long long y) {
    long long q;
    assert(y != 0);
    q = x / y;
    if (q < 0) {
        q *= -1;
    }
    return q;
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

void cf(long long x, long long y) {
    long long q, r;
    assert(y != 0);
    q = eu_div(x, y);
    r = eu_mod(x, y);
    while (r != 0) {
        printf("%lld ", q);
        x = y;
        y = r;
        q = eu_div(x, y);
        r = eu_mod(x, y);
    }
    printf("%lld\n", q);
}

int main() {
    long long x = 0, y = 0;
    long long scanned;

    scanned = scanf("%lld %lld", &x, &y);
    if (scanned < 2) {
        printf("Less than 2 numbers in input!");
        abort();
    }
    assert(scanned == 2);

    cf(x, y);
    return 0;
}
