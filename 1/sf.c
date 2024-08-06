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


unsigned to_fib(int x, unsigned result[], unsigned long long fib_arr[]) {
    int fst_idx = -1, idx = 83;

    while (x > 0) {
        while (idx > 0 && fib_arr[idx] > x) {
            idx--;
        }

        if (fst_idx == -1) {
            fst_idx = idx;
        }

        x -= fib_arr[idx];
        result[idx] = 1;
        idx--; 
    }
    
    return fst_idx;
}


int main() {
    int scanned, i, x = 0;
    unsigned fst_fib, result[84] = {0};
    unsigned long long fib_arr[84];

    for (i = 0; i < 84; ++i) {
        fib_arr[i] = -1ull;
    }

    scanned = scanf("%d", &x);
    if (scanned != 1) {
        printf("Prjgram requires at least 1 number!");
        abort();
    }
    assert(scanned == 1);

    fib(83, fib_arr); 

    fst_fib = to_fib(x, result, fib_arr);
    for (i = fst_fib; i >= 2; --i) {
        if (i == 2) {
            printf("%u\n", result[i]);
        } else {    
            printf("%u", result[i]); 
        }
    }

    return 0;
}
