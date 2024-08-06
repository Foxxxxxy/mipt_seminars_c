#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int gcde(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;     
    int gcd = gcde(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}


int main() {
    int a, b, c, gcd, x, y;
    int scanned;

    scanned = scanf("%d%d%d", &a, &b, &c);
    if (scanned != 3) {
        printf("Less than 3 numbers scanned!");
        abort();
    }
    assert(scanned == 3);

    gcd = gcde(a, b, &x, &y);

    if (gcd < 0) {
        gcd *= -1;
        x *= -1;
        y *= -1;
    }
    assert(gcd >= 0);
    assert(a*x + b*y == gcd);

    if (c % gcd != 0) {
        printf("NONE\n");
    } else {
        int q = c / gcd;
        int s1 = x * q;
        int s2 = y * q;
        printf("%d %d\n", s1, s2);
    }
    
    return 0;
}
