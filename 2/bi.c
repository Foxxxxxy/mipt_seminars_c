#include<stdio.h>
#include<stdlib.h>

#define byte int

struct array {
    int size;
    byte *arr;
};

void invert_bit(struct array *a, int n) {
    int el = n / 8;
    int bit = n % 8;

    a->arr[el] ^= (1 << bit);
}

int main() {
    int size, n;

    scanf("%d", &size);

    byte *arr = calloc(size, sizeof(byte));
    
    struct array a = {size, arr}; 

    for (int i = 0; i < a.size; ++i) {
        byte c;
        scanf("%d", &c);
        a.arr[i] = c;
    }

    scanf("%d", &n);

    invert_bit(&a, n);

    for (int i = 0; i < a.size; ++i) {
        printf("%d ", a.arr[i]);
    }
}
