#include<stdio.h>
#include<stdlib.h>

void fill_sieve(int n, char *sieve, int start, int step) {
    int i;

    for (i = start; i <= n; i += step) {
        sieve[i] = 1;
    }
}

int count_primes(int n, char *sieve) {
    int i, ans = 0, start = 2;
    
    while (start * start <= n) {
        if (!sieve[start]) {
            fill_sieve(n, sieve, start * start, start);
        }

        ++start;
    } 

    for (i = 2; i <= n; ++i) {
        if (sieve[i] == 0) {
            ++ans;
        }
    }

    return ans;
}

int main() {
    int n, ans;
    char *sieve;

    scanf("%d", &n);

    sieve = calloc(n + 1, sizeof(int));

    ans = count_primes(n, sieve);

    printf("%d\n", ans);

    return 0;
}
