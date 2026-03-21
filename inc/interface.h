#pragma once

#include<iostream>

//mozemy uzyc bo moze przyda sie polimorfizm, ale mozemy tez wywalic
template<class T> //mozna ew zrobic na int czy cos
class Interface {
   

    public:
        //w sm nie wiem czy trzeba destruktor
        virtual ~Interface() {}

        //dodaj element na poczatek/koniec struktury
        virtual void pushBack(T arg)=0;
        
        //dodaj element w danym miejscu
        virtual void pushAtIndex(int Indx, T arg)=0;

        //usun element o zadanym indexie
        virtual void removeAtIndex(int Indx)=0;

        //usun ostatni
        virtual void removeLast()=0;

        //znajdz element o danym ineksie
        //zwraca pointer na ten element+ moze pointer na poprzedni elem??
        //nie wiem czy w interface bo wartosci przechowywane mozemy zrobic jako template<class>
         virtual T findX(int Indx)=0;


        //znajdz element o danej WARTOSCI a nie element numer 1500100900
        //zwraca index tego elementu, ale pointer moze byc szybszy
        virtual int findVal(T arg)=0;

        //wypisz elementy(bardziej do testow)
        virtual void print()=0;

        //usuniecie wszystkiego
        virtual void clear()=0;
};