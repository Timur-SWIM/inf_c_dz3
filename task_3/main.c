#include <stdio.h>
#include <stdlib.h>
#define DATA_ERROR (-1)
#define MATH_ERROR (-2)

int chek(int argc, char *argv[]){
    if (argc != 5){
        return DATA_ERROR;
    }
    if (atoi(argv[1]) != atoi(argv[2])){
        return MATH_ERROR;
    }
    return 0;
}

void get_data(int m, int n, int matrix[m][n]){
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            printf("matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print(int m, int n, int matrix[m][n]){
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplication(int m, int n, int sum_matrix[m][n], int matrix1[m][n], int matrix2[m][n]){
    int sum;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            sum = 0;
            for (int k = 0; k < n; ++k){
                sum += matrix1[i][k] * matrix2[k][i];
            }
            sum_matrix[i][j] = sum;
        }
    }
}
int main(int argc, char *argv[]) {
    if (chek(argc, argv) == DATA_ERROR){
        printf("data error\n");
        return DATA_ERROR;
    }
    if (chek(argc, argv) == MATH_ERROR){
        printf("matrices cannot be multiplied");
        return MATH_ERROR;
    }
    int m , n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);

    int matrix1[m][n];
    printf("input matrix1[%d][%d]\n", m, n);
    get_data(m, n, matrix1);
    printf("\n");
    printf("matrix1[%d][%d]\n", m, n);
    print(m, n, matrix1);
    printf("\n");

    m = atoi(argv[3]);
    n = atoi(argv[4]);

    int matrix2[m][n];
    printf("input matrix2[%d][%d]\n", m, n);
    get_data(m, n, matrix2);
    printf("matrix2[%d][%d]\n", m, n);
    print(m, n, matrix2);

    m = atoi(argv[2]);
    n = atoi(argv[3]);

    int sum_matrix[m][n];
    multiplication(m, n, sum_matrix, matrix1, matrix2);
    printf("sum_matrix[%d][%d]\n", m, n);
    print(m, n, sum_matrix);

    return 0;
}

