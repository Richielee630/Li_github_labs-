#include "fifo.h"

namespace lab3{
    fifo::fifo()
    {
        fifo_storage.reserve(100);
        front_index = 0;
        back_index = 0;
        //Reserve 100 spaces in fifo_storage
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.reserve(100);
        fifo_storage [0] = input_string;
        front_index = 0;
        back_index = 0;
    }

    fifo::fifo(const fifo &original){
        fifo_storage.reserve(original.fifo_storage.capacity());
        front_index = original.front_index;
        back_index = original.back_index;
//        for (int i = 0; i < original.fifo_storage.size(); i++){
            this->fifo_storage = original.fifo_storage;
//        }
    }

    fifo::~fifo() {
        front_index=-1;
        back_index=-1;
    }

    fifo &fifo::operator=(const fifo &right)
    {
        fifo_storage.reserve(right.fifo_storage.capacity());
//        fifo_storage.reserve(100);
        front_index = right.front_index;
        back_index = right.back_index;
//        for(int i = 0 ; i<right.fifo_storage.size() ; i++){
            fifo_storage = right.fifo_storage;
//        }
        return *this;
    }

        //return <#initializer#>;

    bool fifo::is_empty() {
        if(front_index == back_index){
            return true;
        }
        return false;
    }

    //return *this;

    int fifo::size()
    {
//        int temp;
//        if (back_index - front_index > 0) {
//            for (int i = 0; i <= front_index; i++) {
//                temp++;
//            }
//        } else {
//            temp = 0;
//        }
//        return temp;
        return (back_index-front_index) % fifo_storage.capacity();
        //return 0;
    }

    std::string fifo::top(){
        return fifo_storage[front_index];
        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input)
    {

        std::cout <<"Inserting" << input <<'\n';
        fifo_storage [back_index] = input;
        back_index++;
    }

    void fifo::dequeue()
    {
//        if (fifo_storage.empty())
//        {
//            std::cout << "UnderFLow\nProgram Ended";
//            exit(EXIT_FAILURE);
//        }
        std::cout <<"Removing" <<fifo_storage [front_index + 1] <<'\n';
        front_index++;
    }


}

