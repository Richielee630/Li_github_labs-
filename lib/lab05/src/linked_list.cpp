#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    linked_list::linked_list(std::string &data) {
        head = tail = new node(data);
    }

    linked_list::linked_list(const linked_list &original) {
        if (original.head != nullptr)
        {
            node *original_tmp = original.head;
            node *tmp = head = new node(original_tmp->data);
            //size = original.size;

            original_tmp = original_tmp->next;
            while (original_tmp != nullptr)
            {
                tmp->next = new node(original_tmp->data);
                tmp = tmp->next;
                tail = tmp;
                original_tmp = original_tmp->next;
            }
        }
        else
        {
            head = nullptr;
            tail = nullptr;
            //size = 0;
        }
    }

    linked_list::~linked_list(){
        while (head != nullptr){
            node *tmp = head;

        }
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        if (this != &RHS)
        {
            if (head != nullptr)
                delete this;
            if (RHS.head != nullptr)
            {
                node *RHS_tmp = RHS.head;
                node *tmp = head = new node(RHS_tmp->data);
                //size = RHS.size;
                RHS_tmp = RHS_tmp->next;
                while (RHS_tmp != nullptr)
                {
                    tmp->next = new node(RHS_tmp->data);
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


    bool linked_list::isEmpty() const {
        return false;
    }

    unsigned linked_list::listSize() const {
        int c = 0;
        node *tmp = head;
        while (tmp != nullptr){
            c++;
            tmp = tmp->next;
        }
        return 0;
    }

    void linked_list::insert(const std::string input, unsigned int location) {

    }

    void linked_list::append(const std::string input) {

    }

    void linked_list::remove(unsigned location) {

    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        return stream;
    }

    void linked_list::sort() {

    }

    std::string linked_list::get_value_at(unsigned location) {

    }
}