#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int to_binary(unsigned int x, unsigned int y, int buffer[]) {
    int mod, digits = 0;
   
    assert(x > 0);
    assert(y > 1);
    assert(y < 11);
    
    while (x > 0) {
        int mod = x % y;
        x /= y;
        
        buffer[digits++] = mod;
    }

    return digits;
}

int main() {
    unsigned int x, y, scanned, digits_num;
    int i, buffer[32];

    scanned = scanf("%d%d", &x, &y);
    if (scanned != 2) {
        printf("Program requires 2 input numbers!");
        abort();
    }
    assert(scanned == 2);

    digits_num = to_binary(x, y, buffer);

    for (i = digits_num - 1; i >= 0; --i) {
        if (i > 0) {
            printf("%d", buffer[i]);
        } else {
            printf("%d\n", buffer[i]);
        }
    }
}

