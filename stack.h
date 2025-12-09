struct Stack {
    int size;
    int max_capacity  = 5 ;
    int pos_in_stack ;
    int * stack ;


    Stack(int max_capa); 
    ~Stack(){ delete [] stack;}
    void push(int n);
    int get_value(int pos) const;
    void pop();
    bool is_empty() const;
    bool is_full() const;

    void print_stack() const;
} ;