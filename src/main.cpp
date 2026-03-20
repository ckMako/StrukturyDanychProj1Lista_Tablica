#include "../inc/singleLinkedList.h"
#include<iostream>
#include<String>
#include "../inc/Menu.hpp"
#include "../inc/Interface.h"
#include "../inc/ArrayList.hpp"
using namespace std;

void dodawanie(Interface<int>* str){
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

void usuwanie(Interface<int>* str){
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

int main(){
    bool running=true;
    Menu menu;
    int structure=0;
    int action=0;
    ArrayList<int> tab;
    List1<int> list;
    Interface<int>* str;
     
    while(running){
        menu.start();
        structure=menu.get_str();
        action=menu.get_action();
        switch(structure){
            case 1: str=&tab;break;
            case 2: str=&list;break;
            case 3:break;
        }

        for(int i=0;i<10;i++){
            str->pushBack(i);
        }
        switch(action){
            case 1:break;
            case 2:dodawanie(str);break;
            case 3:usuwanie(str);break;
        }

        str->print();

        char r;
        cout<<"Czy chcesz kontynuowac?[t/n]";
        cin>>r;
        if(r=='n')running=false;
         system("cls");
 }

    return 0;
}

