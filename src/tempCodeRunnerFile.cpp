void fromFile(Interface<int>* str){
    string fileName;
    cout << "Podaj nazwe pliku: ";
    cin >> fileName;

   ifstream file(fileName);

    if (!file.is_open()) {cout << "Blad: Nie udalo sie otworzyc pliku!" << std::endl;
        return;}
    str->clear();

    int value;
    while (file >> value) { 
        str->pushBack(value);
    }

    file.close();
}
