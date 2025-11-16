# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Linked List adalah jenis struktur data linier di mana setiap elemen tidak disimpan di tempat yang berdekatan, melainkan dihubungkan melalui pointer. Linked List terdiri dari rangkaian node yang saling terhubung, di mana setiap node berisi data dan alamat node berikutnya [1].

### A. Stack <br/>
Stack adalah struktur data linier yang mengikuti aturan tertentu untuk melakukan operasi. Data yang memiliki struktur stack, tersusun seperti tumpukan, sehingga hanya elemen yang baru dimasukkan yang dapat diakses atau dilihat. Ujung tumpukan yang digunakan untuk melakukan semua operasi disebut bagian atas tumpukan. Stack mengikuti prinsip LIFO (Last In First Out), yang berarti elemen yang dimasukkan terakhir akan menjadi elemen pertama yang keluar dari urutan data [2].

## Guided 

### 1. Soal guided 1
"file stack.h"
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct Stack{
    address top;
};

bool isEmpty(Stack listStack);
void createStack(Stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(Stack &listStack, address nodeBaru);
void pop(Stack &listStack);
void update(Stack &listStack, int posisi);
void view(Stack listStack);
void searchData(Stack listStack, int data);

#endif
```
"file stack.cpp"
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(Stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(Stack &listStack){
    listStack.top = Nil;
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

void push(Stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(Stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(Stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(Stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(Stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
"file main.cpp"
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program di atas mengimplementasikan struktur data Stack. Stack disusun dengan prinsip LIFO (Last In First Out), di mana elemen yang terakhir masuk adalah yang pertama keluar. Program menyediakan berbagai operasi dasar: membuat stack kosong (createStack), memeriksa apakah stack kosong (isEmpty), menambah elemen ke puncak stack (push), menghapus elemen teratas (pop), memperbarui nilai elemen pada posisi tertentu (update), menampilkan seluruh elemen stack dari atas ke bawah (view), dan mencari posisi suatu data di dalam stack (searchData). Pada fungsi main, program membuat lima node berisi angka 1–5, kemudian memasukkannya ke dalam stack. Setelah itu dilakukan dua kali operasi pop, beberapa kali update posisi tertentu, dan pencarian data dalam stack. Program ini menunjukkan cara kerja stack dinamis menggunakan pointer dan linked list, lengkap dengan validasi posisi serta pesan notifikasi setiap operasi dijalankan.


### 2. Soal guided 2
"file stack.h"
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20 //array unutknmenyimpan stack smpe 20
#define Nil -1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // nambh elemen

infotype pop(Stack &S); // ambil elemem paling atas
void printInfo(Stack S);
void balikStack(Stack &S); // membentuk urutan stack


#endif
```
"file stack.cpp"
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
"file main.cpp"
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Program ini mengimplementasikan struktur data Stack berbasis array dengan kapasitas maksimal 20 elemen. Stack direpresentasikan dengan array info dan variabel top yang menunjukkan indeks elemen teratas. Program menyediakan operasi dasar seperti membuat stack (CreateStack), mengecek apakah stack kosong atau penuh (isEmpty, isFull), menambah elemen (push), menghapus elemen teratas (pop), menampilkan isi stack dari atas ke bawah (printInfo), serta fungsi khusus untuk membalik isi stack (balikStack) menggunakan dua stack bantu. Pada fungsi main, beberapa operasi push dan pop dilakukan untuk membentuk urutan elemen tertentu, kemudian isi stack dicetak. Setelah itu, fungsi balikStack dijalankan untuk membalik urutan stack, dan hasilnya kembali ditampilkan.



## Unguided 

### 1. Soal unguided
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”.Buatlah implementasi ADT Stack menggunakan Array pada file“stack.cpp” dan “main.cpp”.Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer).Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan
tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

"file stack.h"
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#define MaxEl 20
#define Nil -1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
```
"file stack.cpp"
```C++
#include "stack.h"
using namespace std;

void CreateStack(Stack &S){
    S.top = Nil;
}
void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.info[S.top] = x;
    }else{
        cout << "Stack penuh" << endl;
    }

}
infotype pop(Stack &S) {
    infotype x = -999;  
    if (!isEmpty(S)) {  
        x = S.info[S.top];  
        S.top--;  
    } else {
        cout << "Stack Kosong!" << endl;  
    }
    return x; 
}
void printInfo(Stack S) {
    if (isEmpty(S)) {  
        cout << "Stack Kosong" << endl;  
    } else {
        cout << "[TOP] ";  
        for (int i = S.top; i >= 0; i--) {  
            cout << S.info[i] << " ";  
        }
        cout << endl; 
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
bool isEmpty(Stack S){
    return S.top == Nil;
}
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  
}
void pushAscending(Stack &S, int x){
    Stack Temp1, Temp2;
    CreateStack(Temp1);
    CreateStack(Temp2);
    int t;
    while(!isEmpty(S)){
        t = pop(S);
        if (t < x){
            push(Temp1, t);
            //break;
        }else{
            push(Temp2, t);
        }
    }
    while(!isEmpty(Temp1)){
        push(S, pop(Temp1));
    }
    push(S, x);
    while(!isEmpty(Temp2)){
       
        push(S, pop(Temp2));
    }
}
void getInputStream(Stack &S) {
    char c;

    cout << "Masukkan input: ";

    cin.get(c);           // baca karakter pertama

    while (c != '\n') {   // berhenti jika user tekan ENTER
        push(S, c - '0'); 
        cin.get(c);       // baca karakter berikutnya
    }
}

```
"file main.cpp"
```C++
#include "stack.h"
#include <iostream>
using namespace std;
int main(){
    cout << "Hello World!" << endl;
    Stack S;
    CreateStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S,2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    //push ascending
    cout << "Hello World!" << endl;
    CreateStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;

    //input stream
    cout << "Hello World!" << endl;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan7_modul7/Output1_unguided_modul7.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/mutiara1904/1031124001997_Mutiara-Fauziah/blob/main/pertemuan7_modul7/Output2_unguided_modul7.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/mutiara1904/1031124001997_Mutiara-Fauziah/blob/main/pertemuan7_modul7/Output3_unguided_modul7.png)

Program ini mengimplementasikan struktur data Stack berbasis array. Stack disusun menggunakan array info berukuran maksimum 20 elemen dan indeks top sebagai penanda elemen teratas. Program menyediakan operasi dasar seperti membuat stack (CreateStack), menambah elemen (push), menghapus elemen teratas (pop), memeriksa apakah stack kosong atau penuh (isEmpty, isFull), menampilkan isi stack dari atas ke bawah (printInfo), serta membalik urutan elemen stack menggunakan dua stack sementara (balikStack). Selain itu, program memiliki fungsi pushAscending, yaitu memasukkan elemen baru sambil menjaga agar stack tetap terurut ascending dengan bantuan dua stack temporary. Program juga menyediakan fungsi getInputStream, yang membaca input karakter satu per satu menggunakan cin.get(), kemudian mengonversinya menjadi angka dan memasukkannya ke dalam stack sampai pengguna menekan ENTER. Pada fungsi main, seluruh fitur diuji: operasi dasar stack, push ascending, dan input stream, lalu setiap hasilnya ditampilkan.



## Kesimpulan
Linked List dan Stack merupakan dua struktur data linier yang berbeda namun sama-sama penting dalam pengelolaan data dinamis. Linked List memungkinkan penyimpanan data secara fleksibel karena setiap elemen dihubungkan melalui pointer tanpa perlu berada pada lokasi memori yang berurutan. Sementara itu, Stack berfokus pada mekanisme penyimpanan dan pengambilan data dengan aturan LIFO, sehingga elemen terakhir yang masuk menjadi elemen pertama yang keluar. Kedua struktur data ini memberikan solusi efisien untuk berbagai permasalahan, terutama dalam pengelolaan memori, akses data, dan proses yang membutuhkan urutan operasi tertentu.

## Referensi
[1]Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).<br>
[2]Soffya Ranti. (2022). Pengertian Stack dan Queue serta Contoh Penerapannya. Kompas.Com.https://tekno.kompas.com/read/2022/12/01/02150047/pengertian-stack-dan-queue-serta-contoh-penerapannya?utm_source=Various&utm_medium=Referral&utm_campaign=Top_Desktop
