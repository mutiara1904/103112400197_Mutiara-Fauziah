#include "Singlylist.h"

void CreateList(List &L){
    L.First = NULL;
}
address alokasi (infotype X){
    address P = new ElmList;
    if (P != NULL){
        P -> info = X;
        P -> next = NULL;
    }
    return P;
}
void dealokasi (address &P){
    delete P;
    P = NULL;
}
void printInfo(List L){
    address P = L.First;
    while(P != NULL){
        cout << P -> info << " ";
        P = P -> next;

    }
    cout << endl;
}
void insertFirst (List &L, address P){
    P -> next = L.First;
    L.First = P;
}

