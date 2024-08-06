#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

unsigned get_pisano_period(unsigned m) {
    unsigned tmp, k = 0, f = 0, s = 1;

    do {
        tmp = (f + s) % m;
        f = s;
        s = tmp;
        k++;
    } while (f != 0 || s != 1);

    return k;
}


unsigned fib_mod(unsigned long long x, unsigned m, unsigned pisano_period) {
    unsigned tmp, f = 0, s = 1;
    int i;

    x = x % pisano_period;

    if (x == 0) {
        return f;
    } else if (x == 1) {
        return s;
    } 
    
    for (i = 2; i <= x; ++i) {
        tmp = (f + s) % m;
        f = s;
        s = tmp;
    }

    return s;
} 


int main() {
    unsigned long long x;
    unsigned m, res, pisano_period;
    int scanned;

    scanned = scanf("%llu%u", &x, &m);
    if (scanned != 2) {
        printf("Program requires 2 numbers!\n");
        abort();
    }
    assert(scanned == 2);

    pisano_period = get_pisano_period(m);
    res = fib_mod(x, m, pisano_period);
    printf("%u %u\n", res, pisano_period);

    return 0;
}
