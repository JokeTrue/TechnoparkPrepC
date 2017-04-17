#include  <fstream>
#include <vector>
#include "MyFile.hpp"
#include <boost/algorithm/string.hpp>

MyFile::MyFile() :
        path(nullptr),
        words(nullptr),
        sentences(0) {
    words = new std::vector<std::string>;
}

MyFile::MyFile(const std::string *path) :
        path(path),
        words(nullptr),
        sentences(0) {
    words = new std::vector<std::string>;
}

double MyFile::calculate(const std::string *word) {
    if (words != nullptr) {
        double count = 0;

        for (auto it = words->begin(); it != words->end(); ++it) {
            if (boost::iequals(*word, *it)) {
                count++;
            }
        }
        return (count / sentences);
    } else {
        return -1;
    }
}

bool MyFile::process() {
    try {
        std::ifstream file(*this->path);

        for (std::string line; std::getline(file, line);) {
            std::vector<std::string> sentence_vec;

            boost::split(sentence_vec, line, boost::is_any_of(".!?"));
            sentence_vec.erase(std::remove_if(sentence_vec.begin(), sentence_vec.end(),
                                              [](const std::string &s) { return s.find("", 0); }));

            for (auto sentence: sentence_vec) {
                std::vector<std::string> words_vec;

                int spaces = 0;
                for (auto character: sentence) {
                    if (std::isspace(character)) {
                        spaces++;
                    }
                }
                if (spaces > 0) {
                    boost::split(words_vec, sentence, boost::is_any_of(" "));
                    for (auto word: words_vec) {
                        if (!word.empty()) {
                            words->push_back(word);
                        }
                    }
                } else {
                    if (!sentence.empty()) {
                        words->push_back(sentence);
                    }
                }
            }
            sentences += sentence_vec.size();
        }
    } catch (const std::exception &exc) {
        return false;
    }
    return true;
}
