# <h1 align="center">Laporan Praktikum Modul 3 - Abstact Data Type</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Tipe data merupakan sebuah jenis nilai atau berupa nilai apa yang akan  ditampung  oleh  sebuah  variabel.Ini diperlukan ketika membuat variabel agar memiliki nilai yang jelas dan spesifik ketika digunakan.[1]


### A. Abstarct Data Type (ADT)<br/>
...
Tipe data abstrak (ADT) adalah tipe data tertentu yang didefinisikan oleh pemrogram untuk kemudahan pemrograman dan untuk mengakomodasi tipe data yang tidak secara spesifik diakomodasi oleh bahasa pemrograman yang digunakan. ADT juga menyempurnakan tipe data dengan mengaitkannya dengan fungsi-fungsi yang beroprasi pada data yang bersangkutan.[2]

## Guided 

### 1. Soal Guided 1

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;

};

void inputMhs(mahasiswa &m){
    cout << " input nama : ";
    cin >> m.nama;
    cout << " input nilai 1 : ";
    cin >> m.nilai1;
    cout << " input nilai 2 : ";
    cin >> m.nilai2;

}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2) / 2;

}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "rata -rata nilai adalah : " << rata2(mhs) << endl;

    return 0;
}

```
Program ini dibuat untuk menginputkan data mahasiswa dan menghitung nilai rata-rata dari dua nilai yang dimasukan. Program menggunkana struck mahasiswa untuk menyimpan data mahasiswa yang terdiri dari nama dan nilai. fungsi inputMhs untuk meminta user menginputkan data mahasiswa. Fungsi rata2 untuk menghitung nilai rata-rata dari nilai yang diinputkan user.


### 2. soal guided 2

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H
struct mahasiswa
{
  char nim[10];
  int nilai1, nilai2;
    /* data */
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif


```

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m){
    cout << " input nim : ";
    cin >> m.nim;
    cout << " input nilai 1 : ";
    cin >> m.nilai1;
    cout << " input nilai 2 : ";
    cin >> m.nilai2;

}

float rata2(mahasiswa m){
    return (float)(m.nilai1 + m.nilai2) / 2;
}

```

```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "rata -rata nilai adalah : " << rata2 
    (mhs) << endl;
    system("pause");
    return 0;
}
```
Program tersebut untuk menginput data mahasiswa dan menghhitung nilai rata-rata dari nilai yang dimasukan. Program ini dibagi menjadi tiga bagian, yaitu file header, file implementasi fungsi, dan file main. Pada file header, didefinisikan struktur mahasiswa yang berisi data nim, nilai1, dan nilai2, serta deklarasi dua fungsi yaitu inputMhs dan rata2. inputMhs untuk meminta user menginputkan nim dan dua buah nilai. Fungsi rata2 untuk menghitung nilai rata-rata dari nilai yang diinputkan. Pada file main, program membuat variabel mhs yang bertipe mahasiswa, memanggil fungsi inputMhs, dan memenaggil fungsi rata2 untuk menampilkan hasil perhitungan.


## Unguided 

### 1. Soal unguided 1
Buat program yang dapat menyimpan data mahasiswa maksimal 10 ke dalam sebuah array dengan field nama, nim, uts, uas, tugas dan nilai akhir. nilai akhir yang diperoleh dengan rumus 0.3*uts + 0.4*uas + 0.3*tugas.

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilai(float uts, float uas, float tugas){
    return(0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main(){

    mahasiswa mhs[10];
    int n;
    cout << "Masukan jumlah mahasiswa : " ;
    cin >> n;

    if (n > 10){
        cout << "Jmlah masiswa melebihi batas " << endl;
        return 0;
    }
    for (int i = 0; i < n; i++){
        cout << "Data mahasiswa ke " << i+ 1 << endl;
        cout << " Masukan nama : ";
        cin >> mhs[i].nama;
        cout << "Masukan NIM : ";
        cin >> mhs[i].nim;
        cout << "Masukan nilai UTS : ";
        cin >> mhs[i].uts;
        cout << "Masukan nilai UAS : ";
        cin >> mhs[i].uas;
        cout << "Masukan nilai tugas : ";
        cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungNilai(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    cout << " Data nilai mahasiswa : "<< endl;
    
    for(int i = 0; i < n; i++){
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "------------------------" << endl;
    }

    return 0;


}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan3_modul3/Output_unguided1_modul3.png)

Program ini untuk menginput dan menghitung nilai akhir beberapa mahasiswa(maksimal 10) berdasarkan nilai uts, uas, dan tugas. Struct mahasiswa untuk menyimpan data mahasiswa yang terdiri dari nama, nim, nilai uts, nilai uas, nilai tugas, dan nilai akhir. Program meminta user menginputkan data mahasiswa. Nilai akhir dihitung dengan fungsi hitungNilai.
### 2. soal unguided 2
Buatlah ADT pelajaran dengan file "pelajaran.h" lalu buat implementasi ADT pelajran dalam file "pelajaran.cpp" lalu coba hasil implementasi ADT dalam file "main.cpp"

"pelajaran.h"
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran{
    string namaMapel, kodeMapel;
};
pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);
#endif
```
"pelajaran.cpp"
```C++
#include"pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namaMapel, string kodeMapel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}
void tampil_pelajaran (pelajaran pel){
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Nilai : " << pel.kodeMapel << endl;
}
```
"main.cpp"
```C++
#include "pelajaran.h"
#include "pelajaran.cpp"

using namespace std;
int main(){
    string namapel = "Struktur data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;

}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutia1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan3_modul3/Output_unguided2_modul3.png)

Program ini untuk mengelola dan menampilkan data pelajaran, program dibuat dalam tiga fike, yaitu file header (pelajaran.h), file implementasi (pelajaran.cpp), dan file utama (main.cpp). Dalam file header, didefinisikan struktur pelajaran yang berisi dua atribut, yaitu namaMapel untuk menyimpan nama mata pelajaran dan kodeMapel untuk menyimpan kode pelajaran. Fungsi create_pelajaran untuk membuat data pelajaran baru dan tampil_pelajaran untuk menampilkan data tersebut. Pada file implementasi (pelajaran.cpp), fungsi create_pelajaran digunakan untuk mengisi nilai atribut namaMapel dan kodeMapel. Fungsi tampil_pelajaran berfungsi menampilkan nama pelajaran dan kodenya ke layar. Di bagian main(), program membuat satu data pelajaran dengan nama “Struktur Data” dan kode “STD”.

### 3. soal unguided 3

```C++
#include<iostream>
using namespace std;

void tampilArray(int arr[3][3]){ // ini buat nampillin array
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";

        }
        cout << endl;
    }
}

void tukarNilai(int arr1[3][3], int arr2[3][3], int nilaiA, int nilaiB){ // inibuat neker array
    int *x1  = nullptr;
    int *x2 = nullptr;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(arr1[i][j] == nilaiA){
                x1 = &arr1[i][j];
            }
        }
    } 

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(arr2[i][j] == nilaiB){
                x2 = &arr2[i][j];
            }
        }
    }

    if (x1 != nullptr && x2 != nullptr){
        int temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }else{
        cout << "Nilai tidak ditemukan pada array" << endl;
    }
}


    

int main(){
    int arrA[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    
    };
    int arrB[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };

    cout << "Array A : " << endl;
    tampilArray(arrA);
    cout << "Array B : " << endl;
    tampilArray(arrB);

    int nilaiA, nilaiB;
    cout << "Masukan nilai dari array A : ";
    cin >> nilaiA;
    cout << "Masukan nilai dari array B : ";
    cin >> nilaiB;
    tukarNilai(arrA, arrB, nilaiA, nilaiB);
    cout << "Array A setelah ditukar : " << endl;
    tampilArray(arrA);
    cout << "Array B setelah ditukar : " << endl;
    tampilArray(arrB);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mutia1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan3_modul3/Output_unguided3_modul3.png)

Program ini untuk menampilkan dua buah array dua dimensi (3×3) dan menukar satu elemen dari array pertama dengan satu elemen dari array kedua berdasarkan nilai yang dimasukkan oleh pengguna. Fungsi tampilArray digunakan untuk menampilkan isi array dalam bentuk matriks 3×3 ke layar. Fungsi tukarNilai berfungsi untuk mencari nilai tertentu di masing-masing array, kemudian menukar posisi kedua nilai tersebut. Pencarian dilakukan dengan cara memeriksa setiap elemen array menggunakan perulangan for, dan jika ditemukan nilai yang sesuai, program menyimpan alamat memori elemen tersebut menggunakan pointer (int *x1 dan int *x2). Setelah kedua nilai ditemukan, isi keduanya ditukar menggunakan variabel sementara (temp). Pada fungsi main, dua buah array dideklarasikan dan diisi dengan angka berbeda. Program menampilkan isi awal kedua array, kemudian meminta pengguna memasukkan satu nilai dari arrA dan satu nilai dari arrB yang ingin ditukar. Setelah proses pertukaran dilakukan, program menampilkan isi kedua array kembali untuk menunjukkan hasil perubahan.

## Kesimpulan
Tipe data adalah klasifikasi yang menentukan jenis nilai spesifik yang dapat disimpan oleh sebuah variabel, memastikan bahwa variabel memiliki nilai yang jelas dan terdefinisi saat digunakan dalam program. Sementara itu, Tipe Data Abstrak (ADT) adalah sebuah konsep yang melengkapi tipe data standar. ADT didefinisikan secara khusus oleh pemrogram untuk mengakomodasi kebutuhan yang tidak tercakup oleh bahasa pemrograman. Fungsi utama ADT adalah untuk menyempurnakan tipe data dengan menggabungkan data tersebut dengan fungsi-fungsi (operasi) yang dapat bekerja pada data bersangkutan, sehingga mempermudah proses pemrograman dan meningkatkan abstraksi.

## Referensi
[1] Putra, M. T. D., Pradeka, D., & Yuniarti, A. R. (2022). BELAJAR DASAR PEMROGRAMAN DENGAN C++.<br>
[2] Triase. (2020). Diktat Edisi Revisi Struktur Data. Universitas Islam Negeri Sumatera Utara.<br>
