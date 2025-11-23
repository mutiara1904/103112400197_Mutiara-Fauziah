# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Struktur data adalah cara untuk mengatur, menyimpan, dan mengelola data di dalam komputer agar data mudah diakses, diproses, dan diubah. 
Dengan struktur data, data bisa dikelola dengan lebih baik dan program berjalan lebih cepat dalam memproses informasi. Struktur data juga 
membantu memahami bagaimana data saling terhubung, sehingga memudahkan pencarian dan pengubahan data sesuai kebutuhan aplikasi. Menggunakan 
struktur data yang tepat akan membantu programmer meningkatkan kinerja aplikasi dan menghadapi masalah data yang rumit [1].

### A. Queue <br/>
Queue atau struktur data antrean adalah struktur data yang mengatur elemen data secara linier. Queue memiliki prinsip dasar "First In, First Out" atau FIFO yang berarti 
elemen yang pertama kali dimasukan kedalam antrean, akan dikeluarkan lebih dulu. Queue memiliki banyak peran dalam aplikasi dan algoritma. Salah satu peran utama adalah 
sistem yang bisa mengatur dan mengelola antrean tugas secara efisien, sedangkan dalam komputasi secara sistem digunakan dalam pengelolaan, penjadwalan proses, antrian pesan 
dan manajemen sumber daya. Queue juga bisa dibagi menjadi banyak jenis mendasar dari implementasi dan pengunaan :  
1. Jenis Queue berdasarkan Implementansinya  
- Simple/Linear Queue: Elemen data yang ada pada struktur antrean akan disusun secara linear dan elemen data bisa hanya ditambahkan atau dihapus dari 2 ujung barisan.  
- Circular Queue:  Hampir sama pada linear queue, tetapi ujung dari 2 baris akan saling terhubung, sehingga membentuk antrean yang berputar. 
2. Jenis Queue berdasarkan Pengunaannya  
- Prioritty Queue:  Setiap elemen pada queue  memiliki prioritas, elemen yang akan diambil adalah elemen dengan prioritas teratas.  
- Double-ended Queue (Dequeue):  Elemen pada queue bisa ditambahkan atau dihapus pada 2 ujung barisan antrean [2].


## Guided 

### 1. Soal guided 1
"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL
#include <iostream>
using namespace std;
typedef struct node *address;
struct node{
   int dataAngka;
   address next;
};
struct Queue {
    address head;
    address tail;
};
bool isEmpty(Queue Q);
void createQueue(Queue &Q);
address alokasi(int angka);
void dealokasi(Queue &node);
void enqueue(Queue &Q, address nodeBaru);
int dequeue(Queue &Q);
void updateQueue(Queue &Q, int posisi);
void viewQueue(Queue Q);
void searchData(Queue Q, int data);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(Queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(Queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enqueue(Queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

int dequeue(Queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(Queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(Queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(Queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enqueue(Q, nodeA);
    enqueue(Q, nodeB);
    enqueue(Q, nodeC);
    enqueue(Q, nodeD);
    enqueue(Q, nodeE);
    cout << endl;

    cout << "queue setelah dihapus " << endl;
    viewQueue(Q);
    cout << endl;

    dequeue(Q);
    dequeue(Q);
    cout << endl;

    cout << "queue setelah deque 2 kali" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "queue setelah diupdate " << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}
```
Program tersebut mengimplementasikan struktur data Queue (antrian) menggunakan linked list. Setiap elemen queue disimpan dalam node yang berisi data angka 
dan pointer ke node berikutnya. Queue memiliki dua pointer utama, yaitu head untuk menunjuk elemen paling depan dan tail untuk menunjuk elemen paling belakang. 
Program menyediakan fungsi dasar seperti createQueue untuk inisialisasi, isEmpty untuk mengecek apakah queue kosong, alokasi dan dealokasi untuk membuat serta 
menghapus node, enqueue untuk menambahkan elemen ke bagian belakang queue, dan dequeue untuk menghapus elemen dari bagian depan queue. Selain itu, terdapat fitur 
tambahan seperti updateQueue yang memungkinkan pengguna mengganti nilai node tertentu berdasarkan posisi, viewQueue untuk menampilkan seluruh isi queue, dan searchData 
untuk mencari apakah suatu nilai terdapat dalam queue. Pada fungsi main, program membuat lima node (1 - 5), menambahkannya ke queue, menampilkan antrian, menghapus 
dua node terdepan, mengupdate beberapa posisi, dan melakukan pencarian data.

### 2. Soal guided 2
"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
struct Queue
{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};
void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif

```
"queue.cpp"
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
"main.cpp"
```C++
#include <iostream>
#include"queue.h"
using namespace std;
int main (){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueu 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    
    cout << "\n dequeue 1 elemen" << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "enqueu 1 elemen " << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n dequeue 2 elemen " << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Program tersebut mengimplementasikan Circular Queue menggunakan array berukuran tetap (MAX_QUEUE = 5). Struktur queue menyimpan tiga informasi penting: indeks head sebagai posisi 
elemen depan, tail sebagai posisi elemen belakang berikutnya, serta count sebagai jumlah elemen yang sedang tersimpan. Fungsi createQueue menginisialisasi queue agar kosong, sementara 
isEmpty dan isFull digunakan untuk mengecek kondisi queue. Operasi enqueue menambahkan data ke posisi tail, lalu memutar indeks menggunakan operasi modulus agar bersifat circular. 
Sebaliknya, dequeue mengambil elemen dari head dan menggeser posisi kepala secara circular. Fungsi printInfo menampilkan seluruh isi queue sesuai jumlah elemen yang tersimpan. 
Pada fungsi main, program mendemonstrasikan cara kerja circular queue dengan menambah beberapa elemen, menghapus elemen dari depan, menambah elemen lagi setelah terjadi perputaran 
indeks, dan menampilkan isi queue setiap kali ada perubahan. 


## Unguided 

### 1. Soal unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file“queue.h”.Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme
queue Alternatif 1 (head diam, tail bergerak).

"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;

}
bool isEmptyQueue(Queue Q){
    return (Q.head == 0);
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE);
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh" << endl;

    }
    if (isEmptyQueue(Q)){
        Q.head = 1;
        Q.tail = 1;
        Q.info[0] = x;
    }else{
        Q.tail++;
        Q.info[Q.tail - 1] = x;
    }
    
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "queue kosong" << endl;
        return -1;
    }
    infotype hasil = Q.info[0];
    for (int i = 0; i < Q.tail - 1; i++){
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail == 0){
        Q.head = 0;
    }
    return hasil;
}
void printInfo(Queue Q) {
    int H, T;

    // Konversi posisi HEAD & TAIL ke format tugas (0 → -1 untuk kosong)
    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   // HEAD selalu = 1 → ditampilkan sebagai 0
        T = Q.tail - 1;   // TAIL = jumlah elemen → ditampilkan indeks terakhir
    }

    // Cetak HEAD - TAIL
    cout << H << "  -  " << T << "  |  ";

    // Tampilkan isi queue
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan8_modul8/Output_unguided1_modul8.png)

Program ini mengimplementasikan Queue (antrian) menggunakan array biasa tanpa circular queue. Struktur queue berisi array info[MAX_QUEUE] serta dua indikator posisi: head dan tail.
Pada awalnya, CreateQueue mengatur head = 0 dan tail = 0, yang menandakan queue kosong. Fungsi isEmptyQueue memeriksa apakah head = 0, sedangkan isFullQueue mengecek apakah tail sudah 
mencapai kapasitas maksimum. Proses enqueue menambahkan elemen baru ke lokasi tail. Jika queue kosong, head dan tail diset menjadi 1 dan data diletakkan pada indeks 0. Jika tidak kosong, 
tail dinaikkan dan data disimpan pada posisi tail - 1. Pada operasi dequeue, elemen paling depan (indeks 0) diambil, kemudian seluruh elemen digeser ke kiri agar posisi paling depan tetap 
berada pada indeks 0. Setelah penghapusan, tail dikurangi, dan jika tail menjadi 0, maka queue kembali dianggap kosong (head = 0). Fungsi printInfo menampilkan posisi HEAD dan TAIL sesuai 
format tugas, lalu mencetak isi queue saat ini. Di fungsi main, program mendemonstrasikan mekanisme queue dengan melakukan serangkaian enqueue dan dequeue sambil menampilkan isi queue setelah 
setiap operasi. Program ini menunjukkan model queue sederhana yang menggunakan shift (geser array) setiap kali melakukan penghapusan agar struktur tetap rapi dan elemen depan selalu berada di indeks pertama.

### 2. Soal unguided 2
Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme
queue Alternatif 2 (head bergerak, tail bergerak).

"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return Q.tail < Q.head;
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE - 1);
}
void enqueue(Queue &Q, infotype x){
   
   if(!isFullQueue(Q)){
    Q.tail++;
    Q.info[Q.tail] = x;
   }else{
        cout << "queue penuh \n";
   }
    
    
}
infotype dequeue(Queue &Q){
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];
        Q.head++;

        // reset ketika kosong
        if (Q.head > Q.tail) {
            Q.head = 0;
            Q.tail = -1;
        }
        return x;
    }
    cout << "Queue kosong!\n";
    return -1;
   
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}

```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan8_modul8/Output_unguided2_modul8.png)

Program ini menerapkan struktur data queue dengan array linear yaitu queue yang maju tanpa circular. 
Struktur queue terdiri dari array info[MAX_QUEUE] dan 2 indeks penting yaitu head yang merepresentasikan 
posisi elemen paling depan dan tail yang merepresentasikan posisi elemen paling belakang. Saat queue di buat 
dengan CreateQueue, head di set 0 dan tail -1 sebagai tanda antrian kosong. Fungsi isEmptyQueue akan menguji 
apakah tail di belakang head, untuk menguji apakah queue dalam keadaan kosong, sedangkan isFullQueue menguji 
apakah tail sudah sampai pada indeks paling belakang. Pada proses enqueue, selagi queue belum penuh, tail di increment 1 
dan data baru di masukkan pada posisi yang baru.Untuk proses dequeue, elemen paling depan yang di head diambil, lalu head 
di increment. Jika setelah elemen diambil head sudah lebih dari tail, queue di reset dan di set kedua indeks kembali kedalam 
posisi asal semula. Fungsi printInfo menampilkan posisi head - tail dengan elemen queue dari head sampai tail. Di dalam main, program
ini mengilustrasikan pengoperasian queue dengan serangkaian enqueue dan dequeue lengkap dengan output pada akhir program.
Dengan cara ini, antrian sudah berjalan dengan baik, meskipun tanpa pergeseran elemen tetapi area yang dilalui head sudah tidak terpakai.


### 3. Soal unguided 3
"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return(Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return((Q.tail + 1) % MAX_QUEUE == Q.head);
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "queue penuh" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;

    }else{
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
    Q.info[Q.tail] = x;
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        return -1;
    }
    infotype temp = Q.info[Q.head];
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }
    return temp;
}
void printInfo(Queue Q){
    cout << " " << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX_QUEUE;
    }
    cout << endl;
}
```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan8_modul8/Output_unguided3_modul8.png)

Program ini menggunakan array untuk mengimplementasikan CircularQueue dengan pergeseran indeks (modulus).
Setiap queue berisi array info[MAX_QUEUE] bersama dengan dua penanda, head dan tail, yang menunjukkan lokasi elemen pertama dan terakhir dari queue. 
Awalnya, CreateQueue mengatur kedua indeks ke -1, menunjukkan bahwa queue kosong. Fungsi isEmptyQueue memeriksa bahwa head dan tail adalah -1, dan isFullQueue 
menentukan bahwa queue penuh dengan memeriksa bahwa posisi setelah tail (menggunakan (tail + 1) % MAX_QUEUE) berbenturan dengan head. Dalam operasi enqueue, jika queue kosong, head dan tail diatur ke 0; jika tidak, 
tail dimajukan menggunakan rumus circular (tail + 1) % MAX_QUEUE, dan kemudian data baru ditambahkan ke tail queue. Sebaliknya, operasi dequeue menghapus elemen di posisi head dan kemudian, 
head dimajukan secara sirkular. Jika, setelah penghapusan, head dan tail sama, kedua indeks diatur ke -1 untuk menunjukkan bahwa queue kembali kosong. Fungsi printInfo menunjukkan posisi head dan tail, 
dan kemudian mencetak seluruh queue dengan melacak array secara sirkular hingga tail tercapai. Fungsi utama berisi demonstrasi queue sirkular di mana sejumlah operasi enqueue dan dequeue dilakukan, dan pergerakan 
indeks ditunjukkan tanpa menggeser sisa data di dalam array.


## Kesimpulan
Struktur data merupakan komponen penting dalam pemrograman karena berfungsi untuk mengatur, menyimpan, dan mengelola data agar lebih mudah diakses dan diproses. Penggunaan struktur data yang tepat akan 
meningkatkan efisiensi kinerja program dan membantu menangani pengolahan data yang kompleks. Salah satu struktur data yang sering digunakan adalah queue, yang bekerja dengan prinsip FIFO (First In, First Out). 
Queue sangat bermanfaat dalam berbagai aplikasi seperti penjadwalan proses, pengelolaan antrean tugas, manajemen pesan, serta sistem yang membutuhkan pengolahan data secara berurutan. Selain itu, queue memiliki 
beberapa jenis yang dapat disesuaikan dengan kebutuhan, baik dari sisi implementasi seperti Linear Queue dan Circular Queue, maupun dari sisi penggunaan seperti Priority Queue dan Double-ended Queue. Dengan 
memahami jenis dan fungsi queue, programmer dapat memilih model antrean yang paling sesuai untuk menyelesaikan permasalahan secara lebih efisien.

## Referensi
[1] Anaraindyah, R. (2024). Struktur data: Pengertian, fungsi, dan penerapannya. Universitas Negeri Surabaya.https://share.google/kfvAZsEHXwWWO9ZVc </br>
[2] Maulana, R. (2023). Struktur data queue: Pengertian, fungsi, dan jenisnya. Digoding.https://share.google/pxu2YAgcsMBzVlprm
