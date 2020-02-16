#include "lifo.h"

namespace lab3 {
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = -1;
        //Reserve 100 spaces in lifo_storage
    }

    lifo::lifo(std::string input_string) {

    }

    lifo::lifo(const lifo &original) {

    }

    lifo::~lifo() {
        //delete []lifo_storage;
    }

    lifo &lifo::operator=(const lifo &right) {
        //return <#initializer#>;
    }

    bool lifo::is_empty() {
        {
            return lifo_storage.size() == 0;
        }
        //return false;
    }

    int lifo::size()
    {
        return lifo_storage.size() + 1;
        //return 0;
    }

    std::string lifo::top() {
        return lifo_storage[index];
        //return std::__cxx11::string();
    }

    void lifo::push(std::string input) {
        if (lifo_storage.empty()) {
            std::cout << "UnderFLow\nProgram Ended";
            exit(EXIT_FAILURE);
        }
        std::cout << "Inserting" << input << '\n';
        lifo_storage[++index] = input;
    }

    void lifo::pop()
    {
        if (lifo_storage.empty()) {
            std::cout << "UnderFLow\nProgram Ended";
            exit(EXIT_FAILURE);
        }
        std::cout << "Removing" << lifo_storage[index] <<'\n';
        lifo_storage [index--];
    }
}