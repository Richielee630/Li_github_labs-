#include "queue.h"
namespace lab5{
//    queue::queue() {
//
//    }
    queue::queue() {

    }

    queue::queue(std::string &data):storage_structure(data) {

    }

    queue::queue(const queue &original) :storage_structure(original.storage_structure){
    }

    queue::~queue() {
      
    }

    queue &queue::operator=(const queue &RHS) {
        //return <#initializer#>;
        storage_structure = RHS.storage_structure;
        return *this;
    }

    bool queue::isEmpty() const {
        return storage_structure.isEmpty();
    }

    unsigned queue::queueSize() const {
        return storage_structure.listSize();
    }

    std::string queue::top() const {
        //return std::__cxx11::string();
        if(!storage_structure.isEmpty()){
          std::string top_str = const_cast<linked_list*>(&storage_structure)->get_value_at(0);
          return top_str;
        }else{
          return "";
        }
    }

    void queue::enqueue(const std::string &data) {
        storage_structure.append(data);
    }

    void queue::dequeue() {
        storage_structure.remove(0);
    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
       stream << RHS.storage_structure;
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        stream >> RHS;
        return stream;
    }
}
