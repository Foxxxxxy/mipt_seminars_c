#include<assert.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

struct sieve_t {
  int n;
  char *s;
};

void fill_sieve(struct sieve_t *sv) {
    int i, n = sv->n, start = 2;
    char *s = sv->s;

    while (start * start <= n) {
        if (!s[start]) {
            for (i = start * start; i <= n; i += start) {
                s[i] = 1;
            }
        }

        ++start;
    } 
}

int nth_prime(struct sieve_t *sv, int N) {
    int i, k = 0;

    for (i = 2; i <= sv->n; ++i) {
        if (sv->s[i] == 0) {
            ++k;
        }
        if (k == N) {
            return i;
        }
    }
}

int sieve_bound(int num) {
    assert(num > 20);
    double dnum = num;
    double dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres);
}

int main() {
    int n, size, ans;
    char *s;

    scanf("%d", &n);

    if (n > 20) {
        size = sieve_bound(n);
    } else {
        size = 100;
    }

    s = calloc(size + 1, sizeof(char));

    struct sieve_t sieve = { size, s };

    fill_sieve(&sieve);

    ans = nth_prime(&sieve, n);

    printf("%d\n", ans);

    return 0;
}
