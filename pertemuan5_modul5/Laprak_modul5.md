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
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Implementasi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    // Hitung ukuran linked list
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        // Pindah ke node tengah
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        // Cek apakah data ditemukan
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        // Jika data midNode lebih kecil dari key, cari di bagian kanan
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) {
                    return lastNode;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            start = midNode->next;
            size = newSize;
        }
        // Jika data midNode lebih besar dari key, cari di bagian kiri
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            if (mid == 1) {
                if (start->data == key) {
                    return start;
                }
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

// Prosedur untuk menambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk membersihkan memori
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int searchKey;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    // Data linked list sudah ditentukan dari awal
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Tampilkan isi linked list
    displayList(head);
    
    // 🔹 Pencarian pertama (otomatis mencari 40)
    searchKey = 40;
    cout << "\nMencari nilai: " << searchKey << endl;
    
    Node* result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // 🔹 Pencarian kedua (otomatis mencari 25)
    searchKey = 25;
    cout << "\nMencari nilai: " << searchKey << endl;
    
    result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // Bersihkan memori
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
