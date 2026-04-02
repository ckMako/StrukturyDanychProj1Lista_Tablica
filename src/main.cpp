#include<iostream>
#include<string>
#include<filesystem>
#include <fstream>
#include <random>
#include <chrono>
#include "../inc/Menu.hpp"
#include "../inc/Interface.h"
#include "../inc/singleLinkedList.h"
#include "../inc/doubleLinkedList.h"
#include "../inc/ArrayList.hpp"
using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;


void fromFile(Interface<int>* str);
void randomVal(Interface<int>* str, unsigned int seed);


int main(){
    bool running=true;
    Menu<int> menu;
    int structure=0;
    int action=0;
    ArrayList<int> tab;
    List1<int> list;
    //List2<int> list2;
    Interface<int>* str;
     
    while(running){
        menu.start();
        structure=menu.get_str();
        action=menu.get_action();
        switch(structure){
            case 1: str=&tab;break;
            case 2: str=&list;break;
            //case 3:str=&list2;break;
        }

       
        switch(action){
            case 1:fromFile(str);break;
            case 2:menu.add(str);break;
            case 3:menu.remove(str);break;
            case 4:menu.search(str);break;
            case 5:str->clear();break;
            case 6:randomVal(str,42);break;
            case 7: str->print();break;
        }


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
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, fileName);

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Blad: Nie udalo sie otworzyc pliku: " << fileName << endl;
        return;}
    
    str->clear();
    int value;
    while (file >> value) { 
        str->pushBack(value);
    }

    file.close();
    cout << "Pomyslnie wczytano dane." << endl;
}

void randomVal(Interface<int>* str, unsigned int seed) {
    mt19937 generatorID(seed);     
    mt19937 generatorValue(seed);
    
    unsigned int size;

     bool success = false;

    while (!success) {
        try {cout<<"Z ilu elementow ma sie skladac tablica?: ";
            if (!(cin >> size)) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                throw std::invalid_argument("Blad: To nie jest liczba calkowita!");
            }
            success = true;

        } catch (const std::invalid_argument& e) {
            system("cls");
            cout << e.what() << endl << endl;
        }
    }
    unsigned int id = generatorID() % size;
    int example;

    auto start = high_resolution_clock::now();

    for(int i = 0; i < size; i++) {
        int value = generatorValue() % 1000;
        str->pushBack(value);
        if(i==id) example=value;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Wypelnianie zakonczone. Czas: " << duration.count() << " us.\nPrzykladowa wartosc: "<<example <<endl;
}


