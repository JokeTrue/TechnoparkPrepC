#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_STRING_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Got %d arguments, expected 1.\n", argc - 1);
        return EXIT_FAILURE;
    }

    char *path = argv[1];
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", path);
        return EXIT_FAILURE;
    }

    int index = 0;
    char ch[MAX_LINES], array[MAX_LINES][MAX_STRING_LENGTH];
    while (fscanf(fp, "%s", ch) == 1) {
        if (strlen(ch) >= MAX_STRING_LENGTH) {
            printf("String is too long...\n");
            return EXIT_FAILURE;
        }
        strcpy(array[index], ch);
        index++;
    }

    // Сортировка
    char tmp[MAX_LINES];
    const int size = index;
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size - 1; j++) {
            if (strcmp(array[j - 1], array[j]) > 0) {
                strcpy(tmp, array[j - 1]);
                strcpy(array[j - 1], array[j]);
                strcpy(array[j], tmp);
            }
        }
    }

    // Выбор неповторяющихся строк
    for (int f = 0; f < size; f++) {
        int num_occ = 0;
        for (int g = 0; g < size; g++) {
            if ((strcmp(array[f], array[g])) == 0) {
                num_occ++;
            }
        }
        if (num_occ == 1) {
            printf("%s\n", array[f]);
        }
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
