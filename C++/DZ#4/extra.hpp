#ifndef DZ_4_EXTRA_HPP
#define DZ_4_EXTRA_HPP

#define ARRAY_SIZE 1024
#define MAX_LINE 255

Student *fill_students();

void filter_by_faculty(Student *array, char *faculty);

void filter_by_year(Student *array, int year);

void show_sorted(Student *array);

size_t length(Student *array);

#endif //DZ_4_EXTRA_HPP
