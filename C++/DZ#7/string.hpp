#ifndef DZ_7_STRING_HPP
#define DZ_7_STRING_HPP
using std::ostream;

class String {
public:
    String();

    String(const char *str);

    ~String();

    String(const String &rhs);

    String &operator=(const String &str);

    char &operator[](unsigned int);

    String &operator+=(const String &rhs);

    friend String operator+(String, String);

    friend bool operator==(const String &s, const String &t);

    std::size_t size() const;

    int length() const;

    void *display() const;

    friend ostream &operator<<(ostream &ost, const String &s);

private:
    std::size_t _size;
    int _length;
    char *_string;
};


#endif //DZ_7_STRING_HPP