#include <cstring>
#include <iostream>
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
    cout << left << this->get_name() << ' ';
    cout << left << this->get_patronymic() << ' ';
    cout << left << this->get_surname() << ' ';
    cout << left << this->get_birthdate() << ' ';
    cout << left << this->get_faculty() << ' ';
    cout << left << this->get_course() << ' ';
    cout << left << this->get_telephone() << ' ';
    cout << left << this->get_adress() << ' ';
    cout << endl;

}

void Student::set_faculty(char *new_faculty) {
    if (strlen(new_faculty) + 1 <= strlen(this->faculty) + 1) {
        this->faculty = new_faculty;
    }

}

void Student::set_name(char *new_name) {
    if (strlen(new_name) + 1 <= strlen(this->name) + 1) {
        this->name = new_name;
    }
}

void Student::set_patronymic(char *new_patr) {
    if (strlen(new_patr) + 1 <= strlen(this->patronymic) + 1) {
        this->patronymic = new_patr;
    }
}

void Student::set_surname(char *new_surname) {
    if (strlen(new_surname) + 1 <= strlen(this->surname) + 1) {
        this->surname = new_surname;
    }

}

void Student::set_birthdate(int new_birthdate) {
    this->birthdate = new_birthdate;
}

void Student::set_adress(char *new_adress) {
    if (strlen(new_adress) + 1 <= strlen(this->adress) + 1) {
        this->adress = new_adress;
    }
}

void Student::set_telephone(char *new_tel) {
    if (strlen(new_tel) + 1 <= strlen(this->telephone) + 1) {
        this->telephone = new_tel;
    }
}

void Student::set_course(int new_course) {
    this->course = new_course;
}



