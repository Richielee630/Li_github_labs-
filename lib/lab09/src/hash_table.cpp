#include "../inc/hash_table.h"

namespace lab9 {
    // Implemented for you.
    unsigned hash_table::hash_1(std::string to_hash) {
        // DJB2 Hashing Algorithm
        unsigned int hash = 5381;
        for(char c: to_hash){
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    // Implemented for you.
    unsigned hash_table::hash_2(std::string to_hash) {
        // BKDR Hashing Algorithm
        unsigned int seed = 131;
        unsigned int hash = 0;
        for(char c: to_hash){
            hash = (hash * seed) + c;
        }
        return hash;
    }

    void hash_table::expand() {
        // Expand the hash table by a factor of 2 every time this function is called
        key_value* hash_table_array_new = new key_value[2*max_size];
        for(int i = 0; i < max_size; ++i){
            if(hash_table_array[i].key != ""){
                int attempt = 0;
                int h1 = hash_1(hash_table_array[i].key);
                int h2 = 0;
                if(probing == 'd'){
                    h2 = hash_2(hash_table_array[i].key);
                }
                int a = 0;
                while(true){
                    if(hash_table_array_new[(h1+a)%(2*max_size)].key == ""){
                        hash_table_array_new[(h1+a)%(2*max_size)].key = hash_table_array[i].key;
                        hash_table_array_new[(h1+a)%(2*max_size)].value = hash_table_array[i].value;
                        break;
                    }
                    ++attempt;
                    a = attempt;
                    if(probing == 'q'){
                        a = a*a;
                    }else if(probing == 'd'){
                        a = a * h2;
                    }
                }
            }
        }
        max_size = 2*max_size;
        delete[] hash_table_array;
        hash_table_array = hash_table_array_new;
    }

    hash_table::hash_table(char type):probing(type),max_size(100),current_size(0),hash_table_array(new key_value[100]) {
        /*
         * Define the probing technique
         * 'l': Linear probing
         *          hash_1() + attempt
         * 'q': Quadratic probing
         *          hash_1() + attempt^2
         * 'd': Double Probing
         *          hash_1() + attempt * hash_2()
         *
         * Create a hash table with an initial size of 100
         */

    }

    hash_table::~hash_table() {
        delete[] hash_table_array;
    }

    bool hash_table::insert(std::string key, int value) {
        // Insert a key according to the defined probing technique
        // If you run into an issue where you get an infinite collision loop,
        //   figure out a way to get out of the loop.
        if(current_size*1.0/max_size > 0.7){
            expand();
        }
        int attempt = 0;
        int h1 = hash_1(key);
        int h2 = 0;
        if(probing == 'd'){
            h2 = hash_2(key);
        }
        int a = 0;
        while(attempt < max_size){
            if(hash_table_array[(h1+a)%(max_size)].key == ""){
                hash_table_array[(h1+a)%(max_size)].key = key;
                hash_table_array[(h1+a)%(max_size)].value = value;
                break;
            }
            ++attempt;
            a = attempt;
            if(probing == 'q'){
                a = a*a;
            }else if(probing == 'd'){
                a = a * h2;
            }
        }
        if(attempt >= max_size){
            return false;
        }
        return true;
    }

    bool hash_table::in_table(std::string key){
        // Checks to see if that key is in the table.
        // Use the specified probing technique
        // Keep collisions in mind
        int attempt = 0;
        int h1 = hash_1(key);
        int h2 = 0;
        if(probing == 'd'){
            h2 = hash_2(key);
        }
        int a = 0;
        while(attempt < max_size){
            if(hash_table_array[(h1+a)%(max_size)].key == key){
                break;
            }
            ++attempt;
            a = attempt;
            if(probing == 'q'){
                a = a*a;
            }else if(probing == 'd'){
                a = a * h2;
            }
        }
        if(attempt >= max_size){
            return false;
        }
        return true;

    }

    int hash_table::get(std::string key) {
        // Get the int value from the node that has key
        // Use the specified probing technique
        int attempt = 0;
        int h1 = hash_1(key);
        int h2 = 0;
        if(probing == 'd'){
            h2 = hash_2(key);
        }
        int a = 0;
        while(attempt < max_size){
            if(hash_table_array[(h1+a)%(max_size)].key == key){
                break;
            }
            ++attempt;
            a = attempt;
            if(probing == 'q'){
                a = a*a;
            }else if(probing == 'd'){
                a = a * h2;
            }
        }
        if(attempt < max_size){
            return hash_table_array[(h1+a)%(max_size)].value;
        }
        return 0;
    }

    void hash_table::update(std::string key, int value){
        // Update a key in the hash table.
        // Keep collisions in mind
        // Use the specified probing technique
        int attempt = 0;
        int h1 = hash_1(key);
        int h2 = 0;
        if(probing == 'd'){
            h2 = hash_2(key);
        }
        int a = 0;
        while(attempt < max_size){
            if(hash_table_array[(h1+a)%(max_size)].key == key){
                break;
            }
            ++attempt;
            a = attempt;
            if(probing == 'q'){
                a = a*a;
            }else if(probing == 'd'){
                a = a * h2;
            }
        }
        if(attempt < max_size){
            hash_table_array[(h1+a)%(max_size)].value = value;
        }

    }

    void hash_table::remove(std::string key){
        // Remove an item from the hash table. Keep collisions in mind
        // Use the specified probing technique
        // If the item isn't in the table, do nothing.
        int attempt = 0;
        int h1 = hash_1(key);
        int h2 = 0;
        if(probing == 'd'){
            h2 = hash_2(key);
        }
        int a = 0;
        while(attempt < max_size){
            if(hash_table_array[(h1+a)%(max_size)].key == key){
                break;
            }
            ++attempt;
            a = attempt;
            if(probing == 'q'){
                a = a*a;
            }else if(probing == 'd'){
                a = a * h2;
            }
        }
        if(attempt < max_size){
            hash_table_array[(h1+a)%(max_size)].key = "";
        }
        --current_size;
    }

    std::string hash_table::to_string(){
        // Run through the entire array and create a string following this format. The {} brackets aren't part of the return
        // [{array location}]{key_value.key}:{key_value.int}
        std::string output;
        for(int i = 0; i < max_size; ++i){
            if(hash_table_array[i].key != ""){
                output += "["+std::to_string(i)+"]"+ hash_table_array[i].key +":"+std::to_string(hash_table_array[i].value);
                output += "\n";
            }
        }
        return output;
        return std::string();
    }
}
