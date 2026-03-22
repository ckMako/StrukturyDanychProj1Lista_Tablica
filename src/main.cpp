#include<iostream>
#include<String>
#include <fstream>
#include "../inc/Menu.hpp"
#include "../inc/Interface.h"
#include "../inc/singleLinkedList.h"
#include "../inc/ArrayList.hpp"
using namespace std;


void fromFile(Interface<int>* str);
void randomVal(Interface<int>* str);


int main(){
    bool running=true;
    Menu<int> menu;
    int structure=0;
    int action=0;
    ArrayList<int> tab;
    //List1<int> list;
    Interface<int>* str;
     
    while(running){
        menu.start();
        structure=menu.get_str();
        action=menu.get_action();
        switch(structure){
            case 1: str=&tab;break;
            //case 2: str=&list;break;
            case 3:break;
        }

       
        switch(action){
            case 1:fromFile(str);break;
            case 2:menu.add(str);break;
            case 3:menu.remove(str);break;
            case 4:menu.search(str);break;
            case 5:str->clear();break;
            case 6:randomVal(str);
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

void fromFile(Interface<int>* str){
    string fileName;
    cout << "Podaj nazwe pliku: ";
    cin >> fileName;

   ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Blad: Nie udalo sie otworzyc pliku!" << std::endl;
        return;
    }
    str->clear();

    int value;
    while (file >> value) { 
        str->pushBack(value);
    }

    file.close();
}

void randomVal(Interface<int>* str){//!!!
    int s;
    cout<<"Z ilu elementow ma sie skladac struktura? ";
    cin>>s;
    for(int i=0;i<s;i++){
        str->pushBack(i);
    }

};
