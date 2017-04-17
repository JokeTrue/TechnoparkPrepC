#ifndef DZ_8_MYFILE_HPP
#define DZ_8_MYFILE_HPP


#include <string>
#include <map>
#include <unordered_map>
#include <vector>

class MyFile {
    typedef int Key;
    typedef std::vector<std::string> Value;
public:
    MyFile();

    MyFile(const std::string *path);

    ~MyFile() = default;

    void add_word(std::string *word, Key sentence_num);

    double calculate(const std::string *word);

    void display();

private:
    std::string *path;
    std::unordered_map<Key, Value> *words;

};


#endif //DZ_8_MYFILE_HPP
