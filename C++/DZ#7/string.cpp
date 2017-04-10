#include <cstring>
#include <iostream>
#include "string.hpp"

String::String() :
        _size(0),
        _length(0),
        _string(nullptr) {

}

String::String(const char *str) {
    _length = (int) strlen(str);
    _size = _length + 1;
    _string = new char[_size];

    strcpy(_string, str);
}

String::~String() {
    if (_string != nullptr) {
        delete[] _string;
        _string = nullptr;
    }
}

String::String(const String &rhs) {
    _length = rhs._length;
    _size = rhs._size;
    _string = new char[_size];

    strcpy(_string, rhs._string);
}

String operator+(String a, String b) {
    a += b;
    return a;
}

String &String::operator=(const String &rhs) {
    if (this != &rhs) {
        _length = rhs._length;
        _size = rhs._size;
        delete[] _string;
        _string = new char[_size];

        strcpy(_string, rhs._string);

    }

    return *this;
}

String &String::operator+=(const String &rhs) {
    _length = _length + rhs._length;
    _size = _length + 1;

    char *buffer = new char[_size];
    strcpy(buffer, _string);
    strcat(buffer, rhs._string);

    delete[] _string;
    _string = buffer;

    return *this;
}

std::size_t String::size() const {
    return _size;
}

int String::length() const {
    return _length;
}

void *String::display() const {
    std::cout << _string << std::endl;
}




