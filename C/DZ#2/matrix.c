#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>
#include "matrix.h"

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix) * rows * cols);
    if (!matrix) {
        printf("Can't allocate %zu bytes: %s.\n", sizeof(Matrix) * rows * cols, strerror(errno));
        free_matrix(matrix);
        return 0;
    }
    int n = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Matrix m = {.row = i, .col = j, .value = 0, .count = (size_t) (rows * cols)};
            matrix[n] = m;
            n++;
        }
    }
    return matrix;
}

Matrix *create_matrix_from_file(FILE *file) {
    int rows, cols;
    assert(fscanf(file, "%d %d", &rows, &cols) == 2);

    Matrix *matrix = create_matrix(rows, cols);
    if (!matrix) {
        return 0;
    }

    double value;
    int num, row, col;
    assert(fscanf(file, "%d", &num) == 1);
    for (int i = 0; i < num; i++) {
        assert(fscanf(file, "%d %d %lf", &row, &col, &value) == 3);
        set_elem(matrix, row, col, value);
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    free(matrix);
}

double get_elem(Matrix *matrix, int row, int col) {
    const int size = (const int) matrix[0].count;
    for (int i = 0; i < size; i++) {
        if (matrix[i].row == row && matrix[i].col == col) {
            return matrix[i].value;
        }
    }
    return 0;
}

void set_elem(Matrix *matrix, int row, int col, double val) {
    const int size = (const int) matrix[0].count;
    for (int i = 0; i < size; i++) {
        if (matrix[i].row == row && matrix[i].col == col) {
            matrix[i].value = val;
        }
    }
}

int get_rows(Matrix *matrix) {
    int size = (int) matrix[0].count;
    return matrix[size - 1].row + 1;
}

int get_cols(Matrix *matrix) {
    int size = (int) matrix[0].count;
    return matrix[size - 1].col + 1;
}

void print_matrix(Matrix *matrix) {
    printf("Matrix from File: \n");
    int rows = get_rows(matrix);
    int cols = get_cols(matrix);
    int iter1 = 0;
    int iter2 = 0;
    if (rows == cols) {
        iter1 = rows;
        iter2 = cols;
    }
    if (rows < cols) {
        iter1 = rows;
        iter2 = cols;
    }
    if (rows > cols) {
        iter1 = cols;
        iter2 = rows;
    }
    int n = 0;
    for (int i = 0; i < iter1; ++i) {
        for (int j = 0; j < iter2; ++j) {
            printf("%.2lf\t", matrix[n].value);
            n++;
        }
        printf("\n");
    }
}

void transpose(Matrix *matrix) {
    int rows = get_rows(matrix);
    int cols = get_cols(matrix);
    int iter1 = 0;
    int iter2 = 0;
    if (rows == cols) {
        iter1 = rows;
        iter2 = cols;
    }
    if (rows > cols) {
        iter1 = rows;
        iter2 = cols;
    }
    if (rows < cols) {
        iter1 = cols;
        iter2 = rows;
    }

    printf("Transposed Matrix:\n");
    for (int i = 0; i < iter1; i++) {
        for (int j = 0; j < iter2; j++) {
            printf("%.2lf\t", get_elem(matrix, j, i));
        }
        printf("\n");
    }
}

