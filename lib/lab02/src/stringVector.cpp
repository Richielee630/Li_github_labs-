#include <vector>
#include "../inc/stringVector.h"

namespace lab2 {
    stringVector::stringVector() {
        new std::string[allocated_length];
        length = 0;
        allocated_length = 0;
    //std::vector<int> tec
    }

    stringVector::~stringVector() {
        delete[] data;
    }

    unsigned stringVector::size() const{
        return length;
        //return ;
    }

    unsigned stringVector::capacity() const{
        return allocated_length;
        //return ;
    }

    void stringVector::reserve(unsigned new_size) {
        auto *temp = new std::string[new_size];
        for (int i= 0; i < length; i ++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    bool stringVector::empty() const{
        return length == 0;
        //return ;
    }

    void stringVector::append(std::string new_data) {
        //delete []new_data
        if (allocated_length == 0){
            allocated_length = 1;
            data = new std::string[allocated_length];
            data[0] = new_data;
        }
        else if (length == allocated_length){
            auto *temp = new std::string[2*allocated_length];
            for (int i= 0; i < length; i ++){
                temp[i] = data[i];
            }
            delete []data;
            data = temp;
        }
        else{
            data[length]= new_data;
        }
        length++;
    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        if (pos1 >= length || pos2 >= length)
        {
            throw std::invalid_argument("out of bounds");
        }
        else
        {
            std::string temp;
            temp = data[pos1];
            data[pos1] = data [pos2];
            data[pos2] = temp;
        }
//        int n;
//        std::cin>>n;
//        char s1[n];
//        char s2[n];
//        char s3[n];
//        std::cin>>s1;
//        std::cin>>s2;
//        strcpy(s3,s1);
//        strcpy(s1,s2);
//        strcpy(s2,s3);
//        std::cout<<s1<<"\n";
//        std::cout<<s2;
//        //return 0 ;
    }

    //stringVector &stringVector::operator=(std::string *rhs) {
        //if (this == &rhs)
            //return *this;
        //const = rhs.length;
        //return *this;
        //return ;
        //delete []data;
        //data = reinterpret_cast<std::string *>(new int[rhs.length]);
        //length = rhs.length;
        //memcpy(data, rhs.data, sizeof(int) * length);
    //}
    stringVector &stringVector::operator=(stringVector const &rhs) {
        delete[]data;
        data = reinterpret_cast<std::string *>(new int[rhs.length]);
        length = rhs.length;
        memcpy(data, rhs.data, sizeof(int) * length);
    }

    std::string &stringVector::operator[](unsigned position)
    {
        {
            if(position > length){
                throw std::out_of_range("Position out of range");
            }

            return data[position - 1];
        }


    }

    void stringVector::sort() {
        {
            string str;

            for (int i = (length - 1); i > 0; i--) {

                for (int j = 0; j < i; j++) {
                    if (data[j].compare(data[j + 1]) > 0) {
//Swap
                        str = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = str;
                    }
                }
            }
        }
}

