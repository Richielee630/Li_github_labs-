#include "lifo.h"

namespace lab3 {
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = -1;
        //Reserve 100 spaces in lifo_storage
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        index = 1;
        lifo_storage [0] = input_string;
    }

    lifo::lifo(const lifo &original) {
        lifo_storage.reserve(original.lifo_storage.capacity());
        index = original.index;
        for (int i = 0; i < index; i++){
            lifo_storage[i] = original.lifo_storage[i];
        }
    }

    lifo::~lifo() {
        index = -1;
        //delete []lifo_storage;
    }

    lifo &lifo::operator=(const lifo &right) {
        index = right.index;
        lifo_storage.reserve(right.lifo_storage.capacity());
        for (int i = 0; i <= index; i++) {
            lifo_storage[i] = right.lifo_storage[i];
        }
        return *this;
        //return <#initializer#>;
    }

    bool lifo::is_empty() {
        if(index == -1){
            return true;
        }

        return false;
    }
        //return false;

    int lifo::size()
    {
//        int temp;
//        if (index > -1) {
//            for (int i = 0; i <= index; i++) {
//                temp++;
//            }
//        } else {
//            temp = 0;
//        }
//        return temp;
        return lifo_storage.size();
    }

    std::string lifo::top() {
        return lifo_storage[index];
        //return std::__cxx11::string();
    }

    void lifo::push(std::string input) {
//        if (lifo_storage.empty())
//        {
//            std::cout << "UnderFLow\nProgram Ended";
//            exit(EXIT_FAILURE);
//        }
        if (index == lifo_storage.capacity() - 1)
        {
            lifo_storage.reserve(lifo_storage.capacity() + 20);
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
        index--;
    }
}