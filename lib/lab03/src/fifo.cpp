#include "fifo.h"

namespace lab3{
    fifo::fifo() {
        fifo_storage[100];
        front_index = 0;
        back_index = -1;
        //Reserve 100 spaces in fifo_storage
    }

    fifo::fifo(std::string input_string) {

    }

    fifo::fifo(const fifo &original) {

    }

    fifo::~fifo() {

    }

    fifo &fifo::operator=(const fifo &right) {
        //return <#initializer#>;
    }

    bool fifo::is_empty(){
        //return false;
    }

    int fifo::size(){
        //return fifo.size();
        //return 0;
    }

    std::string fifo::top(){
        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input)
    {
        if (is_empty())
        {
            std::cout << "UnderFLow\nProgram Ended";
            exit(EXIT_FAILURE);
        }
        //back_index = (back_index + 1 ) % fifo_storage;
        fifo_storage [back_index] = input;
    }

    void fifo::dequeue()
    {
        if (is_empty())
        {
            std::cout << "UnderFLow\nProgram Ended";
            exit(EXIT_FAILURE);
        }

    }
}

