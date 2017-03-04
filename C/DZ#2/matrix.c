#include <stdio.h>
#include <assert.h>

void print_matrix(const double **matrix, const int rows, const int cols) {
    printf("Matrix from file:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

double get_elem(const double **matrix, const int row, const int col) {
    return matrix[row][col];
}

void set_elem(double **matrix, int row, int col, double elem) {
    matrix[row][col] = elem;
}

void transpose(double **matrix, int rows, int cols) {
    printf("Transposed Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2lf\t", matrix[j][i]);
        }
        printf("\n");
    }
}
