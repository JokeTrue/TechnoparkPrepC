#include <cstdio>
#include <iostream>
#include <cstring>
#include "Student.hpp"
#include "extra.hpp"

Student *fill_students() {
    FILE *fp = fopen("/home/joketrue/Projects/TechnoparkPrepC/C++/DZ#4/students.txt", "r");
    if (fp == NULL) {
        cout << "Unable to open %s: %s.\n" << endl;
        return nullptr;
    }
    Student *array = new(nothrow) Student[ARRAY_SIZE];
    if (array == nullptr) {
        fclose(fp);
        return nullptr;
    }
    char *name = new char[255];
    char *patronymic = new char[255];
    char *surname = new char[255];
    int birthdate = 0;
    char *telephone = new char[255];
    char *adress = new char[255];
    char *faculty = new char[255];
    int course;
    int i = 0;
    while (fscanf(fp, "%s %s %s %d %s %s %s %d", name, patronymic, surname, &birthdate, telephone, adress,
                  faculty, &course) == 8) {
        if (i > ARRAY_SIZE) {
            break;
        }
        Student *st = new Student(
                name,
                patronymic,
                surname,
                birthdate,
                adress,
                telephone,
                faculty,
                course
        );
        array[i] = *st;
        i++;
    }
    fclose(fp);
    return array;
}

void filter_by_faculty(Student *array, char *faculty) {
    cout << "Filtered by Faculty " << faculty << ":" << endl;
    for (int i = 0; i < length(array); i++) {
        Student that = array[i];
        if (strcmp(array[i].get_faculty(), faculty) == 0) {
            that.show();
            cout << endl;
        }
    }
}

int cmp(const void *ptr1, const void *ptr2) {
    Student *st1 = (Student *) ptr1;
    Student *st2 = (Student *) ptr2;
    int result = (strcmp(st1->get_faculty(), st2->get_faculty()));
    if (st1->get_course() < st2->get_course()) {
        result += 1;
    } else if (st1->get_course() > st2->get_course()) {
        result += -1;
    }
    return result;
}

void filter_by_year(Student *array, int year) {
    cout << "Filtered by Year " << year << ":" << endl;
    for (int i = 0; i < length(array); i++) {
        Student that = array[i];
        if (that.get_birthdate() > year) {
            that.show();
            cout << endl;
        }
    }
}

void show_sorted(Student *array) {
    qsort(array, length(array), sizeof(Student), cmp);
    for (int i = 0; i < length(array); i++) {
        Student that = array[i];
        that.show();
        cout << endl;
        Student next = array[i + 1];
        if (next.get_name() != nullptr) {

            if (strcmp(that.get_faculty(), next.get_faculty()) != 0 || that.get_course() != next.get_course()) {
                cout
                        << "------------------------------------------------------------------------------------------------------------------\n";
            }
        }
    }
}

size_t length(Student* array) {
    size_t size = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i].get_course() != 0) {
            size++;
        }
    }
    return size;
}