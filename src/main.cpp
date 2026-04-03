#include<iostream>
#include<string>
#include<filesystem>
#include <fstream>
#include <random>
#include <chrono>
#include "../inc/Menu.hpp"
#include "../inc/interface.h"
#include "../inc/singleLinkedList.h"
#include "../inc/doubleLinkedList.h"
#include "../inc/ArrayList.hpp"
using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;


const int count= 100;//ile tablic/list 

void fromFile(Interface<int>* str);
void randomVal100(Interface<int>* str[100], unsigned int seed); 
void randomVal(Interface<int>* str, unsigned int seed);

int main(){
    bool running=true;
    Menu<int> menu;
    int structure=0;
    int action=0;
    bool test=false;//true-działa na 100 strukturach, false-na jednej

    test=menu.test();
    
    
    ArrayList<int> tab[100];
    List1<int> list[100];
    //List2<int> list2[100];
    Interface<int>* str[100];//tablica wskaźników na 100 struktur
    
        ArrayList<int> tab_s;
        List1<int> list_s;
        //List2<int> list2_s;
        Interface<int>* str_s;//wskaźnik na pojedynczą strukturę
   
     
    while(running){
        menu.start();
        structure=menu.get_str();
        action=menu.get_action();

        if(test){
        for(int i = 0; i < 100; i++) {
            switch(structure){
                case 1: str[i] = &tab[i]; break;
                case 2: str[i] = &list[i]; break;
                //case 3: str[i] = &list2[i]; break;
            }
        }}
        else{
            switch(structure){
                case 1: str_s = &tab_s; break;
                case 2: str_s = &list_s; break;
                //case 3: str_s = &list2_s; break;
            }
        }


        if(!test){
        switch(action){
            case 1:fromFile(str_s);break;
            case 2:menu.add(str_s);break;
            case 3:menu.remove(str_s);break;
            case 4:menu.search(str_s);break;
            case 5:str_s->clear();break;
            case 6:randomVal(str_s,42);break;
            case 7: str_s->print();break;
        }
    }
        else{
            switch(action){
                case 1: 
                    for(int i = 0; i < 100; i++) fromFile(str[i]); 
                    break;
                case 2: menu.add100(str);break;
                case 3: menu.remove100(str);break; 
                case 4: 
                    for(int i = 0; i < 100; i++) menu.search(str[i]); //!!!
                    break;
                case 5: 
                    for(int i = 0; i < 100; i++) str[i]->clear(); 
                    break;
                case 6:randomVal100(str, 42); break;
                case 7:cout<<"Czynnosc niedostepna"<<endl;break;
            }
        }

        char r;
        cout<<"Czy chcesz kontynuowac?[t/n]";
        cin>>r;
        if(r=='n') running=false;
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
        return;
    }
    
    str->clear();
    int value;
    while (file >> value) { 
        str->pushBack(value);
    }

    file.close();
    cout << "Pomyslnie wczytano dane." << endl;
}


void randomVal(Interface<int>* str, unsigned int seed) {
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

    auto start = high_resolution_clock::now();

    for(int i = 0; i < size; i++) {
        int value = generatorValue() % 1000;
        str->pushBack(value);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Wypelnianie zakonczone. Czas: " << duration.count() << " us."<<endl;
}


void randomVal100(Interface<int>* str[100], unsigned int seed) {//losowe wypelnienie 100 struktur
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

    auto start = high_resolution_clock::now();

for(int s = 0; s < 100; s++) {
    if(s%10 == 0) seed*=2;//co 10 struktur wypelnienie będzie się zmieniać
        str[s]->clear(); 
        generatorValue.seed(seed); //żeby miały te same wartosci
        for(unsigned int i = 0; i < size; i++) {
            int value = generatorValue() % 1000;
            str[s]->pushBack(value);
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    
    
        cout << "Sredni czas : " << duration.count() / 100 << " us.\n";
}