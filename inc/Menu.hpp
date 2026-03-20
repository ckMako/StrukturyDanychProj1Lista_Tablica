#pragma once
#include<iostream>
#include<time.h>
#include<chrono>
#include<thread>
using namespace std::chrono_literals;

class Menu{
    private:
    int act_str_;//aktualna_struktura
    int act_action_;//aktualna_czynnosc
    public:
    Menu(){};
    ~Menu(){};
    void start(){
        int w;
        std::cout<<"Wybierz strukture: "<<std::endl<<"1) Tablica dynamiczna"<<std::endl<<"2)Lista jednokierunkowa"<<std::endl<<"3)Lista dwukierunkowa"<<std::endl;
        std::cin>>w;
        system("cls");
        znana_struktura(w);
        act_str_=w;
        
    };
    void znana_struktura(int w){
        if(w != 1 && w != 2 && w != 3){
            std::cout<<"Bledna struktura!"<<std::endl;
            start();
        }
        int o=0;
        while(o==0){
        std::cout<<"Wybierz, co chcesz zrobic:"<<std::endl<<"1)Utworzyc z danych z pliku"<<std::endl<<"2)Dodac dane recznie"<<std::endl<<"3)Usunac dane"<<std::endl;
        std::cin>>o;
        if(o != 1 && o != 2 && o != 3){
            std::cout<<"Bledna czynnosc!"<<std::endl;
            o=0;
           //std::this_thread::sleep_for(500ms);
        }
        system("cls");
        act_action_=o;

        }
         }

    int get_str(){return act_str_;}
    int get_action(){return act_action_;}   
   

};