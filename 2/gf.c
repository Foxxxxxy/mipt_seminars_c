#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct seq {
    int a, b, length;
};

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

int sieve_bound(int num) {
    if (num < 20) {
        return 100;
    }
    double dnum = num;
    double dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres);
}

char is_prime(struct sieve_t *sv, int n) {
    assert(n < sv->n);

    return sv->s[n] == 0 ? 1 : 0;
}

int seq_len(int a, int b, struct sieve_t *sieve) {
    int i, val, k = 0;

    for (i = 0; ; ++i) {
        val = i*i + a*i + b;
        if (!is_prime(sieve, val) || val < 2) {
            break;
        }
        ++k;
    }

    return k;
}

struct seq gen_seq(int n, struct sieve_t *sieve) {
    int i, j, cur_seq_len, max_seq_len = 0, opt_a, opt_b;
    for (i = -n + 1; i < n; ++i) {
       for (j = -n + 1; j < n; ++j) {
           cur_seq_len = seq_len(i, j, sieve);
           if (cur_seq_len > max_seq_len) {
               max_seq_len = cur_seq_len;
               opt_a = i;
               opt_b = j;
           } 
       }
    }

    struct seq res = { opt_a, opt_b, max_seq_len };
    return res;
} 

int main() {
    int n, size;
    char *s;

    scanf("%d", &n);

    size = sieve_bound(n*n + n);

    s = calloc(size + 1, sizeof(char));

    struct sieve_t sieve = { size, s };
    fill_sieve(&sieve);

    struct seq ans = gen_seq(n, &sieve);

    printf("%d %d %d\n", ans.a, ans.b, ans.length);
    
    return 0;
}
