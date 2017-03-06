#ifndef MATRIX_H
#define MATRIX_H

double get_elem(const double **matrix, const int row, const int col);

void set_elem(double **matrix, int row, int col, double elem);

void transpose(const double **matrix, const int rows, const int cols);


#endif