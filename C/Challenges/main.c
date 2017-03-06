#include <stdio.h>
#include <stdlib.h>
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
        fclose(fp);
        return EXIT_FAILURE;
    }

    Matrix *matrix = create_matrix_from_file(fp);
    print_matrix(matrix);
    transpose(matrix);
    free_matrix(matrix);
    fclose(fp);
    return EXIT_SUCCESS;
}