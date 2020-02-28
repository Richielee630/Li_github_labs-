#include "stack.h"
namespace lab5{
    stack::stack():storage_structure() {
   
    }

    stack::stack(std::string &data):storage_structure(data) {

    }

    stack::stack(const stack &original):storage_structure(original.storage_structure) {

    }

    stack::~stack() {

    }

    stack &stack::operator=(const stack &RHS) {
        //return <#initializer#>;
        storage_structure = RHS.storage_structure;
        return *this;
    }

    bool stack::isEmpty() const {
        return storage_structure.isEmpty();
    }

    unsigned stack::stackSize() const {
        return storage_structure.listSize();
    }

    std::string stack::top() const {
        //return std::__cxx11::string();
        int size = storage_structure.listSize();
        if(size > 0){
          return const_cast<linked_list*>(&storage_structure)->get_value_at(size-1); 
        }else{
          return "";
        }
    }

    void stack::push(const std::string &data) {
      storage_structure.append(data);
    }

    void stack::pop() {
     int size = stackSize();
     if (size == 0)
       return;
     storage_structure.remove(stackSize()-1);
    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {
        int size = RHS.stackSize();
        if (size > 0){
          while(size > 0){
            stream << RHS.storage_structure.get_value_at(size-1);
            --size;
          }
        }
        return stream;
    }

    std::istream& operator>>(std::istream &stream, stack &RHS) {
        return stream;
    }
}
