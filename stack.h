#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
    NodePtr top;
    int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};

Stack::Stack(){
    top = NULL;
    size = 0;
}

void Stack::push(int x){
    NodePtr new_node = new NODE(x);
    if(new_node){
        new_node->set_next(top);  // link to old top
        top = new_node;           // update top
        size++;
    }
}

int Stack::pop(){
    if(top == NULL){
        cout << "Stack underflow!" << endl;
        return -1;  // or throw error
    }

    NodePtr t = top;
    int value = t->get_value();

    top = t->get_next();  // move top to next
    delete t;             // free memory
    size--;

    return value;
}

Stack::~Stack(){
    while(top != NULL){
        pop();
    }
}

#endif
