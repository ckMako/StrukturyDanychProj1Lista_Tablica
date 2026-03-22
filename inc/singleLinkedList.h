#pragma once

#include "cell.h"
#include "interface.h"

template<class T>
class List1 :public Interface<T> {

    cell<T>* head;
    //cell<T>* tail;
    int Rozmiar=0;

    public:
    List1(){
        head=nullptr;
    }

    void pushBack(T arg) override {
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
        void pushAtIndex(int Indx,int w)override{
        std::cout<<"implement "<<std::endl;
    }

        void removeAtIndex(int Indx)override{
        std::cout<<"implement "<<std::endl;
    }


    cell<T>* findInd(int arg) {
        cell<T>*tmp=nullptr;
        if(arg>=this->Rozmiar){
            return this->head;
        }

        tmp=this->head;
        for (int i=arg;i>0;i--){
            tmp=tmp->getNext();
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
