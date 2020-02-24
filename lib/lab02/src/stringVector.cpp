#include <vector>
#include "../inc/stringVector.h"

namespace lab2 {
    stringVector::stringVector() {
        //new std::string[allocated_length];
        data = nullptr;
        length = 0;
        allocated_length = 0;
        //std::vector<int> tec
    }

    stringVector::~stringVector() {
        if (allocated_length > 0)
        delete[] data;
    }

    unsigned stringVector::size() const {
        return length;
        //return ;
    }

    unsigned stringVector::capacity() const {
        return allocated_length;
        //return ;
    }

    void stringVector::reserve(unsigned new_size) {
        std::string *temp = new std::string[new_size]; // Create a new array
        for(int i =0; i < new_size; i++)
        {
            if(i < length){
                temp[i] = data[i];
            }
            else
                break;
        }

        delete []data ;
        data = temp;

        allocated_length = new_size;

        if(length > new_size){
            length = new_size;
        }
    }

    bool stringVector::empty() const {
        return length == 0;
        //return ;
    }

    void stringVector::append(std::string new_data) {
        if (allocated_length == 0) {
            allocated_length = 1;
            //length = 1;
            data = new std::string[allocated_length];
            data[0] = new_data;
        } else if (length == allocated_length) {
            auto *temp = new std::string[2 * allocated_length];
            for (int i = 0; i < allocated_length; i++)
            {
                temp[i] = data[i];
            }
            allocated_length = 2* allocated_length;
            delete[]data;
            data = temp;
            temp [length] =new_data;
        } else {
            data[length] = new_data;
        }
        length++;
    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        if (pos1 >= length || pos2 >= length) {
            throw std::invalid_argument("out of bounds");
        } else {
            std::string temp;
            temp = data[pos1];
            data[pos1] = data[pos2];
            data[pos2] = temp;
        }
    }


    stringVector &stringVector::operator=(stringVector const &rhs) {
        if(this == &rhs){
            return *this;
        }
        length = rhs.length;
        allocated_length = rhs.allocated_length;
        data = new std::string[allocated_length];
        for(int i=0; i<allocated_length; i++){
            data[i]=rhs.data[i];
        }
        return *this;
//        length = rhs.length;
//        allocated_length = rhs.allocated_length;
//        std::string *data = new std::string [allocated_length];
//        for (int i; i < length; i++ )
//        {
//            data[i] = rhs.data[i];
//        }
//        return *this;
    }

    std::string &stringVector::operator[](unsigned position) {
        if(position >= allocated_length){
            throw std::invalid_argument("Position Out Of Range");
        }
        return data[position];
    }

    void stringVector::sort() {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - 1; j++) {
                if (data[j].compare(data[j + 1]) > 0) {
                    swap(j, j + 1);
                }
            }
        }
    }
}