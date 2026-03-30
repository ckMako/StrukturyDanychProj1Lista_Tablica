#pragma once

#include "cell.h"
#include "interface.h"

template<class T>
class List1 :public Interface<T> {

    cell<T>* head;
    cell<T>* tail;
    int Rozmiar=0;

    public:
    List1(){
        head=nullptr;
        tail=nullptr;
    }

    void pushBack(T arg) override {
        cell<T>* tmp = new cell<T>(arg);
        tmp->setNext(nullptr);

        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        } else {
            tail->setNext(tmp);
            tail = tmp;
        }

        Rozmiar++;
    }

    void pushFront(T arg) {
        cell<T>* tmp =new cell<T>(arg);
        tmp->setNext(head);
        head=tmp;
        Rozmiar++;
    }

    void print() override {
        cell<T>* tmp=head;
        while(tmp!=nullptr) {
            std::cout<<tmp->getArg()<<std::endl;
            tmp=tmp->getNext();
        }
    }

    //dummies
        void pushAtIndex(int Indx,T w)override{
        
    }

        void removeAtIndex(int Indx)override{
        std::cout<<"implement "<<std::endl;
    }

    //rand values
    cell<T>* findInd(int arg) {
        cell<T>*tmp=nullptr;
        if(arg>=this->Rozmiar){
            return this->head;
        }

        tmp=this->head;
        for (int i = 0; i < arg; i++) {
            tmp = tmp->getNext();
        }

        return tmp;
    }

        T findX(int Indx)override{
        std::cout<<"implement "<<std::endl;
        T arg; return arg;
    }
        int findVal(T arg)override{
        std::cout<<"implement "<<std::endl;
        return 0;
    }


    void clear()override{};

    void removeLast(){};

    int getSize(){
        return Rozmiar;
    }
};
