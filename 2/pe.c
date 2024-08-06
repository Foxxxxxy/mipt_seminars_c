#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
  int n;
  char *s;
};

void fill_sieve(struct sieve_t *sv);
bool is_prime(struct sieve_t *sv, unsigned n);

int sieve_bound(int num)
{
    double dnum, dres;
    if (num <= 20)
        return 100;
    dnum = num;
    dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres) + 1;
}

void fill_sieve(struct sieve_t *sv) {
    sv->s[0] |= 1;
    sv->s[0] |= (1 << 1);

    for (int n = 2; n * n <= sv->n; ++n) {
        if (((sv->s[n / CHAR_BIT] >> (n % CHAR_BIT)) & 1) == 0) {
            for (int m = n * n; m < sv->n; m += n) {
                sv->s[m / CHAR_BIT] |= (1 << m % CHAR_BIT); 
            }
        }
    }
}

bool is_prime(struct sieve_t *sv, unsigned n) {
    return !((sv->s[n / CHAR_BIT] >> (n % CHAR_BIT)) & 1);
}

int main() {
    int n;

    scanf("%d", &n);

    int sieve_size = sieve_bound(n);
    char *sieve = calloc((sieve_size / CHAR_BIT) + 1, sizeof(char));

    struct sieve_t *sv = malloc(sizeof(struct sieve_t));

    sv->n = sieve_size;
    sv->s = sieve;

    fill_sieve(sv);
    
    int i = 2, c = 0;
    for ( ; ; ++i) {
        if (is_prime(sv, i)) {
            ++c;
        }
        if (c == n) {
            break;
        }
    }

    printf("%d\n", i);
}
