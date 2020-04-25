#include "doubly_linked_list.h"

namespace lab6 {
    // Auxiliary Functions
    unsigned partititon(int* to_sort, int low, int high);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(int* to_sort, int low, int high){
        if(high <= low){
            return;
        }
        int part = partititon(to_sort,low,high);
        quicksort(to_sort,low,part-1);
        quicksort(to_sort,part+1,high);
    }

    unsigned partititon(int* to_sort, int low, int high){
        int mid = low +((high-low) >> 1);
        int pivot = to_sort[mid];
        int left = low;
        int right = high;
        int tr = left;
        while(tr<right){
            if(to_sort[tr] < pivot){
                std::swap(to_sort[left],to_sort[tr]);
                ++left;
                ++tr;
            }else if(to_sort[tr] > pivot){
                std::swap(to_sort[tr],to_sort[right]);
                --right;
            }else{
                ++tr;
            }
        }
        return left;
    }

    void mergesort(doubly_linked_list& to_sort){
        to_sort = recursive_merge_sort(to_sort);
    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort){
        int size = to_sort.size();
        if(size <= 1){
            return to_sort;
        }
        int split = size/2;
        doubly_linked_list another = to_sort.split(split);
        to_sort = recursive_merge_sort(to_sort);
        another = recursive_merge_sort(another);
        return merge(to_sort,another);
    }

    //Used for the merging the two lists
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right){
        doubly_linked_list newlist;
        while(!left.is_empty()&&!right.is_empty()){
            if(left.get_data(0) <= right.get_data(0)){
                newlist.append(left.get_data(0));
                left.remove(0);
            }else{
                newlist.append(left.get_data(0));
                right.remove(0);
            }
        }
        while(!left.is_empty()){
            newlist.append(left.get_data(0));
            left.remove(0);
        }
        while(!right.is_empty()){
            newlist.append(right.get_data(0));
            right.remove(0);
        }
        return newlist;
    }
}
