#include<stdio.h>
#include<stdlib.h>

void bits(int x) {
    if (x == 0) {
        printf("NO\n");
        return;
    }

    int first = -1, second = -1, k = 0;

    while (x > 0) {
        if (x & 1) {
            if (first == -1) {
                first = k;
            }
            second = k;
        }
        x >>= 1;
        ++k;
    }

    printf("%d %d\n", second, first);
}

int main() {
    int x;

    scanf("%d", &x);

    bits(x);
}

