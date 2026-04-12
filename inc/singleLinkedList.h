#pragma once

/**
 * 
 * @param 
 * @return 
 */

#include "cell.h"
#include "interface.h"

template<class T>
class List1 :public Interface<T> {

    cell<T>* head;
    cell<T>* tail;
    unsigned int Rozmiar=0;

    public:
    List1(){
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

        if (head == nullptr) {
            //zanim dodamy dane
            head = tmp;
            tail = tmp;
        } else {
            //normalnie
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
            head=temp;
            return;
        }

        if(Indx==Rozmiar){
            cell<T>*temp=new cell<T>(arg);
            tail->setNext(temp);
            tail=temp;
            return;
        }

        cell<T>* tmp=new cell<T>(arg);
        cell<T>* ptr=this->findInd(--Indx);
        tmp->setNext(ptr->getNext());
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
        if(Indx==0) {
            cell<T>* tmp=head;

        }
        if(Rozmiar<=2){
            return;}
        
        
        cell<T>* tmp=nullptr;

        if(Indx==0){        
            tmp=head;
            head=tmp->getNext();
            delete tmp;
            Rozmiar--;
        } else {
            tmp=this->findInd(--Indx);
            cell<T>* toDelete=tmp->getNext();
            tmp->setNext(toDelete->getNext());
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
        return -1;
    }


    void clear()override{
        cell<T>* current = head;
        while(current != nullptr) {
            cell<T>* next = current->getNext();
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        Rozmiar = 0;
    };

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
    int getSize() override{
        return Rozmiar;
    }
};
