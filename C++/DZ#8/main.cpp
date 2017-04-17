#include <iostream>
#include <fstream>
#include "MyFile.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Got " << argc - 1 << " arguments, expected 2." << std::endl;
        return 0;
    }

    const std::string *path = new std::string(argv[1]);
    const std::string *word = new std::string(argv[2]);

    MyFile mf(path);
    if (mf.process()) {
        std::cout << "Среднее значение вхождения слова в документе = "  << mf.calculate(word) << std::endl;
    } else {
        std::cerr << "Error occurred during processing stage" << std::endl;
    }
    return 0;
}