#include<stdio.h>
#include<stdlib.h>

unsigned long long iabs(unsigned long long x) {
    return (x >= 0) ? x : -x;
}

unsigned long long eu_mod(unsigned long long x, unsigned long long y) {
    unsigned long long r;
    r = x % y;
    if (r < 0) {
        r += iabs(y);
    }
    return r;
}

unsigned long long bin_gcd(unsigned long long x, unsigned long long y) { 
    unsigned long long q;
    q = eu_mod(x, y);
    while (q > 0) {
        x = y;
        y = q;
        q = eu_mod(x, y);
    }
    return y;
}

unsigned long long lcm(int n) {
    unsigned long long lcm = 1;
    for (int i = 2; i <= n; ++i) {
        lcm = i * lcm / bin_gcd(i, lcm);
    }
    return lcm;
}

int main() {
    int n;

    scanf("%d", &n);

    unsigned long long res = lcm(n);

    printf("%llu\n", res);
}

