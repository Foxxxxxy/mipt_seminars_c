#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

char is_prime(int x) {
    int i;
    for (i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        return 0;
      }
    }
    return 1;
}

int nth_prime(int n) {
    int i, k = 1, res = 2;

    if (n == 1) {
        return res;
    }

    for (i = 3; ; ++i) {
        if (is_prime(i)) {
            ++k;
            res = i;
        }
        
        if (k == n) {
            break;
        }
    }

    return res;
}

int main() {
    int n, res, scanned;

    scanned = scanf("%d", &n);
    if (scanned != 1) {
        printf("Program requires 1 number");
        abort();
    }
    assert(scanned == 1);

    res = nth_prime(n);
    
    printf("%d\n", res);

    return 0;
}
