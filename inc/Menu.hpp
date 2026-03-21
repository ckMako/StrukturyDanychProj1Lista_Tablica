#pragma once
#include"Interface.h"
#include<iostream>
#include<time.h>
#include<chrono>
#include<thread>
using namespace std;
using namespace  chrono_literals;

template<class T>
class Menu{
    private:
    int act_str_;//aktualna_struktura
    int act_action_;//aktualna_czynnosc
    public:
    Menu(){};
    ~Menu(){};
    void start(){
        int w;
        cout<<"Wybierz strukture: "<<endl<<"1) Tablica dynamiczna"<<endl<<"2)Lista jednokierunkowa"<<endl<<"3)Lista dwukierunkowa"<<endl;
        cin>>w;
        system("cls");
        znana_struktura(w);
        act_str_=w;
        
    };
    void znana_struktura(int w){
        if(w != 1 && w != 2 && w != 3){
             cout<<"Bledna struktura!"<< endl;
            start();
        }
        int o=0;
        while(o==0){
         cout<<"Wybierz, co chcesz zrobic:"<< endl<<"1)Utworzyc z danych z pliku"<< endl<<"2)Dodac dane recznie"<< endl<<"3)Usunac dane"<< endl<<"4)Wyszukac"<< endl<<"5)Wyczyscic"<<endl<<"6)Utworzyc losowo"<<endl;
         cin>>o;
        if(o != 1 && o != 2 && o != 3 && o != 4 && o!=5&& o!=6){
             cout<<"Bledna czynnosc!"<< endl;
            o=0;
           // this_thread::sleep_for(500ms);
        }
        system("cls");
        act_action_=o;

        }
         }

    void search(Interface<T>* str){
    T val;
    int i, o;
     cout<<"Chcesz wyszukac po indeksie(1) czy po wartosci(2)?";
    cin>>o;
    switch (o){
        case 1:{cout<<"Podaj indeks: ";
            cin>>i;
            val=str-> findX(i);break;}
        case 2:{cout<<"Podaj wartosc: ";
            cin>>val;
            i=str-> findVal(val);break;}
       
        default: cout<<"Bledna czynnosc! ";break;    
    }
    if(i==-1)cout<<"Brak podanej wartosci "<<endl;return;
    cout<<endl<<"Dla indeksu "<<i<<"wartosc wynosi "<<val<<endl;
}  

    int get_str(){return act_str_;}
    int get_action(){return act_action_;}  
    
    

    void remove(Interface<int>* str){
    int i,o;
    cout<<"Chcesz usunac na poczatku(1), na koncu(2), czy w danym indeksie(3)?"<<endl;
    cin>>o;
        switch (o){
        case 1:str->removeAtIndex(0);break;    
        case 2:str->removeLast();break;
        case 3:{cout<<"Podaj indeks: ";
            cin>>i;
            str->removeAtIndex(i);break;}
        default: cout<<"Bledna czynnosc! ";break;    
    }
}

void add(Interface<int>* str){
    int i,w,o;
    cout<<"Jaka wartosc chcesz dodac?"<<endl;
    cin>>w;
    cout<<"Chcesz dodac na poczatku(1), na koncu(2), czy w danym indeksie(3)?"<<endl;
    cin>>o;
    switch (o){
        case 1:str->pushAtIndex(0,w);break;
        case 2:str->pushBack(w);break;
        case 3:{cout<<"Podaj indeks: ";
            cin>>i;
            str->pushAtIndex(i,w);break;}
        default: cout<<"Bledna czynnosc! ";break;    
    }
}

   

};