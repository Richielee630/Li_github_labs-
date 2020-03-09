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
        head = nullptr;
        tail = nullptr;
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

        std::vector<int> output;

        while (position_from > 0){
            cur_front = cur_front->next;
            --position_from;
        }

        while (position_to > 0 ){
            cur_back = cur_back->next;
            --position_to;
        }

        while (cur_front != cur_back){
            output.push_back(cur_front->get_data());
            cur_front = cur_front->next;
        }
        output.push_back(cur_front->get_data());///当set包含position to的data时的情况
        return output;
        ///vector 怎么 return
        ///此时如何return出两个position之间的strings？
    }

    unsigned doubly_linked_list::size() {
        int len = 0;
        node *current = head;
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
        if(tail == nullptr)
        {
            head = new_node;
            tail = head;
        }else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
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
                tail = head;
            }
        }
        else {
            node *cur = head;
            while (location > 1) {
                --location;
                cur = cur->next;
            }
            node *next = cur->next;
            //tmp->next = cur->next;///这一步的意义是？
            //cur->next->prev = cur;
            cur->next = tmp;
            tmp->prev = cur;
            tmp->next = next;
            next->prev = tmp;
        }
    }

    void doubly_linked_list::remove(unsigned location) {
        if(location == 0){
            node* cur = head;
            if(cur != nullptr){
                head = head->next;

                if(head == nullptr){
                    tail = head;
                }else{
                    head->prev = nullptr;
                }
                delete cur;
                cur = nullptr;

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
                if(cur->next){
                    cur->next->prev = cur;
                }
                if(get == tail){
                    tail = cur;
                }
                delete get;
                get = nullptr;
            }
        }
    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {
        ///1.找到position的node
        ///2.location之后的作为新list，定义新list的头尾ptr；
        ///3.注意prev定义
        node *cur1 = head;
        while (position > 0){
            --position;
            cur1 = cur1->next;
        }
        doubly_linked_list new_list;
        new_list.head = cur1;
        new_list.tail = tail;
        tail = cur1->prev;
        if (tail){
            tail->next = nullptr;
        }
        new_list.head->prev = nullptr;
        return  new_list;
//        while (cur1->prev){
//            split1->get_data() = cur1->get_data();
//            cur1 = cur1->prev;
//            return;
//        }

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
///        1.找到两个position对应的node
///        2.创建新linkedlist然后把头尾ptr定义好
///        3.创建两个pointer来检测这个list前后是否还有数据
        node* pos_1 = head;
        node* pos_2 = head;
        while(position_1 > 0){
            --position_1;
            pos_1 = pos_1->next;
        }
        while(position_2 > 0){
            --position_2;
            pos_2 = pos_2->next;
        }
        doubly_linked_list new_list;
        new_list.head = pos_1;
        new_list.tail = pos_2;
        node* prev = pos_1->prev;
        node* next = pos_2->next;
        if(prev == nullptr){
            head = next;
        }
        if(next == nullptr){
            tail = prev;
        }
        if(prev != nullptr)///如果新list之外还有数据，就将他们组合成另一个新list
        {
            prev->next = next;
        }
        if(next != nullptr){
            next->prev = prev;
        }
        pos_1->prev = nullptr;
        pos_2->next = nullptr;
        return new_list;
    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
    ///1.找到两个position对应的node
    ///
    ///
    ///
        node* pos_1 = head;
        node* pos_2 = head;
        while(position_1 > 0){
            --position_1;
            pos_1 = pos_1->next;
        }
        while(position_2 > 0){
            --position_2;
            pos_2 = pos_2->next;
        }
        node* new_node_1 = new node(pos_2->get_data());
        node* new_node_2 = new node(pos_1->get_data());

        new_node_1->prev = pos_1->prev;
        new_node_1->next = pos_1->next;
        new_node_2->prev = pos_2->prev;
        new_node_2->next = pos_2->next;
        if(pos_1->prev)
            pos_1->prev->next = new_node_1;
        if(pos_1->next)
            pos_1->next->prev = new_node_1;
        if(pos_2->prev)
            pos_2->prev->next = new_node_2;
        if(pos_2->next)
            pos_2->next->prev = new_node_2;
        if(pos_1 == head){
            head = new_node_1;
        }
        if(pos_1 == tail){
            tail = new_node_1;
        }
        if(pos_2 == head){
            head = new_node_2;
        }
        if(pos_2 == tail){
            tail = new_node_2;
        }
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
        for(int i = 0; i+location_1_start <= location_1_end; ++i){
            swap(location_1_start + i, location_2_start + i);
        }
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
        cur = head;
        while(cur->next){
            cur->next->prev = cur;
            cur = cur->next;
        }
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        auto* output = new doubly_linked_list(*this);
        *output += rhs;
        return *output;
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
                while (RHS_tmp != nullptr)
                {
                    append(RHS_tmp->get_data());
                    RHS_tmp = RHS_tmp->next;
                }
            }
        }
        return *this;
    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
        node* cur = rhs.head;
        while(cur){
            append(cur->get_data());
            cur = cur->next;
        }
        return *this;
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
        node* r = rhs.head;
        node* c = head;
        while(r&&c){
            if(r->get_data()!=c->get_data()){
                return false;
            }
            r = r->next;
            c = c->next;
        }
        if(c && !r){
            return false;
        }
        if(!c && r){
            return false;
        }
        return true;
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
        int input;
        stream >> input;
        RHS.append(input);
        return stream;
    }
}

