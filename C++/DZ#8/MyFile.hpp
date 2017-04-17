#ifndef DZ_8_MYFILE_HPP
#define DZ_8_MYFILE_HPP


#include <string>
#include <map>
#include <unordered_map>
#include <vector>

class MyFile {
public:
    MyFile();

    MyFile(const std::string *path);

    ~MyFile() = default;

    MyFile(MyFile const &) = delete;

    void operator=(MyFile const &x) = delete;

    MyFile(MyFile &&) = delete;

    bool process();

    double calculate(const std::string *word);

private:
    const std::string *path;
    std::vector<std::string> *words;
    int sentences;

};


#endif //DZ_8_MYFILE_HPP
