#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define byte char

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

struct num_as_array {
    byte *arr;
    int num, size;
};

void make_array_from_num(struct num_as_array *a) {
    int d, num_copy = a->num, k = 0;
    
    while (num_copy > 0) {
        d = num_copy % 10;
        a->arr[k++] = d;
        num_copy /= 10;
    }

    a->size = k;
}

int shifted_num(struct num_as_array *a, byte shift) {
    int res = 0, p = 1;

    for (int i = 0; i < a->size; ++i) {
        int pos = (shift + i) % a->size;
        res += (a->arr[pos] * p);
        p *= 10;
    }

    return res;
}

bool is_cycle_prime(int x, struct sieve_t *sieve) {
    byte *arr = calloc(7, sizeof(byte));
    struct num_as_array a = {arr, x, 0};

    make_array_from_num(&a);

    for (int i = 0; i < a.size; ++i) {
        int sn = shifted_num(&a, i);
        if (!is_prime(sn, sieve)) {
            return false;
        }
    }

    return true;
}

int find_nearest_cycle_prime(int x, struct sieve_t *sieve) {
    if (is_cycle_prime(x, sieve)) {
        return x;
    }

    for (int i = 1; ; ++i) {
        if (is_cycle_prime(x - i, sieve)) {
            return x - i;
        }
        if (is_cycle_prime(x + i, sieve)) {
            return x + i;
        }
    }

    return -1;
}


int main() {
    int x;

    scanf("%d", &x);

    char *s = calloc(10000000, sizeof(char));
    if (!s) {
        printf("Failed to allocate memory for sieve!");
        exit(EXIT_FAILURE);
    }
    struct sieve_t sieve = { 10000000, s };

    fill_sieve(&sieve);

    int res = find_nearest_cycle_prime(x, &sieve);

    printf("%d\n", res);
}
