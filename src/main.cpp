#include "singleLinkedList.h"

int main() {
    List1<int> Obj;

    for (int i = 0; i <= 10; ++i) {
        Obj.pushBack(i);
    }

    std::cout << "Zawartosc listy: " << std::endl;
    Obj.print();

    return 0;
}