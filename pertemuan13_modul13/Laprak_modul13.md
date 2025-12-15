# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Struktur data adalah cara untuk mengatur, menyimpan, dan mengelola data di dalam komputer agar data mudah diakses, diproses, dan diubah. 
Dengan struktur data, data bisa dikelola dengan lebih baik dan program berjalan lebih cepat dalam memproses informasi. Struktur data juga 
membantu memahami bagaimana data saling terhubung, sehingga memudahkan pencarian dan pengubahan data sesuai kebutuhan aplikasi. Menggunakan 
struktur data yang tepat akan membantu programmer meningkatkan kinerja aplikasi dan menghadapi masalah data yang rumit [1].

### A. Multi Linked List<br/>
Multi Linked List yang terhubung banyak terdiri dari beberapa kelompok Linked List yang berbeda, tetapi bisa diakses sekaligus. Setiap kelompok Linked List memiliki simpul-simpul yang saling terkait dalam kelompok tersebut. Tipe Linked List ini memungkinkan penyimpanan data dalam bentuk kelompok-kelompok terpisah sekaligus menjaga struktur data yang rapi dan teratur. Dengan memahami perbedaan antara berbagai jenis Linked List, kita bisa memilih struktur data yang tepat sesuai dengan kebutuhan aplikasi [2].

## Guided 

### 1. Soal guided
multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H
#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent;//alis pointer struct nodeParent
typedef struct nodeChild *NodeChild; //alis pointer struct nodeChild
struct nodeChild{ // node anak
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};
struct listAnak{ // list anka
    NodeChild first;
    NodeChild last;
};
struct nodeParent{ //node parent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};
struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};
//buat list
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//aloksi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeChild(NodeParent &nodeInduk);

//alokasi  & dealokasi anak
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

//operasi parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodeprev);

// operasi anak
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodeprev);
void findChildByID(listInduk &LInduk, string IDCari);

//oprerasi print
void printStrukturMLL(listInduk &LInduk);
#endif
```

multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu 
            
            ){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;
int main(){
    //inisiasi list
    listInduk LInduk;
    createListInduk(LInduk);

    //membuat data parent
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Desert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //masukan data child
    NodeChild M01 = alokasiNodeChild("M01", "Nasi gorenf special");
    insertLastChild(K01 -> L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam bakar madu");
    insertLastChild(K01 -> L_Anak, M02);

    //isi kagrito minun k02
    NodeChild D02 = alokasiNodeChild("D02", "Jus alpukat");
    insertLastChild(K02 -> L_Anak, D02);

    // isi kategorui desert
    NodeChild S01 = alokasiNodeChild("S01", "puding coklat");
    insertLastChild(K03 -> L_Anak, S01);
    cout << endl;

    //print mll
    printStrukturMLL(LInduk);
    cout << endl;

    //cari node child
    findChildByID(LInduk, "D01");
    cout << endl;

    //hapus node child
    deleteAfterChild(K01 -> L_Anak, M01);
    cout << endl;

    // hapus node parent
    deleteAfterParent(LInduk, K02);
    cout << endl;

    //print setelh delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
```
Program ini mengimplementasikan Multi Linked List (MLL) dengan konsep parent–child untuk memodelkan data kategori makanan (parent) dan daftar makanan (child). Struktur data terdiri dari listInduk yang menyimpan node parent bertipe doubly linked list, dan setiap node parent memiliki listAnak sendiri yang juga berupa doubly linked list untuk menyimpan node child. Program menyediakan fungsi untuk membuat list, mengalokasikan dan mendealokasikan node, menambah data parent dan child di posisi terakhir, menghapus node parent beserta seluruh child-nya, menghapus node child tertentu, mencari child berdasarkan ID di seluruh struktur, serta menampilkan seluruh isi multi linked list. Pada main(), program menginisialisasi list, menambahkan beberapa kategori makanan dan makanan ke dalamnya, menampilkan struktur data, melakukan pencarian data child berdasarkan ID, menghapus data tertentu, lalu menampilkan kembali struktur akhir untuk menunjukkan perubahan yang terjadi.


## Unguided 

### 1. Soal unguided 1
Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”,Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”.Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk
dari multi linked listnya .Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur
printMLLStructure().

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H
#include<iostream>
using namespace std;
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};
struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};
struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};
struct listChild{
    NodeChild first;
    NodeChild last;
};
struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent{
    NodeParent first;
    NodeParent last;
};
bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
#endif
```
MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent){
    return(LParent.first == nullptr && LParent.last == nullptr);
}

bool isEmptyChild(listChild &LChild){
    return(LChild.first == nullptr && LChild.last == nullptr);
}

void createListParent(listParent &LParent){
    LParent.first =  LParent.last = nullptr; 
}
void createListChild(listChild &LChild){
    LChild.first = LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = nullptr;
    nodeBaruParent->prev = nullptr;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = weight;
    nodeBaruChild->next = nullptr;
    nodeBaruChild->prev = nullptr;
    return nodeBaruChild;
}
void deallocNodeParent(NodeParent &NParent){
    if(NParent != nullptr){
        NParent -> next = NParent -> prev = nullptr;
        delete NParent;
        NParent = nullptr;
    }
}
void deallocNodeChild(NodeChild &NChild){
    if(NChild != nullptr){
        NChild -> next = NChild -> prev = nullptr;
        delete NChild;
        NChild = nullptr;
    }
}
void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent){
    if(!isEmptyParent(LParent)){
        NodeParent nodeBantu = LParent.first;
        if(LParent.first == LParent.last){
            LParent.first = LParent.last = nullptr;
        }else{
            LParent.first = nodeBantu->next;
            LParent.first->prev = nullptr;
        }
        deleteListChild(nodeBantu->L_Child);
        deallocNodeParent(nodeBantu);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev){
    if(LParent.first == nullptr){
        cout <<"List parent kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeParent nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LParent.last = NPrev;
            }
            deleteListChild(nodeHapus -> L_Child);
            deallocNodeParent(nodeHapus);
        }
        
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        newNChild->next =LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild){
    if(!isEmptyChild(LChild)){
        NodeChild nodeBantu = LChild.first;
        if(LChild.first == LChild.last){
            LChild.first = LChild.last = nullptr;
        }else{
            LChild.first = nodeBantu->next;
            LChild.first->prev = nullptr;
        }
        deallocNodeChild(nodeBantu);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev){
    if(LChild.first == nullptr){
        cout <<"List child kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeChild nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LChild.last = NPrev;
            }
            nodeHapus->next = nullptr;
            deallocNodeChild(nodeHapus);
        } 
    }
}
void printMLLStructure(listParent &LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;

        if (C == nullptr) {
            cout << "(tidak ada child)" << endl;
        } else {
            int noChild = 1;
            while (C != nullptr) {
                cout << " - Child " << noChild << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                cout << "    Ekor : " << C->isidata.ekor << endl;
                cout << "    Bobot : " << C->isidata.bobot << endl;

                C = C->next;
                noChild++;
            }
        }

        cout << "-----------------------------" << endl;
        P = P->next;
        noParent++;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)){
        deleteFirstChild(LChild);
    }
}
```
main.cpp
```C++
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent G001 = allocNodeParent("G001", "Aves");
    NodeParent G002 = allocNodeParent("G002", "Mamalia");
    NodeParent G003 = allocNodeParent("G003", "Pisces");
    NodeParent G004 = allocNodeParent("G004", "Amfibi");
    NodeParent G005 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, G001);
    insertLastParent(LParent, G002);
    insertLastParent(LParent, G003);
    insertLastParent(LParent, G004);
    insertLastParent(LParent, G005);

    insertLastChild(G001->L_Child,allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(G002->L_Child,allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G002->L_Child,allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G002->L_Child,allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G004->L_Child,allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LParent);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan13_modul13/Output_unguided1_modul13.png)

Program ini merupakan implementasi Multi Linked List (MLL) dengan konsep parent–child untuk merepresentasikan data golongan hewan (parent) dan data hewan (child). Setiap parent disimpan dalam listParent berbentuk doubly linked list, dan masing-masing parent memiliki listChild sendiri yang juga berupa doubly linked list untuk menyimpan hewan yang termasuk dalam golongan tersebut. Program menyediakan fungsi untuk membuat list, mengecek list kosong, melakukan alokasi dan dealokasi node, menambah dan menghapus data parent maupun child (di awal, akhir, atau setelah node tertentu), serta menghapus seluruh child saat parent dihapus. Pada fungsi main(), dibuat beberapa golongan hewan seperti Aves, Mamalia, dan lain-lain, kemudian dimasukkan beberapa data hewan ke masing-masing golongan. Seluruh struktur multi linked list ditampilkan menggunakan fungsi printMLLStructure.

### 2. Soal Unguided 2
Tambahkan prosedur searchHewanByEkor(input/output LParent :
listParent, input tail : Boolean) yang digunakan untuk melakukan operasi
SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan
menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil
prosedur tersebut pada main.cpp.

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H
#include<iostream>
using namespace std;
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};
struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};
struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};
struct listChild{
    NodeChild first;
    NodeChild last;
};
struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent{
    NodeParent first;
    NodeParent last;
};
bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
void searchHewanByEkor(listParent LParent, bool tail);
#endif
```

MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent){
    return(LParent.first == nullptr && LParent.last == nullptr);
}

bool isEmptyChild(listChild &LChild){
    return(LChild.first == nullptr && LChild.last == nullptr);
}

void createListParent(listParent &LParent){
    LParent.first =  LParent.last = nullptr; 
}
void createListChild(listChild &LChild){
    LChild.first = LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = nullptr;
    nodeBaruParent->prev = nullptr;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = weight;
    nodeBaruChild->next = nullptr;
    nodeBaruChild->prev = nullptr;
    return nodeBaruChild;
}
void deallocNodeParent(NodeParent &NParent){
    if(NParent != nullptr){
        NParent -> next = NParent -> prev = nullptr;
        delete NParent;
        NParent = nullptr;
    }
}
void deallocNodeChild(NodeChild &NChild){
    if(NChild != nullptr){
        NChild -> next = NChild -> prev = nullptr;
        delete NChild;
        NChild = nullptr;
    }
}
void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent){
    if(!isEmptyParent(LParent)){
        NodeParent nodeBantu = LParent.first;
        if(LParent.first == LParent.last){
            LParent.first = LParent.last = nullptr;
        }else{
            LParent.first = nodeBantu->next;
            LParent.first->prev = nullptr;
        }
        deleteListChild(nodeBantu->L_Child);
        deallocNodeParent(nodeBantu);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev){
    if(LParent.first == nullptr){
        cout <<"List parent kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeParent nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LParent.last = NPrev;
            }
            deleteListChild(nodeHapus -> L_Child);
            deallocNodeParent(nodeHapus);
        }
        
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        newNChild->next =LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild){
    if(!isEmptyChild(LChild)){
        NodeChild nodeBantu = LChild.first;
        if(LChild.first == LChild.last){
            LChild.first = LChild.last = nullptr;
        }else{
            LChild.first = nodeBantu->next;
            LChild.first->prev = nullptr;
        }
        deallocNodeChild(nodeBantu);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev){
    if(LChild.first == nullptr){
        cout <<"List child kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeChild nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LChild.last = NPrev;
            }
            nodeHapus->next = nullptr;
            deallocNodeChild(nodeHapus);
        } 
    }
}
void printMLLStructure(listParent &LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;

        if (C == nullptr) {
            cout << "(tidak ada child)" << endl;
        } else {
            int noChild = 1;
            while (C != nullptr) {
                cout << " - Child " << noChild << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                cout << "    Ekor : " << C->isidata.ekor << endl;
                cout << "    Bobot : " << C->isidata.bobot << endl;

                C = C->next;
                noChild++;
            }
        }

        cout << "-----------------------------" << endl;
        P = P->next;
        noParent++;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)){
        deleteFirstChild(LChild);
    }
}
    
    
void searchHewanByEkor(listParent LParent, bool tail) {
    NodeParent nodeBantuParent = LParent.first;
    int posisiParent = 1;

    while (nodeBantuParent != nullptr) {
        NodeChild nodeBantuChild = nodeBantuParent->L_Child.first;
        int posisiChild = 1;

        while (nodeBantuChild != nullptr) {
            if (nodeBantuChild->isidata.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent "
                     << nodeBantuParent->isidata.namaGolongan
                     << " pada posisi ke-" << posisiChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << nodeBantuChild->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posisiChild << endl;
                cout << "Nama Hewan : " << nodeBantuChild->isidata.namaHewan << endl;
                cout << "Habitat : " << nodeBantuChild->isidata.habitat << endl;
                cout << "Ekor : " << nodeBantuChild->isidata.ekor << endl;
                cout << "Bobot : " << nodeBantuChild->isidata.bobot << endl;
                cout << "-----------------------------" << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << nodeBantuParent->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posisiParent << endl;
                cout << "Nama golongan : " << nodeBantuParent->isidata.namaGolongan << endl;
                cout << "-----------------------------" << endl << endl;
            }
            nodeBantuChild = nodeBantuChild->next;
            posisiChild++;
        }

        nodeBantuParent = nodeBantuParent->next;
        posisiParent++;
    }
}

```
main.cpp
```C++
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent G001 = allocNodeParent("G001", "Aves");
    NodeParent G002 = allocNodeParent("G002", "Mamalia");
    NodeParent G003 = allocNodeParent("G003", "Pisces");
    NodeParent G004 = allocNodeParent("G004", "Amfibi");
    NodeParent G005 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, G001);
    insertLastParent(LParent, G002);
    insertLastParent(LParent, G003);
    insertLastParent(LParent, G004);
    insertLastParent(LParent, G005);

    
    insertLastChild(G001->L_Child,allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G001->L_Child,allocNodeChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(G002->L_Child,allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G002->L_Child,allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G002->L_Child,allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G004->L_Child,allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LParent);
    cout << endl;
    searchHewanByEkor(LParent, false);
    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan13_modul13/Output_unguided2_modul13.png)


Program ini mengimplementasikan Multi Linked List (MLL) dengan struktur parent–child untuk memodelkan data golongan hewan sebagai parent dan data hewan sebagai child. Setiap node parent disimpan dalam listParent berbentuk doubly linked list, dan masing-masing parent memiliki listChild sendiri yang juga berupa doubly linked list untuk menyimpan hewan yang termasuk dalam golongan tersebut. Program menyediakan operasi dasar seperti pembuatan list, pengecekan list kosong, alokasi dan dealokasi node, penambahan dan penghapusan data parent maupun child, serta penghapusan seluruh child ketika parent dihapus. Selain itu, terdapat fungsi pencetakan struktur MLL untuk menampilkan hubungan parent dan child, serta fungsi searchHewanByEkor yang menelusuri seluruh struktur untuk mencari dan menampilkan data hewan berdasarkan kondisi ekor (berekor atau tidak). Pada fungsi main(), beberapa golongan hewan dan data hewan dimasukkan ke dalam struktur, kemudian seluruh data ditampilkan dan dilakukan pencarian hewan berdasarkan atribut ekor.

### 3. Soal Unguided 3
Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list
child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan
memanggil prosedur printMLLStructure().

MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H
#include<iostream>
using namespace std;
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};
struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};
struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};
struct listChild{
    NodeChild first;
    NodeChild last;
};
struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent{
    NodeParent first;
    NodeParent last;
};
bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

#endif
```
MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent){
    return(LParent.first == nullptr && LParent.last == nullptr);
}

bool isEmptyChild(listChild &LChild){
    return(LChild.first == nullptr && LChild.last == nullptr);
}

void createListParent(listParent &LParent){
    LParent.first =  LParent.last = nullptr; 
}
void createListChild(listChild &LChild){
    LChild.first = LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = nullptr;
    nodeBaruParent->prev = nullptr;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = weight;
    nodeBaruChild->next = nullptr;
    nodeBaruChild->prev = nullptr;
    return nodeBaruChild;
}
void deallocNodeParent(NodeParent &NParent){
    if(NParent != nullptr){
        NParent -> next = NParent -> prev = nullptr;
        delete NParent;
        NParent = nullptr;
    }
}
void deallocNodeChild(NodeChild &NChild){
    if(NChild != nullptr){
        NChild -> next = NChild -> prev = nullptr;
        delete NChild;
        NChild = nullptr;
    }
}
void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent){
    if(!isEmptyParent(LParent)){
        NodeParent nodeBantu = LParent.first;
        if(LParent.first == LParent.last){
            LParent.first = LParent.last = nullptr;
        }else{
            LParent.first = nodeBantu->next;
            LParent.first->prev = nullptr;
        }
        deleteListChild(nodeBantu->L_Child);
        deallocNodeParent(nodeBantu);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev){
    if(LParent.first == nullptr){
        cout <<"List parent kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeParent nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LParent.last = NPrev;
            }
            deleteListChild(nodeHapus -> L_Child);
            deallocNodeParent(nodeHapus);
        }
        
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        newNChild->next =LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild){
    if(!isEmptyChild(LChild)){
        NodeChild nodeBantu = LChild.first;
        if(LChild.first == LChild.last){
            LChild.first = LChild.last = nullptr;
        }else{
            LChild.first = nodeBantu->next;
            LChild.first->prev = nullptr;
        }
        deallocNodeChild(nodeBantu);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev){
    if(LChild.first == nullptr){
        cout <<"List child kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeChild nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LChild.last = NPrev;
            }
            nodeHapus->next = nullptr;
            deallocNodeChild(nodeHapus);
        } 
    }
}
void printMLLStructure(listParent &LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;

        if (C == nullptr) {
            cout << "(tidak ada child)" << endl;
        } else {
            int noChild = 1;
            while (C != nullptr) {
                cout << " - Child " << noChild << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                cout << "    Ekor : " << C->isidata.ekor << endl;
                cout << "    Bobot : " << C->isidata.bobot << endl;

                C = C->next;
                noChild++;
            }
        }

        cout << "-----------------------------" << endl;
        P = P->next;
        noParent++;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)){
        deleteFirstChild(LChild);
    }
}

```
main.cpp
```C++
#include <iostream>
#include "MultiLL.h"
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);

    NodeParent G001 = allocNodeParent("G001", "Aves");
    NodeParent G002 = allocNodeParent("G002", "Mamalia");
    NodeParent G003 = allocNodeParent("G003", "Pisces");
    NodeParent G004 = allocNodeParent("G004", "Amfibi");
    NodeParent G005 = allocNodeParent("G005", "Reptil");

    insertLastParent(LParent, G001);
    insertLastParent(LParent, G002);
    insertLastParent(LParent, G003);
    insertLastParent(LParent, G004);
    insertLastParent(LParent, G005);

    insertLastChild(G001->L_Child,allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G001->L_Child,allocNodeChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(G002->L_Child,allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G002->L_Child,allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G002->L_Child,allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G004->L_Child,allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LParent);
    cout << endl;
    deleteAfterParent(LParent, G003);
    cout << endl;
    printMLLStructure(LParent);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan13_modul13/Output_unguided3_modul13.png)

Program ini merupakan implementasi Multi Linked List (MLL) dengan struktur parent–child untuk merepresentasikan data golongan hewan sebagai parent dan data hewan sebagai child. Setiap golongan hewan disimpan dalam listParent berbentuk doubly linked list, dan masing-masing parent memiliki listChild sendiri untuk menyimpan data hewan yang termasuk dalam golongan tersebut. Program menyediakan fungsi untuk membuat list, mengecek kondisi kosong, melakukan alokasi dan dealokasi node, menambah dan menghapus node parent maupun child, serta menghapus seluruh data child saat parent dihapus. Pada fungsi main(), beberapa golongan hewan dan data hewan dimasukkan ke dalam struktur, kemudian seluruh isi multi linked list ditampilkan. Selanjutnya dilakukan penghapusan node parent setelah golongan tertentu (deleteAfterParent), dan struktur list dicetak kembali untuk menunjukkan perubahan data yang terjadi.

## Kesimpulan
Struktur data merupakan cara untuk mengatur, menyimpan, dan mengelola data agar mudah diakses, diproses, serta diubah sehingga program dapat berjalan lebih efisien dan terstruktur. Pemilihan struktur data yang tepat membantu programmer memahami hubungan antar data, mempercepat proses pencarian dan pengolahan, serta menangani permasalahan data yang kompleks. Salah satu contohnya adalah Multi Linked List, yaitu struktur yang terdiri dari beberapa Linked List yang saling terhubung dan dikelompokkan, sehingga data dapat disimpan dalam kelompok-kelompok terpisah namun tetap terorganisasi dan dapat diakses secara bersamaan sesuai kebutuhan aplikasi.

## Referensi
[1] Anaraindyah, R. (2024). Struktur data: Pengertian, fungsi, dan penerapannya. Universitas Negeri Surabaya.https://share.google/kfvAZsEHXwWWO9ZVc </br>
[2] Annisa. (2025). Pengertian Linked List : Structur Data dalam Pemprograman .https://share.google/ZHwf3jDuCjJnvDri3