# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List(Bagian kedua)</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Linked List adalah jenis struktur data linier di mana setiap elemen tidak disimpan di tempat yang berdekatan, melainkan dihubungkan melalui pointer. Linked List terdiri dari rangkaian node yang saling terhubung, di mana setiap node berisi data dan alamat node berikutnya [1].

### A. Linear search<br/>
Linear Search adalah algoritma yang bekerja dengan mencocokkan data satu per satu secara berurutan, mulai dari ujung awal hingga ujung akhir dari sekumpulan data. Pencarian menggunakan Linear Search tidak akan berhenti sampai data yang dicari berhasil ditemukan.
Kelebihan linear search adalah datanya tidak harus terurut dan dan alhoritmanya mudah dipelajari, tetapi tidak cocok unutk data yang sangat besar dan waktu pencariannya lama [2].
### B. Binary search<br/>
Binary Search adalah metode pencarian yang digunakan untuk data yang sudah terurut. Metode ini bekerja dengan membagi data menjadi dua bagian secara terus-menerus. Dengan membagi dua, proses pencarian menjadi lebih cepat karena tidak perlu mencari di bagian yang tidak relevan. Kelebihan binary search adalah pencarian nya lebih cepat dan efektif jika datanya banyak, tetapi datanya harus terurut[2].

## Guided 

### 1. soal guided 1

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Program ini bertujuan untuk mencari suatu angka dalam linked list dengan menggunakan algoritma Binary Search. Program ini memakai struktur data linked list, di mana setiap node terdiri dari dua bagian, yaitu data berupa bilangan bulat dan pointer next yang mengarah ke node berikutnya. Awalnya, program membangun linked list dengan fungsi append(), yang menambahkan nilai baru di bagian akhir daftar. Setelah linked list selesai dibuat, fungsi binarySearch() digunakan untuk mencari angka tertentu, misalnya angka 40. Cara kerjanya adalah dengan membagi daftar menjadi dua bagian secara berulang, sama seperti metode binary search pada array. Fungsi ini terlebih dahulu menghitung jumlah elemen dalam linked list, lalu menentukan posisi tengah (mid), membandingkan nilai tengah tersebut dengan angka yang dicari, dan menyesuaikan batas pencarian ke kiri atau ke kanan hingga angka ditemukan atau tidak ada node lagi yang perlu dicari. Di akhir program, hasil pencarian ditampilkan di layar dengan pesan "found" jika angka ditemukan, dan "not found" jika tidak ditemukan.

### 2. soal guided 2

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Programini digunakan untuk mencari sebuah data di dalam linked list dengan menggunakan algoritma Linear Search. Struktur data yang digunakan adalah linked list, di mana setiap node terdiri dari dua bagian: bagian pertama menyimpan nilai data dan bagian kedua menunjuk ke node berikutnya. Fungsi append() digunakan untuk menambahkan node baru di akhir dari linked list. Dalam fungsi linearSearch(), pencarian dilakukan secara bertahap mulai dari node pertama (head) sampai node terakhir. Setiap node diperiksa satu per satu untuk mengetahui apakah nilai datanya sama dengan nilai yang dicari (key). Jika ditemukan, fungsi akan mengembalikan pointer ke node tersebut; jika tidak ditemukan, fungsi akan mengembalikan nilai nullptr. Di dalam fungsi main(), program membuat linked list dengan data 10, 20, dan 30, lalu melakukan pencarian terhadap nilai 20 menggunakan fungsi linearSearch(). Hasil dari proses pencarian tampil di layar dalam bentuk pesan “found” jika data ditemukan dan “not found” jika tidak.

### soal guided 2
file "listBuah.h"
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL
#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; // nama alias daatbuah pada struct buah
typedef struct node *address; // mendefniskan alias address sbgi pointer ke struct

struct node{ //  node unutk isi linked list  isi setiap 
    dataBuah isiData;
    address next;
};
struct linkedList{ //linked list
   address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst (linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLst(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address Prev);

#endif

```
file "listBuah.cpp"
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.jumlah = jumlah; 
    nodeBaru->isiData.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isiData.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isiData.nama << ", Jumlah : " << nodeBantu->isiData.jumlah << ", Harga : " << nodeBantu->isiData.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isiData.nama;
        cout << "Jumlah : ";
        cin >> List.first->isiData.jumlah;
        cout << "Harga : ";
        cin >> List.first->isiData.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isiData.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isiData.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isiData.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isiData.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isiData.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isiData.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isiData.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

file "main.cpp"
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("jeruk" , 100, 3000);
    nodeB = alokasi("apel", 75, 4000);
    nodeC = alokasi("pir" , 87, 5000 );
    nodeD = alokasi("semangka", 43, 11500);
    nodeE = alokasi("durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE); // a-c-d-b-e
    cout << "isi list detelah dilakukan insert" << endl;
    printList(List);
    cout << " Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "isi list setelah dlakukan update " << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;


    return 0;
}
```


## Unguided 

### 1. sol unguided 1
Implementasikan program C++ yang menggunakan algoritma Binary
Search pada Linked List untuk mencari elemen tertentu. Program
harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 1:
• Gunakan struktur Node dengan data integer dan pointer next
• Implementasikan fungsi append() untuk menambah node
• Implementasikan fungsi binarySearch() yang mengembalikan
pointer ke node yang ditemukan
• Data dalam linked list harus terurut (ascending) untuk
binary search bekerja dengan benar
• Tampilkan langkah-langkah pencarian dan posisi tengah
setiap iterasi
• Program utama harus membuat linked list dengan minimal 5
elemen dan melakukan pencarian
```C++
#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node* next; // pointer ke node berikutnya
};

// Fungsi untuk menampilkan linked list
void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Implementasi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    // Hitung ukuran linked list
    int size = 0;
    for (Node* current = head; current; current = current->next)
        size++;
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        // Pindah ke node tengah
        for (int i = 0; i < mid; i++)
            midNode = midNode->next;
        
        // Jika ketemu
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        // Jika mid lebih kecil dari key → cari di kanan
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) return lastNode;
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            start = midNode->next;
            size = newSize;
        }
        // Jika mid lebih besar dari key → cari di kiri
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            if (mid == 1) {
                if (start->data == key) return start;
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            size = mid;
        }
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}

// Tambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Hapus semua node (bebaskan memori)
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main program
int main() {
    Node* head = nullptr;
    int searchKey;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Tampilkan list
    displayList(head);
    
    // 🔹 Pencarian pertama
    searchKey = 40;
    cout << "Mencari nilai: " << searchKey << "\n";
    
    Node* result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // 🔹 Pencarian kedua
    searchKey = 25;
    cout << "Mencari nilai: " << searchKey << "\n";
    
    result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    deleteList(head);
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan%_modul5/Output_unguided2_modul5.png)

Program ini berfungsi untuk mencari data dalam linked list menggunakan metode binary search. Struktur Node digunakan untuk menyimpan data dan pointer ke node berikutnya. Fungsi append() menambahkan data baru ke akhir list, sedangkan displayList() menampilkan seluruh isi list. Fungsi binarySearch() melakukan pencarian dengan membagi list menjadi dua bagian, memeriksa nilai tengah, lalu menentukan apakah pencarian dilanjutkan ke kiri atau kanan hingga data ditemukan atau tidak ada elemen tersisa. Pada fungsi main(), program membuat list berisi 10 hingga 60, menampilkannya, lalu secara otomatis mencari nilai 40 (ditemukan) dan 25 (tidak ditemukan).

### 2. soal unguided 2
Implementasikan program C++ yang menggunakan algoritma Linear
Search pada Linked List untuk mencari elemen tertentu. Program
harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 2:
• Gunakan struktur Node dengan data integer dan pointer next
• Implementasikan fungsi append() untuk menambah node
• Implementasikan fungsi linearSearch() yang mengembalikan
pointer ke node yang ditemukan
• Data dalam linked list tidak perlu terurut untuk linear
search
• Tampilkan setiap langkah pencarian dan node yang sedang
diperiksa
• Program utama harus membuat linked list dengan minimal 3
elemen dan melakukan pencarian

```C++
#include <iostream>
using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int posisi = 1;

    cout << "\nProses Pencarian:\n";

    while (current != nullptr) {
        cout << "Memeriksa node " << posisi << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next;
        posisi++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

void printList(Node* head) {
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);

    // Pencarian pertama
    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << "\n";
    Node* hasil1 = linearSearch(head, cari1);

    if (hasil1) {
        cout << "\nHasil: Nilai " << cari1 << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil1 << "\n";
        cout << "Data node: " << hasil1->data << "\n";
        if (hasil1->next)
            cout << "Node berikutnya: " << hasil1->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari1 << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    // Pencarian kedua
    int cari2 = 25;
    cout << "\nMencari nilai: " << cari2 << "\n";
    Node* hasil2 = linearSearch(head, cari2);

    if (hasil2) {
        cout << "\nHasil: Nilai " << cari2 << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil2 << "\n";
        cout << "Data node: " << hasil2->data << "\n";
        if (hasil2->next)
            cout << "Node berikutnya: " << hasil2->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari2 << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan5_modul5/Output_unguided2_modul5.png)

Program di atas merupakan implementasi pencarian linear pada linked list menggunakan C++. Struktur Node digunakan untuk menyimpan data dan pointer ke node berikutnya. Fungsi append menambahkan node baru di akhir list, sedangkan printList menampilkan isi list dari awal hingga akhir dengan format “data -> … -> NULL”. Fungsi linearSearch mencari nilai tertentu secara berurutan dari node pertama sampai terakhir sambil menampilkan proses pencarian. Pada fungsi main, program membuat linked list berisi nilai 10, 20, 30, 40, dan 50, lalu menampilkan isinya. Setelah itu, dilakukan pencarian dua kali: nilai 30 yang ditemukan dalam list, dan nilai 25 yang tidak ditemukan.

## Kesimpulan
Linked List adalah struktur data linier yang unik karena elemennya, yang disebut node, tidak disimpan di lokasi memori yang berdekatan sebaliknya, node-node tersebut dihubungkan melalui pointer. Setiap node berisi data dan alamat (pointer) ke node berikutnya dalam urutan. Sementara itu, terdapat dua algoritma pencarian utama: Linear Search dan Binary Search. Linear Search bekerja dengan membandingkan data satu per satu secara berurutan dari awal hingga akhir dan memiliki keunggulan karena datanya tidak harus terurut serta algoritmanya mudah dipelajari, namun menjadi tidak efisien untuk data yang sangat besar karena waktu pencariannya lama. Sebaliknya, Binary Search adalah metode yang jauh lebih cepat dan efektif, terutama untuk data besar, karena ia bekerja dengan cara membagi data menjadi dua bagian secara terus-menerus, tetapi kelemahan utamanya adalah algoritma ini hanya dapat diterapkan pada data yang sudah terurut.

## Referensi
[1]Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).<br>
[2]Putra, M. Naufal Adrian Pratama. 2023. Algoritma Pemrograman: Linear Search & Binary Search. Medium, 29 Juni 2023. Diakses dari https://medium.com
