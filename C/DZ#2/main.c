#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <errno.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Got %d arguments, expected 1.\n", argc - 1);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Unable to open %s: %s.\n", path, strerror(errno));
        return EXIT_FAILURE;
    }

    int rows, cols;
    assert(fscanf(fp, "%d %d", &rows, &cols) == 2);

    double **matrix = malloc(sizeof(double *) * rows);
    if (!matrix) {
        printf("Can't allocate %zu bytes: %s.\n", sizeof(double *) * rows, strerror(errno));
        free(matrix);
        fclose(fp);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < rows; ++i) {
        matrix[i] = calloc(sizeof(double), (size_t) cols);
        assert(matrix[i]);
    }

    int row, col, num;
    double value;
    assert(fscanf(fp, "%d", &num) == 1);
    for (int i = 0; i < num; ++i) {
        assert(fscanf(fp, "%d %d %lf", &row, &col, &value) == 3);
        set_elem(matrix, row, col, value);
    }

    print_matrix((const double **) matrix, cols, rows);
    transpose((const double **) matrix, cols, rows);

    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    fclose(fp);
    return EXIT_SUCCESS;
}

