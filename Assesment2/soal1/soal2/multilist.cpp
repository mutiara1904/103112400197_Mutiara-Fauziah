#include "multilist.h"

void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

Parent* alokasiNodeParent(string id, string nama) {
    Parent *P = new Parent;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    P->firstChild = NULL;
    P->lastChild = NULL;
    return P;
}

Child* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    Child *C = new Child;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(Parent *P) {
    delete P;
}
void dealokasiNodeChild(Child *C) {
    delete C;
}

void insertFirstParent(ListParent &LP, Parent *P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(Parent *P, Child *C) {
    if (P->firstChild == NULL) {
        P->firstChild = P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

void hapusListChild(Parent *P) {
    Child *C = P->firstChild;
    while (C != NULL) {
        Child *temp = C;
        C = C->next;
        delete temp;
    }
    P->firstChild = P->lastChild = NULL;
}

void deleteAfterParent(ListParent &LP, Parent *prec) {
    if (prec != NULL && prec->next != NULL) {
        Parent *del = prec->next;
        prec->next = del->next;

        if (del->next != NULL)
            del->next->prev = prec;
        else
            LP.last = prec;

        hapusListChild(del);
        delete del;
    }
}

void searchFilmByRatingRange(ListParent LP, float min, float max) {
    Parent *P = LP.first;
    while (P != NULL) {
        Child *C = P->firstChild;
        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "Genre : " << P->namaGenre << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Rating : " << C->ratingFilm << endl;
                cout << "-------------------" << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
}

void printStrukturMLL(ListParent LP) {
    Parent *P = LP.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i++ << " ===" << endl;
        cout << "ID Genre : " << P->idGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;

        Child *C = P->firstChild;
        int j = 1;
        while (C != NULL) {
            cout << " - Child " << j++ << endl;
            cout << "   Judul : " << C->judulFilm << endl;
            C = C->next;
        }
        P = P->next;
    }
}
