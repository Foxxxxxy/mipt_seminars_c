#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long fast_mul(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long res = 0;
    
    while (b > 0) {
        if (b % 2 == 1) {
           res = (res + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }

    return res;
}

unsigned long long fast_pow(unsigned long long num, unsigned long long power, unsigned long long mod) {
    unsigned long long res = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            res = fast_mul(res, num, mod);
        }
        num = fast_mul(num, num, mod);
        power /= 2;
    }

    return res;
}

bool ferma_test(unsigned long long n) {
    srand(time(NULL));

    for (int i = 0; i < 100; ++i) {
        unsigned long long vitness = rand() % 100;
        if (vitness % n == 0) {
            continue;
        }
        
        unsigned long long mod = fast_pow(vitness, n - 1, n);
        
        if (mod != 1) {
            return false;
        }
    }

    return true;
}

int main() {
    unsigned long long n;

    scanf("%llu", &n);

    bool is_prime = ferma_test(n);

    printf("%d\n", is_prime);
}
