#include <vector>
#include "../inc/stringVector.h"

namespace lab2 {
    stringVector::stringVector() {
        length = 0;
        allocated_length = 0;
    //std::vector<int> tec
    }

    stringVector::~stringVector() {
        delete data;
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
        std::string *temp = new std::string[new_size];
        for (int i= 0; i < length; i ++) {
            temp[i] = data[i];
        }
        delete []data;
        data = temp;
    }

    bool stringVector::empty() const{
        if (length == 0) {
            //std::cout << "True";
            return true;
        }
        else {
            //std::cout << "False";
            return false;
        }
        //return ;
    }

    void stringVector::append(std::string new_data) {
        //delete []new_data
        if (allocated_length == 0){
            allocated_length == 1;
            data = new std::string[allocated_length];
            data[0] = new_data;
        }
        else if (length == allocated_length){
            std::string *temp = new std::string[2*allocated_length];
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
        int n;
        std::cin>>n;
        char s1[n];
        char s2[n];
        char s3[n];
        std::cin>>s1;
        std::cin>>s2;
        strcpy(s3,s1);
        strcpy(s1,s2);
        strcpy(s2,s3);
        std::cout<<s1<<"\n";
        std::cout<<s2;
        //return 0 ;
    }

    stringVector &stringVector::operator=(stringVector const &rhs) {
        if (this == &rhs)
            return *this;
        const = rhs.length;
        return *this;
        //return ;
    }

    std::string &stringVector::operator[](unsigned position) {


        //return ;
    }

    void stringVector::sort()
    {
        int n;
        char arr[n][MAX];
        char temp[MAX];
        for (int j=0 ; j<n-1 ; j++)
        {
            for (int i=j+1 ; i<n ; i++) {
                if (strcmp(arr[j],arr[i]) > 0 )
                {
                    strcpy(temp, arr[j]);
                    strcpy(arr[j], arr[i]);
                    strcpy(arr[i], temp);
                }
            }
        }
    }
}