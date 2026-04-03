#pragma once
#include<iostream>
#include "interface.h"


template<class T>
class ArrayList :public Interface<T> {

    private:
    int count_;//zajete w tablicy
    int size_;//rozmiar tablicy
    T* ptr_;//zerowy element tablicy

    public:
    ArrayList(){
    count_=0;
    size_=10;
    ptr_=new T[size_];
    }

    ~ArrayList() {
        delete[] ptr_;
    }

    void resize() {//zwiększa rozmiar *2
        size_ *= 2;                  
        T* newPtr = new T[size_];

        for (int i = 0; i < count_; i++) {
            newPtr[i] = ptr_[i];}

        delete[] ptr_;                  
        ptr_=newPtr;                 
    }

    void resize_s() {//zmniejsza rozmiar /2
        size_ /= 2;                  
        T* newPtr = new T[size_];

        for (int i = 0; i < count_; i++) {
            newPtr[i] = ptr_[i];}

        delete[] ptr_;                  
        ptr_=newPtr;                 
    }

    void pushBack(T arg) override {
       if(size_==count_) resize();
       ptr_[count_] = arg;
       count_++;
    }

    void pushAtIndex(int Indx, T arg)override{
        if(Indx<0||Indx>=count_){std::cout<<"Bledny indeks!";return;}
        if(size_==count_) resize();
       for (int i = count_; i > Indx; i--) {
        ptr_[i] = ptr_[i - 1]; 
    }
    ptr_[Indx] = arg;
    count_++;
    }


    void removeAtIndex(int Indx)override{
        if(Indx<0||Indx>=count_){std::cout<<"Bledny indeks!";return;}
        if(count_==0){std::cout<<"Nie ma czego usuwac";return;}
        for(int i=Indx;i<count_;i++){
            ptr_[i] = ptr_[i + 1]; 
        }

        count_--;
        if(count_==size_/2)resize_s();

    }

    void removeLast()override{
        if(count_==0){std::cout<<"Nie ma czego usuwac";return;}
        count_--;
        if(count_==size_/2)resize_s();

    }

     void print()override {  
        for(int i=0;i<count_;i++) std::cout<<ptr_[i]<<" ";
       
        std::cout<<std::endl<<size_<<std::endl;}

    int findVal(T arg) override {
        
        for (int i = 0; i < count_; i++) {
            if (ptr_[i] == arg) {
                return i;
            }
    }
    return -1; 
}

        T findX(int Indx) {
        if (Indx < 0 || Indx >= count_) {
        std::cout << "Indeks poza zakresem!" << std::endl;
        return T(); //s
    }
    return ptr_[Indx];
}

void clear() override {
    delete[] ptr_;         
    size_ = 10;             
    count_ = 0;             
    ptr_ = new T[size_];   
}
};