#include <iostream>

template <class T>
class cell {
    T arg;
    cell<T>* next;
    // cell* prev;

    public:

    cell(T passArg) {
        this->arg=passArg;
        this->next=NULL;
    }

    void point(cell<T>& passArg){
        this->next=passArg;
    }
};