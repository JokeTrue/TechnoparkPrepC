#ifndef _SET_H_
#define _SET_H_

#include <iostream>

using std::ostream;
using std::istream;

template<class T>
class Set {
private:

    int _capacity;

    int _size;

    T *buffer;

    void copy(const Set &s);

    void clear();

    int find(const T &d) const;

public:
    typedef T *iterator;

    iterator begin();

    iterator end();

    T &front();

    T &back();

    typedef T *const_iterator;

    const_iterator begin() const;

    const_iterator end() const;

    T &front() const;

    T &back() const;


    T &operator[](unsigned int index);

public:

    Set(int s = 0);

    Set(const T *arr, int n);

    Set(const Set &s);

    Set(const T &d);

    ~Set();

    Set &operator=(const Set &s);

    bool is_in(const T &d) const;

    bool insert(const T &d);

    bool erase(const T &d);

    bool full() const;

    bool empty() const;

    void clean();

    int size() const;

    Set &operator+=(const Set &v);

    Set &operator-=(const Set &v);

    bool compare(const Set &v) const;

    void print(ostream &ost) const;

    void scan(istream &ist);

};

template<class T>
bool operator==(const Set<T> &v1, const Set<T> &v2);

template<class T>
bool operator!=(const Set<T> &v1, const Set<T> &v2);

template<class T>
ostream &operator<<(ostream &ost, const Set<T> &v);

template<class T>
istream &operator>>(istream &ist, Set<T> &v);

template<class T>
Set<T> operator+(const Set<T> &v1, const Set<T> &v2);

template<class T>
Set<T> operator-(const Set<T> &v1, const Set<T> &v2);

template<class T>
void Set<T>::copy(const Set<T> &s) {
    _capacity = s._capacity;
    _size = s._size;

    buffer = new T[_capacity];

    for (int i = 0; i < _size; i++) {
        buffer[i] = s.buffer[i];
    }
}

template<class T>
void Set<T>::clear() {
    if (buffer) {
        delete[] buffer;
        buffer = nullptr;
        _capacity = 0;
        _size = 0;
    }
}

template<class T>
Set<T>::Set(int s)
        : _capacity(s), _size(0), buffer(new T[s]) {
}

template<class T>
Set<T>::Set(const Set<T> &s) {
    copy(s);
}

template<class T>
Set<T>::Set(const T &d) {
    _capacity = 1;
    _size = 1;
    buffer = new T(d);
}

template<class T>
Set<T>::Set(const T *arr, int n) {
    _capacity = n;
    _size = 0;
    buffer = new T[n];

    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
}

template<class T>
Set<T>::~Set() {
    clear();
}

template<class T>
Set<T> &Set<T>::operator=(const Set<T> &s) {
    if (this == &s) {
        return *this;
    }
    clear();
    copy(s);
    return *this;
}

template<class T>
Set<T> &Set<T>::operator+=(const Set<T> &s) {
    if (this == &s) {
        return *this;

    }
    Set new_set(_capacity + s._capacity);

    new_set._size = _size;
    for (int i = 0; i < _size; i++) {
        new_set.buffer[i] = buffer[i];
    }

    for (int i = 0; i < s._size; i++) {
        new_set.insert(s.buffer[i]);
    }
    *this = new_set;
    return *this;
}

template<class T>
Set<T> operator+(const Set<T> &s1, const Set<T> &s2) {
    Set<T> s = s1;
    s += s2;
    return s;
}

template<class T>
Set<T> &Set<T>::operator-=(const Set<T> &s) {
    if (this == &s) {
        clean();
    }

    for (int i = 0; i < s._size; i++) {
        erase(s.buffer[i]);
    }
    return *this;
}

template<class T>
Set<T> operator-(const Set<T> &s1, const Set<T> &s2) {
    Set<T> s = s1;
    s -= s2;
    return s;
}

template<class T>
int Set<T>::size() const {
    return _size;
}

template<class T>
bool Set<T>::compare(const Set<T> &s) const {
    if (this == &s) {
        return true;
    }

    if (_size != s._size) {
        return false;
    }

    for (int i = 0; i < _size; i++) {
        if (!is_in(s.buffer[i])) {
            return false;
        }
    }
    return true;
}

template<class T>
bool operator==(const Set<T> &s1, const Set<T> &s2) {
    return s1.compare(s2);
}

template<class T>
bool operator!=(const Set<T> &s1, const Set<T> &s2) {
    return !(s1 == s2);
}

template<class T>
void Set<T>::print(ostream &ost) const {
    ost << "( ";

    for (int i = 0; i < _size; i++)
        ost << buffer[i] << " ";
    ost << ")";
}

template<class T>
ostream &operator<<(ostream &ost, const Set<T> &s) {
    s.print(ost);
    return ost;
}

template<class T>
void Set<T>::scan(istream &ist) {
    T d;


    while (!ist.eof() && !full()) {
        ist >> d;
        insert(d);
    }
}

template<class T>
istream &operator>>(istream &ist, Set<T> &s) {
    s.scan(ist);
    return ist;
}

template<class T>
bool Set<T>::is_in(const T &d) const {
    for (int i = 0; i < _size; i++) {
        if (buffer[i] == d) {
            return true;
        }
    }
    return false;
}

template<class T>
bool Set<T>::full() const {
    return (_size == _capacity);
}

template<class T>
bool Set<T>::empty() const {
    return (_size == 0);
}

template<class T>
bool Set<T>::insert(const T &d) {
    if (!is_in(d) && !full()) {
        buffer[_size++] = d;
        return true;
    }
    return false;
}

template<class T>
bool Set<T>::erase(const T &d) {
    if (is_in(d)) {
        int i = find(d);
        for (int j = i; j < _size; j++) {
            buffer[j] = buffer[j + 1];
            _size--;
            return true;
        }
    }
    return false;
}

template<class T>
void Set<T>::clean() {
    _size = 0;
}

template<class T>
int Set<T>::find(const T &d) const {
    for (int i = 0; i < _size; i++) {
        if (buffer[i] == d)
            return i;
    }
    return -1;
}

template<class T>
typename Set<T>::iterator Set<T>::begin() {
    return buffer;
}

template<class T>
typename Set<T>::iterator Set<T>::end() {
    return buffer + _size;
}

template<class T>
T &Set<T>::front() {
    return buffer[0];
}

template<class T>
T &Set<T>::back() {
    return buffer[_size - 1];
}

template<class T>
T &Set<T>::operator[](unsigned int index) {
    return buffer[index];
}

template<class T>
typename Set<T>::const_iterator Set<T>::begin() const {
    return buffer;
}

template<class T>
typename Set<T>::const_iterator Set<T>::end() const {
    return buffer + _size;
}

template<class T>
T &Set<T>::front() const {
    return buffer[0];
}

template<class T>
T &Set<T>::back() const {
    return buffer[_size - 1];
}


#endif