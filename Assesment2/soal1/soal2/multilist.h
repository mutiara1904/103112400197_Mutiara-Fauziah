#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
#include <string>
using namespace std;

struct Child {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    Child *next;
    Child *prev;
};

struct Parent {
    string idGenre;
    string namaGenre;
    Parent *next;
    Parent *prev;
    Child *firstChild;
    Child *lastChild;
};

struct ListParent {
    Parent *first;
    Parent *last;
};

void createListParent(ListParent &LP);
Parent* alokasiNodeParent(string idGenre, string namaGenre);
Child* alokasiNodeChild(string idFilm, string judulFilm,
                        int durasi, int tahun, float rating);

void dealokasiNodeParent(Parent *P);
void dealokasiNodeChild(Child *C);
void insertFirstParent(ListParent &LP, Parent *P);
void insertLastChild(Parent *P, Child *C);
void deleteAfterParent(ListParent &LP, Parent *prec);
void hapusListChild(Parent *P);
void searchFilmByRatingRange(ListParent LP, float min, float max);
void printStrukturMLL(ListParent LP);

#endif
