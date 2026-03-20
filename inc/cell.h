#pragma once

#include"interface.h"

template <class T>
class cell {
    T arg;
    cell<T>* next;
    // cell* prev;

    public:

    cell(T passArg) {
        this->arg=passArg;
        this->next=nullptr;
    }

    T getArg() {
        return arg;
    }

    void setArg(T arg){
        this->arg=arg;
    }

    cell<T>* getNext() { 
        return next; 
    }

    void setNext(cell<T>* arg){
        this->next=arg;
    }
};