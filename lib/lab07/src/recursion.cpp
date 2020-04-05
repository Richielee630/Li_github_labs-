#include <string>
#include "../inc/recursion.h"

namespace lab7 {
    recursion::recursion() {
    }

    recursion::~recursion() {
    }

    int recursion::fibonacci(int N) {
        if(N < 0){
            throw "N should be larger than 0";
            return -1;
        }
        if(N==0){
            return 0;
        }
        if(N == 1){
            return 1;
        }
        return fibonacci(N-1)+fibonacci(N-2);

    }

    int recursion::climb_stairs(int n) {
        if(n < 1){
            throw "N should be larger than 1";
            return -1;
        }
        if(n==1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        return climb_stairs(n-1)+climb_stairs(n-2);

        return 0;
    }

    int recursion::pow(int base, int n) {
        if(n < 0){
            throw "n should be larger or equal than 0";
            return -1;
        }
        if(n == 0){
            return 1;
        }
        if( n == 1){
            return base;
        }
        int get = pow(base,n/2);
        get = get*get;
        return n%2 == 0?get:get*base;
    }

    // hint: first check the first and last characters, then recurse with what's left inside
    bool recursion::valid_parenthesis(std::string input) {
        if(input.length() == 0){
            return true;
        }
        if(input[0] == '(' && input[input.length()-1] == ')'){
            return valid_parenthesis(input.substr(1,input.length()-2));
        }else{
            return false;
        }
    }

    // hint: this is very similar to what you've done with linked lists previously, just using recursion.
    bool recursion::are_nodes_ok(const node* head) {
        if(head == nullptr){
            return false;
        }
        if(head->ok == false){
            return false;
        }
        if(head->next == nullptr){
            return true;
        }
        return are_nodes_ok(head->next);
    }
}
