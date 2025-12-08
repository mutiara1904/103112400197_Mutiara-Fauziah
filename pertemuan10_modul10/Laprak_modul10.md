# <h1 align="center">Laporan Praktikum Modul 10 - TREE(Bagian Pertama)</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Multi Linked List yang terhubung banyak terdiri dari beberapa kelompok Linked List yang berbeda, tetapi bisa diakses sekaligus. Setiap kelompok Linked List memiliki simpul-simpul yang saling terkait dalam kelompok tersebut. Tipe Linked List ini memungkinkan penyimpanan data dalam bentuk kelompok-kelompok terpisah sekaligus menjaga struktur data yang rapi dan teratur. Dengan memahami perbedaan antara berbagai jenis Linked List, kita bisa memilih struktur data yang tepat sesuai dengan kebutuhan aplikasi [1].

### A. Tree<br/>
Tree merupakan bentuk struktur data yang membentuk hierarki melalui hubungan antar simpul (node) yang terhubung oleh jalur (edge). Dimulai dari simpul utama yang disebut root, setiap node bisa memiliki satu atau lebih node turunan (child), sedangkan node yang tidak memiliki turunan disebut sebagai daun (leaf) [2].

### B. Rekursif<br/>
Algoritma rekursif adalah jenis algoritma yang memungkinkan sebuah fungsi atau prosedur untuk memanggil dirinya sendiri dengan input yang semakin menyempit [3].

## Guided 

### 1. Soal guided 1
file BST1.h
```C++
#ifndef BST1_H
#define BST1_H
#include<iostream>
using namespace std;
typedef int infotype; // alias infotypen untk dta int
typedef struct Node* address; // alias adres sbgi pointer
struct Node{
    infotype info; // info data yg disimpan dismona (int)
    address left; // pointer left
    address right;// pointer right
};
bool isEmpty(address root);//
void createTree(address &root);// fungsi untuk mdmnuat  bst root do set null
address newNode(infotype x); //untuk memasukan data(infotype) ke dalam node
address insertNode(address root, infotype x);//untuk memasukan node ke dalam BST
//travesal
void preOrder(address root); // secara preorder tengan - kiri - kanan
void inOrder(address root); //kiri - tengah - kanan
void postOrder(address root); // kiri - kanan - tengah

int countNodes(address root);//untuk menghitung size jumlah node yang ada di tree
int treeDepth(address root);// 

#endif
```
file BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
file main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini merupakan implementasi struktur data Binary Search Tree (BST) .Program mendefinisikan struktur Node yang menyimpan data bertipe int serta dua pointer untuk anak kiri dan kanan. isEmpty() untuk mengecek apakah tree kosong, createTree() untuk menginisialisasi root menjadi NULL, serta newNode() dan insertNode() untuk membuat node baru dan memasukkannya ke dalam BST sesuai aturan (nilai lebih kecil ke kiri, lebih besar ke kanan). Programmenyediakan tiga metode traversal: inOrder, preOrder, dan postOrder, masing-masing menampilkan isi tree dengan urutan berbeda.Fungsi countNodes() untuk menghitung jumlah node dalam tree dan treeDepth() untuk menghitung kedalaman tree. Pada fungsi main, tree dibuat terlebih dahulu, kemudian beberapa nilai dimasukkan ke BST. Setelah itu, program menampilkan hasil traversal, jumlah node, dan kedalaman tree. 

### 2. soal guided 2

file BST2.h
```C++
#ifndef BST2_H
#define BST2_H
#include<iostream>
using namespace std;
typedef int infotype; // alias infotypen untk dta int
typedef struct Node* address; // alias adres sbgi pointer
struct Node{
    infotype info; // info data yg disimpan dismona (int)
    address left; // pointer left
    address right;// pointer right
};
bool isEmpty(address root);//
void createTree(address &root);// fungsi untuk mdmnuat  bst root do set null
address newNode(infotype x); //untuk memasukan data(infotype) ke dalam node
address insertNode(address root, infotype x);//untuk memasukan node ke dalam BST
//travesal
void preOrder(address root); // secara preorder tengan - kiri - kanan
void inOrder(address root); //kiri - tengah - kanan
void postOrder(address root); // kiri - kanan - tengah

int countNodes(address root);//untuk menghitung size jumlah node yang ada di tree
int treeDepth(address root);//

//fungsi tambahan
//search
void searchByData(address root, infotype x);

//mostleft dan righrleft
address mostLeft(address root);//menmapilkan mostleft/paling kiti
address mostRight(address root);// menmapilkan paling kanan

//delete
bool deleteNode(address &root, infotype x); // mennghapus node tertentu di dalam BST
void deleteTree(address &root);//proeedur untuk menghapus BSt(hapus seluruh node)

#endif

```
file BST2.cpp
```C++
#ifndef BST2_H
#define BST2_H
#include<iostream>
using namespace std;
typedef int infotype; // alias infotypen untk dta int
typedef struct Node* address; // alias adres sbgi pointer
struct Node{
    infotype info; // info data yg disimpan dismona (int)
    address left; // pointer left
    address right;// pointer right
};
bool isEmpty(address root);//
void createTree(address &root);// fungsi untuk mdmnuat  bst root do set null
address newNode(infotype x); //untuk memasukan data(infotype) ke dalam node
address insertNode(address root, infotype x);//untuk memasukan node ke dalam BST
//travesal
void preOrder(address root); // secara preorder tengan - kiri - kanan
void inOrder(address root); //kiri - tengah - kanan
void postOrder(address root); // kiri - kanan - tengah

int countNodes(address root);//untuk menghitung size jumlah node yang ada di tree
int treeDepth(address root);//

//fungsi tambahan
//search
void searchByData(address root, infotype x);

//mostleft dan righrleft
address mostLeft(address root);//menmapilkan mostleft/paling kiti
address mostRight(address root);// menmapilkan paling kanan

//delete
bool deleteNode(address &root, infotype x); // mennghapus node tertentu di dalam BST
void deleteTree(address &root);//proeedur untuk menghapus BSt(hapus seluruh node)

#endif

```
file main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program ini merupakan implementasi lengkap dari Binary Search Tree (BST) yang mencakup operasi dasar hingga fitur tambahan seperti pencarian, menemukan nilai minimum–maksimum, serta penghapusan node. Program diawali dengan pembuatan struktur node yang menyimpan data integer dan pointer ke anak kiri serta kanan. createTree, isEmpty, newNode, dan insertNode digunakan untuk membangun BST serta menambahkan data baru sesuai aturan BST. traversal inOrder, preOrder, dan postOrder untuk menampilkan . Program ini juga dapat menghitung jumlah node menggunakan countNodes dan kedalaman tree melalui treeDepth. searchByData digunakan untuk pencarian data sekaligus menampilkan parent, sibling, dan child dari node tersebut. Fungsi mostLeft dan mostRight digunakan untuk menemukan nilai terkecil dan terbesar di dalam BST. Program juga mengimplementasikan proses penghapusan node dengan deleteNode, yang menangani berbagai kasus penghapusan (leaf, satu child, dua child). deleteTree digunakan untuk menghapus seluruh node dalam tree. Pada fungsi main, program memasukkan beberapa data awal, menampilkan traversal, melakukan pencarian, menampilkan node ekstrem, menghapus node tertentu berdasarkan input, dan menghapus seluruh isi tree. 

### 3. guided 3

```C++
#include <iostream>
using namespace std;

int pangkat_2(int x){
    if(x == 0){
        return 1;
    }else if(x > 0) { //rekuren
        return 2 * pangkat_2(x-1);
    }
}
int main(){
    cout <<" --rekursif pangkat 2--" << endl;

    int x;
    cout << " masukan nilai x : ";
    cin >> x;
    cout << endl;
    cout << " 2 pangkat " << x << "adalah : " << pangkat_2(x);
    return 0;
}
// x=3
//pankat(2)
//2* pagkat(2)
// 2*2pangkat91
```
Program ini untuk menghitung nilai 2 pangkat x menggunakan rekursi. Fungsi pangkat_2(int x) bekerja dengan prinsip pemanggilan berulang (recursive). Jika x == 0, fungsi mengembalikan nilai 1, karena secara matematika, 2⁰ = 1. Jika x > 0, fungsi akan memanggil dirinya sendiri dengan x-1, lalu mengalikan hasilnya dengan 2. Proses ini terus berlangsung sampai nilai x mencapai 0

## Unguided 

### 1. Soal unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
“bstree.h”.Buatlah implementasi ADT Binary Search Tree pada file“bstree.cpp” dan cobalah hasil
implementasi ADT pada file “main.cpp”

file bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef int infotype;
//typedef Node* address;
struct Node{
    infotype info;
    Node* left;
    Node* right;
};
typedef Node* address;
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root,infotype x);
void printInOrder(address  root);

#endif
```
file bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;
address alokasi(infotype x){
    address P = new Node;
    P -> info = x;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}
void insertNode(address &root, infotype x){
    if(root == NULL){
        root = alokasi(x);
    }else if(x < root -> info){
        insertNode(root -> left, x);
    }else{
        insertNode(root -> right, x);
    }
}
address findNode(address root, infotype x){
    if(root == NULL){
        return NULL;
    }
    if(root -> info == x){
        return root;
    }
    if(x < root -> info){
        return findNode(root -> left, x);
    }else{
        return findNode(root -> right, x);
    }
}
void printInOrder(address root){
    if (root == nullptr) return;

    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}
```
file main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
cout << "Hello World" << endl;
address root = NULL;
insertNode(root,1);
insertNode(root,2);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
printInOrder(root);
return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan10_modul10/Output_unguided1_modul10.png)

Program tersebut mengimplementasikan struktur data Binary Search Tree (BST). Struktur Node memiliki tiga elemen, yaitu info sebagai data, serta pointer left dan right sebagai anak kiri dan kanan. Fungsi alokasi digunakan untuk membuat node baru, sedangkan insertNode berfungsi menempatkan data ke dalam BST sesuai aturan: nilai lebih kecil disimpan di sisi kiri dan nilai lebih besar di kanan. Fungsi findNode digunakan untuk mencari sebuah nilai di dalam tree dengan cara menelusuri node secara rekursif. Sementara itu, fungsi printInOrder mencetak seluruh isi BST dari nilai paling kecil ke paling besar dengan traversal in-order (left–root–right). Pada fungsi main, program membuat BST kosong, memasukkan beberapa nilai (1–7) ke dalam tree, lalu mencetak seluruh isi tree secara urut. 

### 2. Soal unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer

file bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef int infotype;
//typedef Node* address;
struct Node{
    infotype info;
    Node* left;
    Node* right;
};
typedef Node* address;
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root,infotype x);
void printInOrder(address  root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);


#endif
```
file bstree.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;
address alokasi(infotype x){
    address P = new Node;
    P -> info = x;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}
void insertNode(address &root, infotype x){
    if(root == NULL){
        root = alokasi(x);
    }else if(x < root -> info){
        insertNode(root -> left, x);
    }else{
        insertNode(root -> right, x);
    }
}
address findNode(address root, infotype x){
    if(root == NULL){
        return NULL;
    }
    if(root -> info == x){
        return root;
    }
    if(x < root -> info){
        return findNode(root -> left, x);
    }else{
        return findNode(root -> right, x);
    }
}
void printInOrder(address root){
    if (root == nullptr) return;

    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}

int hitungJumlahNode(address root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + hitungJumlahNode(root -> left) + hitungJumlahNode(root -> right);
    }
}
int hitungTotalInfo(address root){
    if(root == NULL){
        return 0;
    }else{
        return root -> info + hitungTotalInfo(root -> left) + hitungTotalInfo(root -> right);
    }
}
int hitungKedalaman(address root, int start){
    if(root == NULL){
        return start;
    }else{
        int leftDepth = hitungKedalaman(root -> left, start );
        int rightDepth = hitungKedalaman(root -> right, start );
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
file main.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;


int main() {
    cout << "Hello World" << endl;
    address root = NULL;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInOrder(root);
    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalInfo(root)<<endl;
    return 0;
    }
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan10_modul10/Output_unguided2_modul10.png)

Program tersebut merupakan implementasi struktur data Binary Search Tree (BST) yang menyimpan data bertipe integer. Struktur Node memiliki nilai info serta pointer left dan right untuk merepresentasikan anak kiri dan kanan. Program menyediakan beberapa fungsi penting, antara lain insertNode untuk memasukkan data ke BST sesuai aturan nilai lebih kecil ke kiri dan lebih besar ke kanan, findNode untuk mencari nilai tertentu, serta printInOrder untuk mencetak seluruh isi tree secara terurut menggunakan traversal in-order. Selain itu, terdapat fungsi tambahan seperti hitungJumlahNode yang menghitung total node dalam tree, hitungTotalInfo yang menjumlahkan seluruh nilai yang tersimpan di tree, dan hitungKedalaman yang menentukan kedalaman atau tinggi tree secara rekursif. Pada fungsi main, program membuat tree kosong, memasukkan beberapa nilai (1–7), mencetak isi tree, lalu menampilkan kedalaman tree, jumlah total node, serta jumlah keseluruhan nilai yang tersimpan.

### 3. Soal unguided 3
Print tree secara pre-order dan post-order.

```C++
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* address;

// Membuat node
address alokasi(int x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

// Pre-order: Root, Left, Right
void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order: Left, Right, Root
void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

int main() {
    address root = NULL;
    root = alokasi(6);                 // root

    root->left = alokasi(4);           // 6 -> left  = 4
    root->right = alokasi(7);          // 6 -> right = 7

    root->left->left = alokasi(2);     // 4 -> left  = 2
    root->left->right = alokasi(5);    // 4 -> right = 5

    root->left->left->left = alokasi(1); // 2 -> left  = 1
    root->left->left->right = alokasi(3); // 2 -> right = 3

    cout << "Pre-Order traversal  : ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan10_modul10/Output_unguided3_modul10.png)

Program tersebut membuat dan menelusuri sebuah binary tree menggunakan metode traversal pre-order dan post-order. Struktur Node digunakan untuk menyimpan sebuah nilai integer serta pointer ke anak kiri dan kanan. Fungsi alokasi digunakan untuk membuat node baru yang kemudian dirangkai secara manual di fungsi main sehingga membentuk sebuah tree dengan akar bernilai 6, dan memiliki beberapa cabang seperti 4, 7, 2, 5, 1, dan 3. Fungsi preOrder menampilkan node dengan urutan Root–Left–Right, sedangkan postOrder menampilkan node dengan urutan Left–Right–Root. Pada bagian output, program mencetak hasil traversal pre-order dan post-order dari tree yang telah dibentuk.

## Kesimpulan
Multi Linked List merupakan struktur data yang terdiri dari beberapa kelompok Linked List terpisah namun tetap dapat diakses sekaligus, sehingga memudahkan pengelompokan data secara rapi dan terorganisasi; sedangkan Tree adalah struktur data hierarkis yang menghubungkan node melalui hubungan parent–child, dimulai dari root hingga leaf, sehingga cocok untuk merepresentasikan data bertingkat; dan algoritma rekursif adalah teknik pemrograman di mana suatu fungsi memanggil dirinya sendiri dengan ruang masalah yang semakin kecil, sehingga sangat efektif digunakan pada proses yang memiliki pola berulang seperti traversal pada Tree. Dengan memahami ketiga konsep ini, kita dapat memilih dan menggunakan struktur data ataupun algoritma yang tepat sesuai kebutuhan aplikasi.

## Referensi
[1] Annisa. (2025). Pengertian Linked List : Structur Data dalam Pemprograman .https://share.google/ZHwf3jDuCjJnvDri3 <br>
[2] Pebrianti, E., & Abdurramadan, N. (2025). Struktur Data Tree: Konsep, Jenis, dan Aplikasinya. Direktorat Pusat Teknologi Informasi.https://share.google/gNeh0RKpK3BtJ8fRK <br>
[3] Annisa. (2025). Algoritma Rekursif: Pengertian, Tujuan dan Jenisnya.https://share.google/Z1b300pEZ29AYrlsX
