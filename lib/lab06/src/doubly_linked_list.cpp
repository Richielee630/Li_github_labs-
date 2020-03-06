#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    doubly_linked_list::doubly_linked_list(int input){

        node *newnode = new node;

        newnode->get_data()=input;
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {

    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {

    }

    doubly_linked_list::~doubly_linked_list() {

    }

    int doubly_linked_list::get_data(unsigned position) {
        node* cur = head;
        while(position > 0){
            cur = cur->next;
            --position;
        }
        if(cur)
            return cur->get_data();
    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {

    }

    unsigned doubly_linked_list::size() {
        int len = 0;
        node *current;
        while (current != nullptr)
        {
            len++;
            current = current->next;
        }
        return len;
    }

    bool doubly_linked_list::is_empty() {
        return head->next = head;
    }

    void doubly_linked_list::append(int input) {

    }

    void doubly_linked_list::insert(int input, unsigned int location) {
        node *tmp = new node(input);
        if (location == 0){
            tmp->next = head;
            head = tmp;
                if(tail == nullptr){
                    tail = head;
                }
            }else{
                node* cur = head;
                while(location > 1){
                    --location;
                    cur = cur->next;
                }
                tmp->next = cur->next;
                cur->next = tmp;
            }
    }

    void doubly_linked_list::remove(unsigned location) {
        if(location == 0){
            node* cur = head;
            if(cur){
                head = head->next;
                if(head == nullptr){
                    tail = head;
                }
                delete cur;
                cur = nullptr;
            }
        }else{
            node* cur = head;
            while(location > 1){
                --location;
                cur = cur->next;
            }
            if(cur->next){
                node* get = cur->next;
                cur->next = cur->next->next;
                if(tail == get){
                    tail = cur;
                }
                delete get;
                get = nullptr;
                if(tail == get){
                    tail = cur;
                }
            }
        }
    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {

    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {

    }

    void doubly_linked_list::sort() {
        // Implement Insertion Sort
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {

    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {
        if (this != &rhs)
        {
            if (head != nullptr){
                //delete this;
                node* cur = head;
                while(cur){
                    node* next = cur->next;
                    delete cur;
                    cur = next;
                }
                head = tail = nullptr;
            }
            if (rhs.head != nullptr)
            {
                node *RHS_tmp = rhs.head;
                node *tmp = head = new node(RHS_tmp->get_data());
                //size = RHS.size;
                RHS_tmp = RHS_tmp->next;
                while (RHS_tmp != nullptr)
                {
                    tmp->next = new node(RHS_tmp->get_data());
                    tmp = tmp->next;
                    tail = tmp;
                    RHS_tmp = RHS_tmp->next;
                }
                //size = RHS.size;
            }
        }
        return *this;
        //return <#initializer#>;
    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {

    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
        int i =0;
        node *p = head->next;
        while ()
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {

    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {

    }
}

