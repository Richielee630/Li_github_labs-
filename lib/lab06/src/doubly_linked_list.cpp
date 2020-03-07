#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    doubly_linked_list::doubly_linked_list(int input){
        node *newnode = new node(input);
        head = newnode;
        tail = newnode;
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {
        if(!vector_input.empty()) {
            node *newnode = new node(vector_input[0]);
            head = newnode;
            tail = head;
            for (int i; i < vector_input.size(); i++)
            {
                node *n = new node(vector_input[i]);
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
        }
        head = nullptr;
        tail = nullptr;
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        head = nullptr;
        tail = nullptr;
        node *original_head = original.head;
        if (original.head){
            node *original_head = original.head;
            node *newnode = new node(original_head->get_data());
            head = newnode;
            tail = head;
            original_head = original_head->next;
            while(original_head){
                node *n = new node(original_head->get_data());
                tail->next = n;
                n->prev = tail;
                tail = n;
                original_head = original_head->next;
            }
        }
    }

    doubly_linked_list::~doubly_linked_list() {
        node *traverse_node = head;
        while (traverse_node){
            node *delete_node = traverse_node;
            traverse_node = traverse_node->next;
            delete delete_node;
            delete_node = nullptr;
        }
        head = nullptr;
        tail = nullptr;
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
        node *cur_front = head;
        node *cur_back = head;
        while (position_from > 0){
            cur_front = cur_front->next;
            --position_from;
        }
//        while (cur_front->next){
//            std::cout << cur_front->get_data();
//        }
        while (position_to > 0 ){
            cur_back = cur_back->next;
            --position_to;
        }
        while (cur_front->next != cur_back){
            std::cout << cur_front->get_data();
        }
        ///vector 怎么 return
        ///此时如何return出两个position之间的strings？
        std::vector<int> output;
        output.push_back(get_data(position_from));
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
        return head == nullptr;
    }

    void doubly_linked_list::append(int input) {
        node *new_node = new node(input);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void doubly_linked_list::insert(int input, unsigned int location) {
        /*
         1. location
         2. 注意 prev
         */
        node *tmp = new node(input);
        if (location == 0){
            tmp->next = head;
            head = tmp;
                if(tail == nullptr){
                    tail = head;///这行的意义是？
                }
            }else{
                node* cur = head;
                while(location > 1){
                    --location;
                    cur = cur->next;
                }
                tmp->next = cur->next;///这一步的意义是？
                cur->next = tmp;
                tmp->prev = cur;
            }
    }

    void doubly_linked_list::remove(unsigned location) {
        if(location == 0){
            node* cur = head;
            if(cur != nullptr){
                head = head->next;
                if(head == nullptr){
                    tail = head;
                }
                delete cur;
                cur = nullptr;///delete cur了为什么还要cur = nullptr？
            }
        }
        else{
            node* cur = head;
            while(location > 1){
                --location;
                cur = cur->next;
            }
            if(cur->next){
                node* get = cur->next;
                cur->next = cur->next->next;
                if(get == tail){
                    tail = cur;
                }
                delete get;
                get = nullptr;
//                if(tail == get)
//                {
//                    tail = cur;
//                }
            }
        }
    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {
        ///1.创建链表list1,2
        ///2.location之前的放进list1，location之后的放list2
        node *split1;
        node *split2;
        node *cur1 = head;
        while (position > 0){
            --position;
            cur1 = cur1->next;
        }
        while (cur1->prev){
            split1->get_data() = cur1->get_data();
            cur1 = cur1->prev;
            return;
        }

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
    }

    void doubly_linked_list::sort() {
        if(head == nullptr){
            return;
        }
        node* prev = head;
        node* cur = head->next;
        while(cur){
            node* next = cur->next;
            node* loop = head;
            if(cur->get_data() <= loop->get_data()){
                cur->next = loop;
                head = cur;
                prev->next = next;
                cur = next;
            }else{
                node* loop_next = head->next;
                while(loop_next!=cur){
                    if(cur->get_data() <= loop_next->get_data()){
                        loop->next = cur;
                        cur->next = loop_next;
                        prev->next = next;
                        cur = next;
                        break;
                    }else{
                        loop = loop_next;
                        loop_next = loop_next->next;
                    }
                }
                if(loop_next == cur){
                    prev = cur;
                    cur = next;
                }
            }
        }
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
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {
        node* cur = RHS.head;
        while(cur){
            stream << cur->get_data() << " -> ";
            cur = cur->next;
        }
        stream << "NULL";
        return stream;
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
        std::string input;
        stream >> input;
        RHS.append();
        return stream;
    }
}

