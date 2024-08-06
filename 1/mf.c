#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


void matrix_mul(int matrix1[], int matrix2[], int m) {
    int temp[4];

    temp[0] = (matrix1[0]*matrix2[0] + matrix1[1]*matrix2[2]) % m;
    temp[1] = (matrix1[0]*matrix2[1] + matrix1[1]*matrix2[3]) % m;
    temp[2] = (matrix1[2]*matrix2[0] + matrix1[3]*matrix2[2]) % m;
    temp[3] = (matrix1[2]*matrix2[1] + matrix1[3]*matrix2[3]) % m;

    matrix1[0] = temp[0];
    matrix1[1] = temp[1];
    matrix1[2] = temp[2];
    matrix1[3] = temp[3];
} 


void matrix_power(int matrix[], int n, int m) {
    int matrix_copy[] = {matrix[0], matrix[1], matrix[2], matrix[3]};
    int result[] = {1, 0, 0, 1};

    while (n > 0) {
        if (n % 2 == 1) {
            matrix_mul(result, matrix_copy, m);
        }
        matrix_mul(matrix_copy, matrix_copy, m);
        n /= 2;
    }

    matrix[0] = result[0];
    matrix[1] = result[1];
    matrix[2] = result[2];
    matrix[3] = result[3];
}


int main() {
    int n, m, matrix[4];
    int scanned;

    scanned = scanf("%d%d%d%d%d%d", &matrix[0], &matrix[1], &matrix[2], &matrix[3], &n, &m);
    if (scanned != 6) {
        printf("Program requires 6 numbers!");
        abort();
    }
    assert(scanned == 6);

    matrix_power(matrix, n, m);
    printf("%d %d %d %d\n", matrix[0], matrix[1], matrix[2], matrix[3]);

    return 0;
}
