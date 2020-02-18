#include "fifo.h"

namespace lab3{
    fifo::fifo()
    {
        fifo_storage.reserve(100);
        front_index = -1;
        back_index = -1;
        //Reserve 100 spaces in fifo_storage
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.reserve(100);
        front_index = 0;
        back_index = 1;
        fifo_storage [0] = input_string;
    }

    fifo::fifo(const fifo &original){
        fifo_storage.reserve(original.fifo_storage.capacity());
        front_index = original.front_index;
        back_index = original.back_index;
        for (int i = 0; i < original.fifo_storage.size(); i++){
            //this->fifo_storage[i] = original.fifo_storage [i];
        }
    }

    fifo::~fifo() {
        front_index=-1;
        back_index=-1;
        //delete []this->fifo_storage;
    }

    fifo &fifo::operator=(const fifo &right)
    {
        if (&right == this){
            return (*this);
        }
        fifo_storage.reserve(100);
        this->front_index = right.front_index;
        this->back_index = right.back_index;

    }

        //return <#initializer#>;

    bool fifo::is_empty() {
        return fifo_storage.empty();
        //return fifo_storage[front_index] == NULL
        return false;
    }

    //return *this;

    int fifo::size()
    {
        return fifo_storage.size();
        //return 0;
    }

    std::string fifo::top(){
        return fifo_storage[front_index];
        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input)
    {
        if (fifo_storage.empty())
        //if (fifo_storage.size() 0);
        {
            std::cout << "UnderFLow\nProgram Ended";
            exit(EXIT_FAILURE);
        }
        std::cout <<"Inserting" << input <<'\n';
        back_index = (back_index + 1 ) % fifo_storage.capacity();
        fifo_storage [back_index] = input;
        //fifo_storage.size()++;
        fifo_storage [++back_index];
    }

    void fifo::dequeue()
    {
        if (fifo_storage.empty())
        {
            std::cout << "UnderFLow\nProgram Ended";
            exit(EXIT_FAILURE);
        }
        std::cout <<"Removing" <<fifo_storage [front_index] <<'\n';
        front_index = (front_index + 1) % fifo_storage.capacity();
        fifo_storage[front_index--];
    }


}

