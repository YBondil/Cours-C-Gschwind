#include <iostream>
#include "stack.h"

IntStack::IntStack(int capa) : max_capacity(capa), size(0), pos_in_stack(-1){
    stack = new int[capa] ; 
}

void IntStack::push(int n){
    if (is_full()){
        std::cerr << "full stack" << std::endl ;
    } else 
    {
        std::cout << n << " is pushed." << std::endl;

        pos_in_stack = (pos_in_stack+1) % max_capacity;
        size ++;

        stack[pos_in_stack] = n ;
    }
    return ;
};
int IntStack::get_value(int pos) const{
    if(pos > 0 || abs(pos) >= size){
        std::cerr<<"Out of range"<<std::endl ;
        return 0;
    }
    return stack[(pos_in_stack + pos+max_capacity) % max_capacity] ;
};

void IntStack::pop(){
    if (is_empty())
    {
        std::cerr << "Empty stack" << std::endl ;
    } else 
    {   
        std::cout << "value popped " << std::endl;

        pos_in_stack = (pos_in_stack-1+max_capacity) % max_capacity;
        size -- ;
    }
    return ;
};

bool IntStack::is_empty() const{
    return size == 0 ;
};  

bool IntStack::is_full() const{
    return max_capacity == size ;
};

void IntStack::print_stack() const{
    std::cout << "--- IntStack Contents (Top to Bottom) ---" << std::endl;
    // Loop from i=0 (Top) to size-1 (Bottom)
    for (int i=0; i<size; i++){
        // Calculate the index by starting at the top (pos_in_stack) and moving back i steps
        int index = (pos_in_stack - i + max_capacity) % max_capacity;
        std::cout << stack[index] << std::endl ;
    }
    std::cout << "--------------------------------------" << std::endl;
};


int main(){

    IntStack pile = IntStack(5);
    pile.push(4);
    pile.push(5);
    pile.push(2);
    pile.push(3);
    pile.push(9);
    pile.push(10);
    pile.print_stack();
    pile.pop();
    pile.get_value(3);
    pile.print_stack();

    return 0;
}
