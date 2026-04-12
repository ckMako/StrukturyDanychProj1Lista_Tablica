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
#include "../inc/tempCodeRunnerFile.h"

int main(){
    List2<int> obj;
    for(int i =0; i<20; i++) {
        obj.pushBack(rand()%100);
    }
    obj.print();
    for(int i=0; i<obj.getSize(); i++) {
        std::cout<<obj.findInd_backdoor(i)->getArg()<<std::endl;
    }
}