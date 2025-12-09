struct IntStack {

    int max_capacity ;
    int size;
    int * stack ;

    IntStack(); 
    ~IntStack(){ delete [] stack;}

    void push(int n);
    int get_value(int pos) const;
    void pop();
    bool is_empty() const;
    bool is_full() const;

    void print_stack() const;

} ;