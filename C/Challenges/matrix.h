#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

typedef struct Matrix {
    int row;
    int col;
    double value;
    size_t count;
} Matrix;


Matrix *create_matrix_from_file(FILE *file);

Matrix *create_matrix(int rows, int cols);

void free_matrix(Matrix *matrix);

double get_elem(Matrix *matrix, int row, int col);

void set_elem(Matrix *matrix, int row, int col, double val);

int get_rows(Matrix *matrix);

int get_cols(Matrix *matrix);

void print_matrix(Matrix *matrix);

void transpose(Matrix *matrix);


#endif //_MATRIX_H_
