#include <fstream>
#include <iostream>
#include "Student.hpp"
#include "extra.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Student *array = fill_students();
    if (array == nullptr) {
        cout << "Failed to fill array of Students" << endl;
        return EXIT_FAILURE;
    }
//    filter_by_faculty(array, "ИБМ");
//    filter_by_year(array, 1994);
    show_sorted(array);

    delete[] array;
    return EXIT_SUCCESS;
}

