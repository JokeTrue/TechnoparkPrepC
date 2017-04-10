#ifndef DZ_7_STRING_HPP
#define DZ_7_STRING_HPP


class String {
public:
    String();

    String(const char *str);

    ~String();

    String(const String &rhs);

    String &operator=(const String &str);

    String &operator+=(const String &rhs);

    friend String operator+(String, String);

    std::size_t size() const;

    int length() const;

    void *display() const;

private:
    std::size_t _size;
    int _length;
    char *_string;
};


#endif //DZ_7_STRING_HPP
