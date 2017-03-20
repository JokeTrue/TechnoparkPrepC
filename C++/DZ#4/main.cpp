#include <fstream>
#include "Student.hpp"
#include "extra.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Got %d arguments, expected 1.\n", argc - 1);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Unable to open %s.\n", path);
        return EXIT_FAILURE;
    }

    Student *array = fill_students(fp);
//    filter_by_faculty(array, "IBM");
//    filter_by_year(array, 2000);
    show_sorted(array);
    fclose(fp);
    return EXIT_SUCCESS;
}

