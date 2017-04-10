#ifndef _SET_H_
#define _SET_H_

#include <iostream>

using std::ostream;

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

    Set(T *arr, int n);

    Set(const Set &s);

    Set(const T &d);

    Set(Set<T> &&other);

    Set &operator=(Set<T> &&other);

    ~Set();

    bool is_in(T &d) const;

    bool insert(T &d);

    bool erase(T &d);

    bool full() const;

    bool empty() const;

    void clean();

    int size() const;

    Set &operator=(const Set &s);

    Set &operator+=(const Set &v);

    Set &operator-=(const Set &v);

    ostream &operator<<(ostream &ost);

    bool compare(const Set &v) const;

};

template<class T>
bool operator==(const Set<T> &v1, const Set<T> &v2);

template<class T>
bool operator!=(const Set<T> &v1, const Set<T> &v2);

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
Set<T>::Set(T *arr, int n) {
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
ostream &Set<T>::operator<<(ostream &ost) {
    ost << "( ";
    for (int i = 0; i < _size; i++) {
        ost << buffer[i] << " ";
    }
    ost << ")";
    return ost;
}

template<class T>
bool Set<T>::is_in(T &d) const {
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
bool Set<T>::insert(T &d) {
    if (!is_in(d) && !full()) {
        buffer[_size++] = d;
        return true;
    }
    return false;
}

template<class T>
bool Set<T>::erase(T &d) {
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

template<class T>
Set<T>::Set(Set<T> &&other) :
        _capacity(0), _size(0), buffer(nullptr) {
    _capacity = other._capacity;
    _size = other._size;
    buffer = other.buffer;

    other._capacity = 0;
    other._size = 0;
    other.buffer = nullptr;
}

template<class T>
Set<T> &Set<T>::operator=(Set<T> &&other) {
    if (this != &other) {
        delete[] buffer;

        _capacity = other._capacity;
        _size = other._size;
        buffer = other.buffer;

        other._capacity = 0;
        other._size = 0;
        other.buffer = nullptr;
    }
    return *this;
}


#endif