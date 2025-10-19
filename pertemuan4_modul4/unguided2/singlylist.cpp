#include "singlylist.h"

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

void deleteFirst(List &L, address &P){
    if (L.First != NULL){
        P = L.First;
        L.First = L.First -> next;
        P -> next = NULL;
    }else{
        P = NULL;
    }
}
void deleteLast(List &L, address &P){
    if (L.First != NULL){
        address Q = L.First;
        if(Q -> next == NULL){
            P = Q;
            L.First = NULL;
        }else{
            while (Q -> next -> next != NULL){
                Q = Q -> next;
            }
            P = Q -> next;
            Q -> next = NULL;


        }
    }else{
        P = NULL;
    }
}
void deleteAfter(List &L, address &P, address prec){
    if (prec != NULL && prec -> next != NULL){
        P = prec -> next;
        prec -> next = P -> next;
        P -> next = NULL;
    }else{
        P = NULL;
    }
}
int nbList(List L){
    int count = 0;
    address P = L.First;
    while (P != NULL){
        count++;
        P = P -> next;
    }
    return count;
}

void deleteList(List &L){
    address P;
    while (L.First != NULL){
        deleteFirst(L, P);
        //dealokasi(P);
    }
}