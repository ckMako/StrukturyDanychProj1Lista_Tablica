#include<iostream>
#include<string>
#include <fstream>
#include "../inc/Menu.hpp"
#include "../inc/interface.h"
#include "../inc/singleLinkedList.h"
#include "../inc/doubleLinkedList.h"
#include "../inc/ArrayList.hpp"
// using namespace std;

#define PRINTF(arg) std::cout<<"Printf: "<<(arg)<<std::endl

void fromFile(Interface<int>* str);
void randomVal(Interface<int>* str);

/**
 * szybkie losowanie val do testów
 * @param str wskaznik na struct
 * @param Num liczba wartosci do push
 * @param Kernel pseudo kernel, do jakiej wartosci liczby
 * @return zapisuje na strukturze
 * 
 */
void randValFastAF(Interface<int>* str, int Num, int Kernel) {
    for(int i=0; i<Num; i++) {
        //zmienimy na cos z <random>
        str->pushBack(rand()%(Kernel+1));
    }
}

int main(){

    List2<int> Obj;
    ArrayList<int> Tab;
    // List2<ArrayList<int>> ObjGoofy; ???
    Interface<int>* struct_ptr=&Obj;
    randValFastAF(struct_ptr, 30, 100);
    struct_ptr->print();
    struct_ptr=&Tab;
    randValFastAF(struct_ptr, 30, 100);
    struct_ptr->print();




//     bool running=true;
//     Menu<int> menu;
//     int structure=0;
//     int action=0;
//     ArrayList<int> tab;
//     List1<int> list;
//     Interface<int>* str;
     
//     while(running){
//         menu.start();
//         structure=menu.get_str();
//         action=menu.get_action();
//         switch(structure){
//             case 1: str=&tab;break;
//             case 2: str=&list;break;
//             case 3:break;
//         }

       
//         switch(action){
//             case 1:fromFile(str);break;
//             case 2:menu.add(str);break;
//             case 3:menu.remove(str);break;
//             case 4:menu.search(str);break;
//             case 5:str->clear();break;
//             case 6:randomVal(str);break;
//             case 7:;
//         }

//         str->print();

//         char r;
//         cout<<"Czy chcesz kontynuowac?[t/n]";
//         cin>>r;
//         if(r=='n')running=false;
//          system("cls");
//  }

//     return 0;
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
