# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Pemrograman berasal dari kata "program" yang secara umum berarti rencana atau rancangan mengenai dasar-dasar dan usaha yang akan dilakukan 
dalam berbagai bidang seperti ketatanegaraan, perekonomian, dan lainnya.Di bidang komputer, program bisa diartikan sebagai urutan perintah yang 
diberikan kepada komputer agar bisa melakukan suatu fungsi atau tugas tertentu. Aktivitas membuat program disebut sebagai memprogram.[1]

### A. Singly Linked List<br/>
Linked list adalah sejenis struktur data yang ukurannya dapat berubah. Tidak seperti array, item dalam linked list tidak semuanya disimpan di samping satu sama lain dalam memori. Sebaliknya, setiap item, yang disebut node, memiliki tautan atau penunjuk ke item berikutnya. Pengaturan ini memudahkan untuk menambah atau menghapus item dari daftar. Daftar terkait tunggal adalah jenis spesifik dari daftar terkait di mana setiap simpul hanya menunjuk ke simpul berikutnya dalam daftar. Struktur single linked list yaitu, data dan pointer(next).[2]


## Guided 

### 1. Soal guided 1

file "list.h"
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

file "list.cpp"
```C++
#include "list.h"
#include <iostream>
using namespace std;
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}
address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}
void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}
void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

```
file "main.cpp"
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini menggunakan struktur data linked list sederhana untuk menyimpan informasi mahasiswa secara dinamis. Setiap bagian data (node) berisi nama, NIM, dan umur mahasiswa serta mengarah ke bagian berikutnya. Program ini menyediakan beberapa fungsi, yaitu membuat list kosong, menambahkan node di awal, tengah, atau akhir list, serta menampilkan seluruh data dalam list. Dalam fungsi utama, lima data mahasiswa dibuat dan dimasukkan ke dalam list menggunakan fungsi-fungsi tersebut, kemudian seluruh data dalam list ditampilkan. Secara keseluruhan, program ini menunjukkan cara dasar kerja linked list dalam menambahkan dan mengelola data tanpa menggunakan array statis.

### 2. Soal guided 2

file "list.h"
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
file "list.cpp"
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) { 
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
file "main.cpp"
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini adalah contoh penggunaan struktur data linked list sederhana yang digunakan untuk menyimpan dan mengelola informasi mahasiswa secara dinamis. Setiap bagian data atau node dalam program berisi informasi seperti nama, nomor induk mahasiswa (NIM), dan usia, serta memiliki tautan ke node berikutnya. Program ini menyediakan beberapa fungsi, seperti membuat list kosong, menambahkan data di awal, tengah, atau akhir list, serta menghapus data dari posisi tertentu atau seluruh list. Pada bagian utama program, yaitu fungsi main(), dilakukan demonstrasi penambahan beberapa data mahasiswa, menampilkan seluruh data dalam list beserta jumlah node yang ada, kemudian menghapus beberapa node dan akhirnya menghapus seluruh list. Tujuan dari program ini adalah untuk menunjukkan cara kerja operasi dasar seperti insert, delete, dan traversal pada struktur data linked list.


## Unguided 

### 1. Soal unguided 1
Buat ADT singly linked list dalam file "Singlylist.h",Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file
“Singlylist.cpp”,Kemudian buat program utama didalam file “main.cpp”. 

file "Singlylist.h"
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;
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

#endif 
```
file "Singlylist.cpp"
```C++
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

```
file "main.cpp"
```C++
#include "Singlylist.h"

int main(){
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan4_modul4/Output_unguided1_modul4.png)

Program ini adalah contoh dasar penggunaan struktur data linked list satu arah. Program ini memiliki beberapa fungsi, seperti membuat list yang kosong (CreateList), menambahkan nilai di awal list (insertFirst), menampilkan semua isi list (printInfo), serta mengelola penggunaan memori dengan proses alokasi dan dealokasi. Dalam fungsi main(), program menciptakan beberapa node yang berisi angka, kemudian menambahkannya ke dalam list dan menampilkan semua nilai yang tersimpan secara berurutan. 

### 2. Soal unguided 2
Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan
jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh
node menggunakan deleteList().

file "singlylist.h"
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infotype;
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
```
file "singlylist.cpp"
```C++
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
```
file "main.cpp"
```C++
#include "singlylist.h"

int main(){
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L, P1);
    deleteLast(L,P5);

    address P;
    deleteAfter(L, P, P4);
    dealokasi(P);
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "List berhasil terhapus " << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan4_modul4/Output_unguided2_modul4.png)

Program ini adalah contoh penuh penggunaan struktur data linked list satu arah. Fungsi ini memungkinkan pengguna untuk menambahkan, menghapus, dan menampilkan elemen-elemen dalam list yang bisa tumbuh secara dinamis.Beberapa fungsi seperti insertFirst, deleteFirst, deleteLast, dan deleteAfter digunakan untuk mengubah isi dari list tersebut. Fungsi nbList berfungsi menghitung jumlah elemen dalam list, sedangkan deleteList digunakan untuk menghapus seluruh elemen dari list. Di dalam fungsi main(), program membuat beberapa elemen, menambahkannya ke dalam list, kemudian menghapus beberapa elemen dan menampilkan hasil akhirnya. 

## Kesimpulan
Pemrograman adalah proses membuat sekumpulan perintah atau instruksi agar komputer bisa melakukan tugas tertentu. Di dunia pemrograman, salah satu jenis struktur data yang sering digunakan adalah linked list. Berbeda dengan array yang ukurannya tidak bisa berubah, linked list memiliki ukuran yang bisa berubah karena setiap elemen atau node dalam linked list saling terhubung lewat pointer. Pada singly linked list khususnya, setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya. Struktur ini membuat proses menambahkan atau menghapus data dalam program menjadi lebih mudah.

## Referensi
[1]Hanief, S., Jepriana, I. W., & Kom, S. (2020). Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi.<br>
[2]Düzgün, M. T. (2024, June 9). Understanding and implementing singly linked lists in C++. Medium.https://medium.com/@togunchan/understanding-and-implementing-singly-linked-lists-in-c-2dc7aa5df07e.<br>
