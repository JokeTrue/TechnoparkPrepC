#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include "Student.hpp"

using namespace std;

Student::Student(char *name, char *patronymic, char *surname, int birthdate, char *adress,
                 char *telephone, char *faculty, int course) :
        name(nullptr),
        patronymic(nullptr),
        surname(nullptr),
        adress(nullptr),
        telephone(nullptr),
        faculty(nullptr) {
    if (name) {
        size_t len = strlen(name) + 1;
        this->name = new char[len];
        memcpy(this->name, name, len);
    }
    if (patronymic) {
        size_t len = strlen(patronymic) + 1;
        this->patronymic = new char[len];
        memcpy(this->patronymic, patronymic, len);
    }
    if (surname) {
        size_t len = strlen(surname) + 1;
        this->surname = new char[len];
        memcpy(this->surname, surname, len);
    }
    if (birthdate) {
        this->birthdate = birthdate;
    }
    if (adress) {
        size_t len = strlen(adress) + 1;
        this->adress = new char[len];
        memcpy(this->adress, adress, len);
    }
    if (telephone) {
        size_t len = strlen(telephone) + 1;
        this->telephone = new char[len];
        memcpy(this->telephone, telephone, len);
    }
    if (faculty) {
        size_t len = strlen(faculty) + 1;
        this->faculty = new char[len];
        memcpy(this->faculty, faculty, len);
    }
    if (course) {
        this->course = course;
    }
}


Student::~Student() {
    delete[] name;
    name = nullptr;

    delete[] patronymic;
    patronymic = nullptr;

    delete[] surname;
    surname = nullptr;

    delete[] adress;
    adress = nullptr;

    delete[] telephone;
    telephone = nullptr;

    delete[] faculty;
    faculty = nullptr;
}


Student::Student(const Student &rhs) {
    if (rhs.name) {
        size_t length = strlen(rhs.name) + 1;
        this->name = new char[length];
        memcpy(this->name, rhs.name, length);
    }
    if (rhs.patronymic) {
        size_t length = strlen(rhs.patronymic) + 1;
        this->patronymic = new char[length];
        memcpy(this->patronymic, rhs.patronymic, length);
    }
    if (rhs.surname) {
        size_t length = strlen(rhs.surname) + 1;
        this->surname = new char[length];
        memcpy(this->surname, rhs.surname, length);
    }
    if (rhs.birthdate) {
        this->birthdate = rhs.birthdate;
    }
    if (rhs.adress) {
        size_t length = strlen(rhs.adress) + 1;
        this->adress = new char[length];
        memcpy(this->adress, rhs.adress, length);
    }
    if (rhs.telephone) {
        size_t length = strlen(rhs.telephone) + 1;
        this->telephone = new char[length];
        memcpy(this->telephone, rhs.telephone, length);
    }
    if (rhs.faculty) {
        size_t length = strlen(rhs.faculty) + 1;
        this->faculty = new char[length];
        memcpy(this->faculty, rhs.faculty, length);
    }
    if (rhs.course) {
        this->course = rhs.course;
    }
}


Student &Student::operator=(const Student &rhs) {
    if (this == &rhs) {
        return *this;
    }
    if (rhs.name) {
        size_t len = strlen(rhs.name) + 1;
        name = new char[len];
        memcpy(name, rhs.name, len);
    }
    if (rhs.patronymic) {
        size_t len = strlen(rhs.patronymic) + 1;
        patronymic = new char[len];
        memcpy(patronymic, rhs.patronymic, len);
    }
    if (rhs.surname) {
        size_t len = strlen(rhs.surname) + 1;
        surname = new char[len];
        memcpy(surname, rhs.surname, len);
    }
    if (rhs.birthdate) {
        birthdate = rhs.birthdate;
    }
    if (rhs.adress) {
        size_t len = strlen(rhs.adress) + 1;
        adress = new char[len];
        memcpy(adress, rhs.adress, len);
    }
    if (rhs.telephone) {
        size_t len = strlen(rhs.telephone) + 1;
        telephone = new char[len];
        memcpy(telephone, rhs.telephone, len);
    }
    if (rhs.faculty) {
        size_t len = strlen(rhs.faculty) + 1;
        faculty = new char[len];
        memcpy(faculty, rhs.faculty, len);
    }
    if (rhs.course) {
        course = rhs.course;
    }
    return *this;
}

char *Student::get_faculty() const {
    return this->faculty;
}

char *Student::get_name() const {
    return this->name;
}

char *Student::get_patronymic() const {
    return this->patronymic;
}

char *Student::get_surname() const {
    return this->surname;
}

int Student::get_birthdate() const {
    return this->birthdate;
}

char *Student::get_telephone() const {
    return this->telephone;
}

int Student::get_course() const {
    return this->course;
}

char *Student::get_adress() {
    return this->adress;
}

void Student::show() {
    const char separator = ' ';
    const int width = 25;

    cout << left << setw(width) << setfill(separator) << this->get_name();
    cout << left << setw(width) << setfill(separator) << this->get_patronymic();
    cout << left << setw(width) << setfill(separator) << this->get_surname();
    cout << left << setw(width) << setfill(separator) << this->get_birthdate();
    cout << left << setw(width) << setfill(separator) << this->get_faculty();
    cout << left << setw(width) << setfill(separator) << this->get_course();
    cout << left << setw(width) << setfill(separator) << this->get_telephone();
    cout << left << setw(width) << setfill(separator) << this->get_adress();

}



