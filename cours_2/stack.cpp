#include <iostream>
#include "stack.h"

IntStack::IntStack() : size(0), max_capacity(2) {
    stack = new int[max_capacity] ; 
}

void IntStack::push(int n){
    if (is_full()){

        max_capacity *= 2;
        int* new_stack = new int[max_capacity];
        std::copy(stack, stack + size, new_stack); 
        delete[] stack;

        stack = new_stack;
        std::cout <<"Max capacity reached, new capacity : "<< max_capacity << "." << std::endl ;

    }

    //std::cout << n << " is pushed." << std::endl;
    size ++;
    stack[ size - 1 ] = n ;

    return ;
};
int IntStack::get_value(int pos) const{
    if(pos > 0 || abs(pos) >= size){
        std::cerr<<"Out of range"<<std::endl ;
        return 0;
    }
    return stack[ size + pos - 1 ] ;
};

void IntStack::pop(){
    if (is_empty())
    {
        std::cerr << "Empty stack" << std::endl ;
    } else 
    {   
        std::cout << "Top value popped. " << std::endl;
        size -- ;
    }
    return ;
};

bool IntStack::is_empty() const{
    return size == 0 ;
};  

bool IntStack::is_full() const{
    return size == max_capacity  ;
};

void IntStack::print_stack() const{
    std::cout << "--- IntStack Contents (Top to Bottom) ---" << std::endl;
    // Loop from i=0 (Top) to size-1 (Bottom)
    for (int i=0; i<size; i++){
        // Calculate the index by starting at the top (pos_in_stack) and moving back i steps
        int index = size - i - 1 ;
        std::cout << stack[index] << std::endl ;
    }
    std::cout << "--------------------------------------" << std::endl << std::endl ;
};


int main(){

    IntStack pile = IntStack();
    for (int i = 0; i<265; i++){
        pile.push(i);
    }
    pile.print_stack();

    return 0;
}
