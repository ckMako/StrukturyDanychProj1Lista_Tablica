#include "cell.h"

template<class T>
class List1 {
    cell<T>* head;
    int Rozmiar=0;

    public:

    void addCell(T arg) {
        cell<T>* tmp=new cell<T>(arg)
        *tmp->point(head);
        head = tmp;
        delete tmp;
        Rozmiar ++;
    }

    // void add_num(int num) {
    //     for (int i=num; i<=0; i--;) {
    //         nothng
    //     }
    // }
};
