#include <linked_list.h>

namespace lab5 {
    linked_list::linked_list()
    {
        //create a empty header node
        head = nullptr;
        tail = nullptr;
    }

    linked_list::linked_list(std::string &data) {
        //construct linked_list from raw data, you need to parse the data to tokens using the way for lab01
        node* newnode = new node(data); 
        head = newnode;
        tail = head;
    }

    linked_list::linked_list(const linked_list &original) {
        head = nullptr;
        tail = nullptr;
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
    }

    linked_list::~linked_list(){
        node *next = head;
        while (next) {
            node *kill = next;
            next = next->next;
            delete kill;
        }
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        if (this != &RHS)
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
        if (head == nullptr){
          return true;
        }
        return false;
    }

    unsigned linked_list::listSize() const {
//        int c = 0;
//        node *tmp = head;
//        while (tmp != nullptr){
//            c++;
//            tmp = tmp->next;
//        }
//        return c;
        int count = 0;
        node* current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void linked_list::insert(const std::string input, unsigned int location) {
        //we assume the location is valid 
        node* newnode = new node(input);
        if(location == 0){
          newnode->next = head;
          head = newnode;
          if(tail == nullptr){
            tail = head;
          } 
        }else{
          node* cur = head;
          while(location > 1){
            --location;
            cur = cur->next;
          } 
          newnode->next = cur->next;
          cur->next = newnode;
        }
        /*
        if (isEmpty()) {
            node *n = new node;
            n->next = NULL;
            n->element = T;
            if (head != NULL) {
                tail = head;
                while (tail->next != NULL) {
                    tmp = tail;
                    tail = tail->next;
                }
                tail->next = n;
            }
            else {
                head = n;
            }
            size++;
            sortList();
        }*/
    }

    void linked_list::append(const std::string input) {
      node* newnode = new node(input);
      if(tail == nullptr){
        head = newnode;
        tail = head; 
      }else{
        tail->next = newnode;
        tail = newnode;  
      }
    }

    void linked_list::remove(unsigned location) {
        if(location == 0){
          node* cur = head;
          if(cur){
            head = head->next;
            if(head == nullptr){
              tail = head;
            } 
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
            delete get;
            get = nullptr; 
          }
        }
        /*
        tail = head;

        while ((tail != NULL) && (tail->element != T)) {
            tmp = tail;x
            tail = tail->next;
        }
        tail = tail->next;
        tmp->next = tail; s
        */
    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        node* cur = RHS.head;
        while(cur){
         stream << cur->data << " -> ";
         cur = cur->next; 
        } 
        stream << "NULL";
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        std::string input;
        stream >> input;
        RHS.append(input);         
        return stream;
    }

    void linked_list::sort() {
       if(head == nullptr){
         return;
       }
       node* prev = head;
       node* cur = head->next;
       while(cur){
         node* next = cur->next;
         node* loop = head;
         if(cur->data <= loop->data){
           cur->next = loop;
           head = cur;
           prev->next = next;
           cur = next;
         }else{
           node* loop_next = head->next;
           while(loop_next!=cur){
             if(cur->data <= loop_next->data){
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

    std::string linked_list::get_value_at(unsigned location) {
       node* cur = head;
       while(location > 0){
         cur = cur->next;
         --location; 
       }
       if(cur)
         return cur->data;
       return "";
    }
}
