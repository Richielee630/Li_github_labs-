#include "../inc/tree.h"
#include <vector>
#include <iostream>

namespace lab8 {
    void clear(node *to_clear);

    // Construct an empty tree
    tree::tree() {
        root = nullptr;
        tree_size = 0;
    }

    // Copy constructor
    tree::tree(const tree &copy) {
        node* next = root;
        std::vector<node*> record;
        while(next){
            record.push_back(next);
            next = next->left;
        }
        while(record.size() > 0){
            next = record.back();
            node* cur = next;
            record.pop_back();
            delete cur;
            next = next->right;
            while(next){
                record.push_back(next);
                next = next->left;
            }
        }
        delete root;
        root = nullptr;

        if(copy.root != nullptr){
            node* copy_next = copy.root;
            std::vector<node*> copy_nodes;
            copy_nodes.push_back(copy_next);
            std::vector<node*> this_nodes;
            this_nodes.push_back(new node(copy.root));
            root = this_nodes[0];
            while(copy_next->left){
                copy_next = copy_next->left;
                copy_nodes.push_back(copy_next);
                node* newnode = new node(copy_next);
                this_nodes.back()->left = newnode;
                this_nodes.push_back(newnode);
            }
            while(copy_nodes.size() > 0){
                node* copy_next = copy_nodes.back();
                copy_nodes.pop_back();
                copy_next = copy_next->right;
                if(copy_next){
                    copy_nodes.push_back(copy_next);
                    node* newnode = new node(copy_next);
                    this_nodes.back()->right = newnode;
                    this_nodes.pop_back();
                    this_nodes.push_back(newnode);
                    while(copy_next->left){
                        copy_next = copy_next->left;
                        copy_nodes.push_back(copy_next);
                        node* newnode1 = new node(copy_next);
                        this_nodes.back()->left = newnode1;
                        this_nodes.push_back(newnode1);
                    }
                }else{
                    this_nodes.pop_back();
                }
            }
        }
    }

    // Deconstruct tree
    tree::~tree() {
        node* next = root;
        std::vector<node*> record;
        while(next){
            record.push_back(next);
            next = next->left;
        }
        while(record.size() > 0){
            next = record.back();
            node* cur = next;
            record.pop_back();
            delete cur;
            next = next->right;
            while(next){
                record.push_back(next);
                next = next->left;
            }
        }
        delete root;
        root = nullptr;
    }

    // Insert
    void tree::insert(int value) {
        if(root == nullptr){
            root = new node(value);
        }else{
            node* n = root;
            while(true){
                if(n->data == value){
                    ++n->frequency;
                    return;
                }else if(value < n->data){
                    if(n->left == nullptr){
                        node* newnode = new node(value);
                        n->left = newnode;
                        return;
                    }else{
                        n = n->left;
                    }
                }else{
                    // >
                    if(n->right == nullptr){
                        node* newnode = new node(value);
                        n->right = newnode;
                        return;
                    }else{
                        n = n->right;
                    }
                }
            }
        }

    }

    // Remove key return true if the key is deleted, and false if it isn't in the tree
    bool tree::remove(int key) {
        std::vector<node*> record;
        node* cur = root;
        node* prev = nullptr;
        while(cur){
            if(cur->data == key){
                if(cur->frequency > 0){
                    --cur->frequency;
                    return true;
                }else{
                    return false;
                }
                /*else{
                if(cur->right){
                  node* tail = cur->right;
                  while(tail->left){
                    tail = tail->left;
                  }
                  tail->left = cur->left;
                  if(prev == nullptr){
                    root = cur->right;
                  }else{
                    if(cur == prev->left){
                       prev->left = cur->right;
                    }else{
                       prev->right = cur->right;
                    }
                  }
                  delete cur;
                }else if(cur->left){
                  node* tail = cur->left;
                  if(prev == nullptr){
                    root = cur->left;
                  }else{
                    if(cur == prev->left){
                       prev->left = cur->left;
                    }else{
                       prev->right = cur->right;
                    }
                  }
                  delete cur;
                }else{
                   delete cur;
                   if(prev == nullptr){
                     root = nullptr;
                   }
                }
                return true;
               }*/
            }else if(cur->data < key){
                prev = cur;
                cur = cur->right;
            }else{
                prev = cur;
                cur = cur->left;
            }
        }
        return false;
    }

    // What level is key on?
    int tree::level(int key) {
        int level = 0;
        node* cur = root;
        while(true){
            if(cur == nullptr){
                return -1;
            }
            if(cur->data == key){
                return level;
            }else if(cur->data >key){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
            ++level;
        }
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        std::string output;
        node* cur = root;
        while(true){
            if(cur == nullptr){
                std::cout << "";
                return;
            }
            output += std::to_string(cur->data);
            if(cur->data == key){
                std::cout << output << std::endl;
                return;
            }else{
                output +=  " -> ";
                if(cur->data > key){
                    cur = cur->left;
                }else{
                    cur = cur->right;
                }
            }

        }

    }

    // Number of items in the tree
    unsigned tree::size() {
        unsigned count = 0;
        node* cur = root;
        std::vector<node*> record;
        while(cur){
            record.push_back(cur);
            count += cur->frequency;
            cur = cur->left;
        }
        while(record.size() > 0){
            cur = record.back();
            record.pop_back();
            cur = cur->right;
            while(cur){
                record.push_back(cur);
                count += cur->frequency;
                cur = cur->left;
            }
        }
        return count;
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        int max_depth = 0;
        node *cur = root;
        std::vector<node*> record;
        std::vector<int> dep;
        while(cur){
            record.push_back(cur);
            if(dep.size() > 0){
                dep.push_back(dep.back()+1);
            }else{
                dep.push_back(0);
            }
            cur = cur->left;
        }
        while(record.size() > 0){
            cur = record.back();
            record.pop_back();
            int d = dep.back();
            dep.pop_back();
            cur = cur->right;
            if(cur == nullptr){
                if(d > max_depth){
                    max_depth = d;
                }
            }
            while(cur){
                ++d;
                record.push_back(cur);
                dep.push_back(d);
                cur = cur->left;
            }
        }
        return max_depth;
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        node* cur = root;
        while(true){
            if(cur == nullptr){
                return false;
            }
            if(key == cur->data){
                if(cur->frequency > 0){
                    return true;
                }else{
                    return false;
                }
            }
            if(key < cur->data){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
        }
        return false;
    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        node* cur = root;
        while(true){
            if(cur == nullptr){
                return 0;
            }
            if(key == cur->data){
                return cur->frequency;
            }
            if(key < cur->data){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
        }
        return 0;
    }

    // Return a string of all of the elements in the tree in order
    std::string tree::to_string() {
        std::string output;
        node* cur = root;
        std::vector<node*> record;
        while(cur){
            record.push_back(cur);
            cur = cur->left;
        }
        while(record.size() > 0){
            cur = record.back();
            for(int i = 0; i < cur->frequency; ++i){
                output += std::to_string(cur->data);
                output += " ";
            }
            record.pop_back();
            cur = cur->right;
            while(cur){
                record.push_back(cur);
                cur = cur->left;
            }
        }
        return output;
    }

    //Use the to string function for the following two functions
    // Print the tree least to greatest, Include duplicates
    void tree::print() {
        std::cout << to_string() << std::endl;
    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {
        stream << RHS.to_string();
        return stream;
    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {
        node* next = root;
        std::vector<node*> record;
        while(next){
            record.push_back(next);
            next = next->left;
        }
        while(record.size() > 0){
            next = record.back();
            node* cur = next;
            record.pop_back();
            delete cur;
            next = next->right;
            while(next){
                record.push_back(next);
                next = next->left;
            }
        }
        //delete root;
        root = nullptr;

        if(rhs.root != nullptr){
            node* copy_next = rhs.root;
            std::vector<node*> copy_nodes;
            copy_nodes.push_back(copy_next);
            std::vector<node*> this_nodes;
            this_nodes.push_back(new node(rhs.root));
            root = this_nodes[0];
            while(copy_next->left){
                copy_next = copy_next->left;
                copy_nodes.push_back(copy_next);
                node* newnode = new node(copy_next);
                this_nodes.back()->left = newnode;
                this_nodes.push_back(newnode);
            }
            while(copy_nodes.size() > 0){
                copy_next = copy_nodes.back();
                copy_nodes.pop_back();
                copy_next = copy_next->right;
                if(copy_next){
                    copy_nodes.push_back(copy_next);
                    node* newnode = new node(copy_next);
                    this_nodes.back()->right = newnode;
                    this_nodes.pop_back();
                    this_nodes.push_back(newnode);
                    while(copy_next->left){
                        copy_next = copy_next->left;
                        copy_nodes.push_back(copy_next);
                        node* newnode1 = new node(copy_next);
                        this_nodes.back()->left = newnode1;
                        this_nodes.push_back(newnode1);
                    }
                }else{
                    this_nodes.pop_back();
                }
            }
        }

        return *this;
    }

    /**************************
     * Extra credit functions *
     **************************/

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {
        std::vector<int> record;
        std::vector<node*> stack;
        node* cur = root;
        while(cur){
            if(cur->data <= key){
                cur = cur->right;
            }else{
                stack.push_back(cur);
                cur = cur->left;
            }
        }
        while(stack.size() > 0){
            node* cur = stack.back();
            for(int i = 0; i < cur->frequency; ++i){
                record.push_back(cur->data);
            }
            stack.pop_back();
            cur = cur->right;
            while(cur){
                stack.push_back(cur);
                cur = cur->left;
            }
        }
        return record;
    }

    // Merge rhs into this. Demo to a TA for credit
    tree tree::operator+(const tree &rhs) const {

    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {

    }

    /*********************************************************************
     * Recursion Example                                                 *
     * Print the linked list from greatest to least using recursion      *
     *********************************************************************/

    // Auxiliary functions
    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }
}
