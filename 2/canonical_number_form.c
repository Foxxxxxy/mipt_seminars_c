#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

struct sieve_t {
    int size;
    char *s;
};

void fill_sieve(struct sieve_t *sv) {
    int start = 2;

    while (start * start <= sv->size) {
        if (!sv->s[start]) {
            for (int i = start * start; i <= sv->size; i += start) {
                sv->s[i] = 1;
            }
        }

        ++start;
    }
}

bool is_prime(int n, struct sieve_t *sv) {
    return sv->s[n] == 0 ? 1 : 0;
}

int primes_count_before_n(int n, struct sieve_t *sv) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (is_prime(i, sv)) {
            ++count;
        }
    }
    return count;
}

struct factor {
    int base, power;
};

struct canonical_form {
    int factors_count;
    struct factor *factors;
};

struct canonical_form get_canonical_form(int n, int max_factors, struct sieve_t *sv) {
    int fc = 0;
    struct factor *factors = calloc(max_factors, sizeof(struct factor));

    for (int i = 2; i <= sv->size && n > 1; ++i) {
        // if i is a prime factor of n
        if (is_prime(i, sv) && n % i == 0) {
            int k = 0;
            while (n % i == 0) {
                ++k;
                n /= i;
            }
            struct factor f = { i, k };
            factors[fc++] = f;
        }
    }

    struct canonical_form cf = { fc, factors };
    return cf;
}

void print_canonical_form(struct canonical_form *cf) {
    for (int i = 0; i < cf->factors_count; ++i) {
        struct factor f = cf->factors[i];

        if (i == cf->factors_count - 1) {
            printf("%d^%d\n", f.base, f.power);
        } else {
            printf("%d^%d * ", f.base, f.power);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int size = get_sieve_size(n);
    char *s = calloc(size + 1, sizeof(char));
    if (!s) {
        printf("Failed to allocate memory for sieve!");
        exit(EXIT_FAILURE);
    }
    struct sieve_t sieve = { size, s };

    fill_sieve(&sieve);

    // number of prime factors of n is always less or equal to number of primes before n
    int max_factors = primes_count_before_n(n, &sieve);

    struct canonical_form cf = get_canonical_form(n, max_factors, &sieve);

    print_canonical_form(&cf);

    return 0;
}
