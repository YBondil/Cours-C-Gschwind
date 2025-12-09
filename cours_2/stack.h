struct IntStack {
    
    int size;
    int max_capacity  = 5 ;
    int pos_in_stack ;
    int * stack ;

    IntStack(int max_capa); 
    ~IntStack(){ delete [] stack;}

    void push(int n);
    int get_value(int pos) const;
    void pop();
    bool is_empty() const;
    bool is_full() const;

    void print_stack() const;

} ;