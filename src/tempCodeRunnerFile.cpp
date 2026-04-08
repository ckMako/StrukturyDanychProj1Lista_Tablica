#include "../inc/tempCodeRunnerFile.h"

// void fromFile(Interface<int>* str){
//     std::string fileName;
//     std::cout << "Podaj nazwe pliku: ";
//     std::cin >> fileName;

//    std::ifstream file(fileName);

//     if (!file.is_open()) {std::cout << "Blad: Nie udalo sie otworzyc pliku!" << std::endl;
//         return;}
//     str->clear();

//     int value;
//     while (file >> value) { 
//         str->pushBack(value);
//     }

//     file.close();
// }

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