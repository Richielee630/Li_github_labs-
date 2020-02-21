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
        lifo_storage.reserve(original.lifo_storage.capacity());
        index = original.index;
//        for (int i = 0; i < index; i++){
        lifo_storage = original.lifo_storage;
//        }
    }

    lifo::~lifo() {
        index = -1;
        //delete []lifo_storage;
    }

    lifo &lifo::operator=(const lifo &right) {
        if(this == &right){
            return *this;
        }
        index = right.index;
        //allocated_length = rhs.allocated_length;
        //data = new std::string[allocated_length];
        lifo_storage= right.lifo_storage;
        //for(int i=0; i<allocated_length; i++){
        //    data[i]=rhs.data[i];
        //}
        return *this;
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
        return index + 1 ;
    }

    std::string lifo::top() {
        return lifo_storage[index];
        //return std::__cxx11::string();
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
