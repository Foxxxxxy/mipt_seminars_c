#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


unsigned long long fib(unsigned n, unsigned long long arr[]) {
    if (arr[n] != -1ull) {
        return arr[n];
    }

    if (n == 0) {
        arr[n] = 0ull;
    } else if (n <= 2) {
        arr[n] = 1ull;
    } else {
        arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
    }
    
    return arr[n];
}

// Calculates Fibonacci number in the range from 1 to 94 (starting from 95 numbers do not fit in unsigned long long)
int main() {
    unsigned n;
    unsigned long long result;
    int scanned, i;

    scanned = scanf("%u", &n);
    if (scanned != 1) {
        printf("Programn requires 1 number!\n");
        abort();
    }
    if (n < 1 || n > 94) {
        printf("Program calculates Fibonacci numbers only in the range from 1 to 94!\n");
        abort();
   }
    assert(scanned == 1);
    assert(n >= 1);
    assert(n <= 94);

    unsigned long long arr[94];
    for (i = 0; i < 94; ++i) {
        arr[i] = -1ull;
    }

    fib(n - 1, arr);

    printf("%llu\n", arr[n - 1]);

    return 0;
}
