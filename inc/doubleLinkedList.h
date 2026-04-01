#pragma once

/**
 * 
 * @param 
 * @return 
 */

#include "cell.h"
#include "interface.h"

#define PASS std::cout<<"implement"<<std::endl;

template<class T>
class List2 :public Interface<T> {

    cell<T>* head;
    cell<T>* tail;
    unsigned int Rozmiar=0;

    public:
    List2(){
        head=nullptr;
        tail=nullptr;
    }


/**
 * dodaje za tail
 * @param arg element typu template do dodania
 * @return void
 */
    void pushBack(T arg) override {
        cell<T>* tmp = new cell<T>(arg);
        tmp->setNext(nullptr);
        tmp->setPrev(nullptr);

        if (head == nullptr) {
            //zanim dodamy dane
            head = tmp;
            tail = tmp;
        } else {
            //normalnie
            tmp->setPrev(tail);
            tail->setNext(tmp);
            tail = tmp;
        }

        Rozmiar++;
    }


/**
 * Dodaje przed head
 * @param arg element do dodania
 * @return void
 */
    void pushFront(T arg) {
        cell<T>* tmp =new cell<T>(arg);
        tmp->setNext(head);
        //tmp setPrev nullptr

        if (head == nullptr) {
            //zanim dodamy dane
            head = tmp;
            tail = tmp;
        } else {
            //normalnie
            tmp->setNext(head);
            head = tmp;
        }
        head=tmp;
        Rozmiar++;
    }

/**
 * Wypisuje wszystkie wartosci w liscie
 * @param none
 * @return void
 */
    void print() override {
        cell<T>* tmp=head;
        int licznik=0;
        std::cout<<"Rozmiar tab: "<<this->getSize()<<std::endl;
        while(tmp!=nullptr) {
            std::cout<<"wartosc pod indeksem: "<<licznik<<" ";
            std::cout<<tmp->getArg()<<std::endl;
            tmp=tmp->getNext();
            licznik++;
        }
    }

/**
 * Insert at Index
 * @param Indx indeks pod którym bedzie nowy elem
 * @param w wartosc do dodania
 * @return void
 */
    void pushAtIndex(int Indx,T arg)override{
        if(Indx>Rozmiar || Indx <0) {
            std::cout<<"none"<<std::endl;
            return;}
        
        if(Indx==0){
            cell<T>*temp=new cell<T>(arg);
            temp->setNext(head);
            //prev->null
            head=temp;
            return;
        }

        if(Indx==Rozmiar){
            cell<T>*temp=new cell<T>(arg);
            tail->setNext(temp);
            temp->setPrev(tail);
            tail=temp;
            return;
        }

        cell<T>* tmp=new cell<T>(arg);
        cell<T>* ptr=this->findInd(--Indx);
        tmp->setNext(ptr->getNext());
        tmp->setPrev(ptr);
        ptr->getNext()->setPrev(tmp);
        ptr->setNext(tmp);
        Rozmiar++;


    }

/**
 * Delete at index
 * @param Indx indeks elementu do usuniecia
 * @return void
 */
    void removeAtIndex(int Indx)override{
        if(Indx>(Rozmiar-1) || Indx <0) {
            std::cout<<"none"<<std::endl;
            return;}

        if(Rozmiar<=2){
            return;}
        
        
        cell<T>* tmp=nullptr;

        if(Indx==0){        
            tmp=head;
            head=tmp->getNext();
            head->setPrev(nullptr);
            delete tmp;
            Rozmiar--;
        } else {
            tmp=this->findInd(--Indx);
            cell<T>* toDelete=tmp->getNext();
            tmp->setNext(toDelete->getNext());
            toDelete->getNext()->setPrev(tmp);
            delete toDelete;
            Rozmiar--;
        }
    
    }

    //rand values

/**
 * Znajdz element pod indeksem
 * @param arg indeks elementu
 * @return wskaźnik na element
 */
    cell<T>* findInd(int arg) {
        cell<T>*tmp=nullptr;
        if(arg>(this->Rozmiar-1) || arg<0){
            std::cout<<"Niepoprawny indeks"<<std::endl;
            return nullptr;
        }

        tmp=this->head;
        for (int i = 0; i < arg; i++) {
            tmp = tmp->getNext();
        }

        return tmp;
    }

    /**
 * finInd ale od tail
 * @param arg indeks elementu
 * @return wskaźnik na element
 */
    cell<T>* findInd_backdoor(int arg) {PASS}

    /**
 * Znajdz wartosc pod indeksem
 * @param arg indeks elementu
 * @return wartosc pod indeksem
 */
    T findX(int arg) override {
        cell<T>* tmp=nullptr;
        tmp=this->findInd(arg);
        return tmp->getArg();
    }

/**
 * znajdz element o danej wartosci
 * @param arg wartosc do znalezienia(match) template
 * @return indeks(int) argumentu
 */
    int findVal(T arg)override{
        cell<T>* tmp=head;
        int retVal=0;
        while(tmp!=nullptr){
            if(tmp->getArg()==arg){
                return retVal;
            } else {
                retVal++;
                tmp=tmp->getNext();
            }
        }
        std::cout<<"nie znaleziono val" <<std::endl;
        return 0;
    }


    void clear()override{};

    void removeLast(){
        cell<T>* tmp=findInd(Rozmiar-2);
        delete tmp->getNext();
        tmp->setNext(nullptr);
        tail=tmp;
        Rozmiar--;
    };


    /**
 * 
 * @return Rozmiar
 */
    int getSize(){
        return Rozmiar;
    }
};
