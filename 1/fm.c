#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


unsigned fib_mod(unsigned x, unsigned m) {
    unsigned tmp, f = 0 % m, s = 1 % m;
    int i;

    if (x == 0) {
        return f;
    } else if (x == 1) {
        return s;
    }

    for (i = 2; i <= x; ++i) {
        tmp = s;
        s = (f + s) % m;
        f = tmp;
    }

    return s;
} 


int main() {
    unsigned x, m, res;
    int scanned;

    scanned = scanf("%u%u", &x, &m);
    if (scanned != 2) {
        printf("Program requires 2 numbers!\n");
        abort();
    }
    assert(scanned == 2);

    res = fib_mod(x, m);
    printf("%u\n", res);

    return 0;
}
