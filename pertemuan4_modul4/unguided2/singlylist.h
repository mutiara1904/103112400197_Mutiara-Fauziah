#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;
//typedef ElmList* address;

struct ElmList{
   infotype info;
   ElmList* next;
};

typedef ElmList* address;

struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype X);
void dealokasi (address &P);
void printInfo (List L);
void insertFirst (List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address prec);
int nbList(List L);
void deleteList(List &L);

#endif 