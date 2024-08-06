#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define MOD 6

struct sieve_t {
    int n;
    char *mod1;
    char *mod5;
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

bool is_prime(struct sieve_t *sv, unsigned n) {
    if (n == 2 || n == 3) {
        return true;
    }

    if (n % MOD != 1 && n % MOD != 5) {
        return false;
    }

    int pos = n / MOD;
    if (n % MOD == 1) {
        return ((sv->mod1[pos / CHAR_BIT] >> (pos % CHAR_BIT)) & 1) == 0;
    } else {
        return ((sv->mod5[pos / CHAR_BIT] >> (pos % CHAR_BIT)) & 1) == 0;
    }
}

void fill_sieve_for_num(struct sieve_t *sv, int num) {
    for (int m = num * num; m < sv->n; m += num) {
        int m_pos = m / MOD;
        int byte = m_pos / CHAR_BIT;
        int offset = m_pos % CHAR_BIT;

        if (m % MOD == 1) {
            sv->mod1[byte] |= (1 << offset);
        }
        if (m % MOD == 5) {
            sv->mod5[byte] |= (1 << offset);
        }
    }
}

void fill_sieve(struct sieve_t *sv) {
    sv->mod1[0] |= 1;

    // each iteration n is increased by 6
    for (int n = 1; n * n < sv->n; n += 2) {
        int pos = n / MOD;

        if (((sv->mod1[pos / CHAR_BIT] >> (pos % CHAR_BIT)) & 1) == 0) {
            fill_sieve_for_num(sv, n);
        }

        n += 4;

        if (((sv->mod5[pos / CHAR_BIT] >> (pos % CHAR_BIT)) & 1) == 0) {
            fill_sieve_for_num(sv, n);
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int sieve_size = sieve_bound(n);
    char *sieve_mod1_part = calloc((sieve_size / MOD) + 1, sizeof(char));
    char *sieve_mod5_part = calloc((sieve_size / MOD) + 1, sizeof(char));

    struct sieve_t *sv = malloc(sizeof(struct sieve_t));

    sv->n = sieve_size;
    sv->mod1 = sieve_mod1_part;
    sv->mod5 = sieve_mod5_part;

    fill_sieve(sv);

    int i = 1, c = 0;
    while (c < n) {
        if (is_prime(sv, i)) {
            ++c;
        }
        if (c == n) {
            break;
        }
        ++i;
    }

    printf("%d\n", i);

}

