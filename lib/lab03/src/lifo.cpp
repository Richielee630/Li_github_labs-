#include "lifo.h"

namespace lab3 {
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = -1;
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        index = 1;
        lifo_storage [index] = input_string;
    }

    lifo::lifo(const lifo &original) {
        //lifo_storage.reserve(original.lifo_storage.capacity());
        index = original.index;
        lifo_storage = original.lifo_storage;
    }

    lifo::~lifo() {
        index = -1;
    }

    lifo &lifo::operator=(const lifo &right) {
        if(this == &right){
            return *this;
        }
        index = right.index;
        lifo_storage= right.lifo_storage;
        return *this;
    }

    bool lifo::is_empty() {
        if(index == -1){
            return true;
        }

        return false;
    }

    int lifo::size()
    {
        return index + 1 ;

    }

    std::string lifo::top() {
        return lifo_storage[index];
    }

    void lifo::push(std::string input) {
        std::cout << "Inserting" << input << '\n';
        lifo_storage[index + 1] = input;
        index++;
    }

    void lifo::pop()
    {
        std::cout << "Removing" << lifo_storage[index] <<'\n';
        index--;
    }
}
