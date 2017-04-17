#include    <fstream>
#include <vector>
#include "MyFile.hpp"
#include <boost/algorithm/string.hpp>

MyFile::MyFile() :
        path(nullptr),
        words(nullptr) {

}

MyFile::MyFile(const std::string *path) :
        words(nullptr) {
    words = new std::unordered_map<int, std::vector<std::string>>;

    std::ifstream file(*path);
    int sentence_count = 0;
    for (std::string line; std::getline(file, line);) {
        std::vector<std::string> sentence_vec;
        boost::split(sentence_vec, line, boost::is_any_of(".!?"));
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
                        add_word(&word, sentence_count);
//                        std::cout << word << std::endl;
                    }
                }
            } else {
                if (!sentence.empty()) {
                    add_word(&sentence, sentence_count);
//                    std::cout << sentence << std::endl;
                }
            }
            sentence_count++;
//            std::cout << "-----------------" << std::endl;
        }
    }
}

void MyFile::add_word(std::string *word, Key sentence_num) {
    if (words->find(sentence_num) == words->end()) {
        std::vector<std::string> words_vector;
        words_vector.push_back(*word);
        words->insert(std::make_pair(sentence_num, words_vector));
    } else {
        words->at(sentence_num).push_back(*word);
    }
}

void MyFile::display() {
    for (auto it = words->begin(); it != words->end();) {
        for (auto obj: it->second) {
            std::cout << obj << std::endl;
        }
        ++it;
    }
}

double MyFile::calculate(const std::string *word) {
    double N = (double) words->size();
    double count = 0;

    for (auto it = words->begin(); it != words->end();) {
        for (auto obj: it->second) {
            if (*word == obj) {
                count++;
            }
        }
        ++it;
    }

    return (count / N);
}
