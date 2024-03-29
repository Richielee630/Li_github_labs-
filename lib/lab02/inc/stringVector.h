
#ifndef CMPE126S20_LABS_STRINGVECTOR_H
#define CMPE126S20_LABS_STRINGVECTOR_H

#include <string>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

#define MAX 100
namespace lab2 {
    class stringVector {
    private:
        std::string *data;
        unsigned length;
        unsigned allocated_length;

    public:
        stringVector();
        virtual ~stringVector();
        unsigned size()const;
        unsigned capacity()const;
        void reserve(unsigned new_size);
        bool empty()const;
        void append(std::string new_data);
        void swap(unsigned pos1, unsigned pos2);
        stringVector &operator=(stringVector const &rhs);
        std::string &operator[](unsigned position);
        void sort();
    };
}

#endif //CMPE126S20_LABS_STRINGVECTOR_H
