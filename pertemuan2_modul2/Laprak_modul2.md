# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Struktur data menjelaskan koleksi atau kelompok data yang dapat dibedakan oleh organisasi dan operasi yang dilakukan terhadapnya. 
Penggunaan struktur data yang tepat selama proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, 
sehingga menjadikan program secara keseluruhan lebih sederhana.[1]

### A. Array<br/>
Array adalah struktur yang terdiri dari sejumlah elemen dengan tipe data yang sama yang disusun secara sekuensial dalam memori komputer.
Semua elemen array bertipe sama dan digunakan untuk mengorganisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui sejak awal. 
Array dibagi menjadi empat, yaitu array satu dimensi, dua dimensi, tiga dimensi, dan banyak dimensi.[1]

### B. Pointer<br/>
Pointer adalah variabel penunjuk yang memiliki alamat lokasi memori tertentu. Pointer tidak memiliki nilai dari variabel yang telah dideklarasikan, tetapi memiliki alamat memori.
Dengan menggunakan pointer, Anda dapat mendapatkan atau mengubah isi memori yang ditunjuk.[2]

### C. Fungsi <br/>
Fungsi adalah blok program yang melakukan suatu aksi tertentu berdasarkan input yang diterima dan mengembalikan nilai ketika deklarasinya dipanggil dalam program.
Fungsi dapat dipanggil dan digunakan di dalam blok kode program utama atau di dalam blok kode yang sama.[2]
### D. Prosedur <br/>
Proses dapat mengembalikan atau tidak mengembalikan nilai atau hasil; untuk melakukannya, diperlukan suatu variabel tertentu. 
Proses pencetakan hasil atau nilai disimpan dalam blok subrutinnya sendiri di program utama, yang kemudian diberi nama prosesnya.[3]




## Guided 

### 1. ...

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masuka value index ke- " << i << ":";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << ":" << arr[j] << endl;
        j++;
    }
    
    return 0;
}
```
program ini berfungsi untuk meminta input 5 nilai dari user, menyimpannya ke dalam array, lalu menampilkan kembali isi array tersebut.

### 2. ...

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr [2][2]){
    for (int  i = 0;i < 2; i++) {
        for (int j = 0; j < 2; j++){
            cout << arr [i][j] << " ";
        }
        cout << endl;
    }

}
    
int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
     int arrB [2][2] = {
        {2, 3},
        {4, 5}
    };

    int arrC [2][2] = {0};
    int arrD [2][2] = {0};

    // penjumlahan array
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "hasil penjumlahan :  " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    // perkalian matriks
    for (int i = 0; i < 2; i++){ //baris
        for (int j = 0; j < 2; j++){ // kolom
            for (int k = 0; k < 2; k++){ //perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrD);
    return 0;

}
```
Program ini dibuat untuk menghitung penjumlahan dan perkalian dua matriks berukuran 2x2 dengan menjumlahkan setiap elemen pada posisi yang sama di kedua matriks. Kemudian, program melakukan perkalian matriks dengan menggunakan aturan perkalian baris dan kolom matriks, lalu hasilnya dimasukkan ke dalam arrD. Fungsi tampilkanHasil mencetak isi matriks.

### 3. ...

```C++
#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++ ){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan :" << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran ; i++){
        cout << " masukan nlia array ke-" << i << ":";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program ini berfungsi untuk melakukan operasi sederhana pada array yang terdiri dari lima angka yang diberikan oleh user. Fungsi operasi aritmetika melakukan dua perhitungan: menghitung jumlah seluruh elemen array dan menghitung hasil perkalian seluruh elemen array; setelah pengguna memasukkan nilai-nilai array, program akan menggunakan fungsi cariMAX untuk menemukan nilai terbesar.

### 4. ...
```C++
#include<iostream>
using namespace std;

int main(){
    int arr [] = {10,20,30,40,50};
    int *ptr = arr;

    for(int i = 0; i < 5; i++){
        cout << " element array ke-" << i+1 << " menggunakan pointer :" << *(ptr + i) << endl;

    }

    for(int i = 0; i < 5; i++){
        cout << " element array ke : " << i+1 << " menggunkan indeks :" << arr[i] << endl;
    }
    return 0;
}
```
Program berfungsi untuk menampilkan isi sebuah array dengan  menggunakan pointer dan menggunakan indeks array. Program mendefinisikan array arr yang terdiri dari lima bilangan, lalu membuat pointer ptr yang menunjuk ke alamat elemen pertama array. Pada perulangan pertama, program menampilkan setiap elemen array dengan memanfaatkan pointer, di mana ekspresi *(ptr + i) digunakan untuk mengakses elemen ke-i. Selanjutnya, pada perulangan kedua, program menampilkan elemen array dengan cara biasa menggunakan indeks, yaitu arr[i]. 
### 5. ...
```C++
#include<iostream>
using namespace std;

void ubahNilai(int *ptr){
    *ptr = 20;
}

int main(){
    int x = 10;
    cout << "nilai sebelum diubah :" << x << endl;

    ubahNilai(&x);
    cout << "nilai setelah diubah : " << x << endl;
    return 0;
}
```
Program menunjukkan cara menggunakan pointer untuk mengubah nilai variabel di dalam sebuah fungsi.Variabel x diberi nilai 10, kemudian fungsi ubahNilai dipanggil dengan mengirimkan alamat variabel x.Dalam fungsi tersebut, pointer ptr digunakan untuk mengakses alamat x dan mengganti nilainya menjadi 20. Setelah fungsi selesai, nilai x di main berubah menjadi 20, lalu ditampilkan ke layar.
### 6. ...
```C++
#include<iostream>
using namespace std;

void ubahNilai(int &ref){
    ref = 20;
}

int main(){
    int x = 10;
    cout << "nilai sebelum diubah :" << x << endl;

    ubahNilai(x);
    cout << "nilai setelah diubah : " << x << endl;
    return 0;
}                             
```
Program menunjukkan cara menggunakan reference untuk mengubah nilai variabel di dalam sebuah fungsi. Variabel x diberi nilai 10 . Fungsi ubahNilai menerima parameter berupa reference (int &ref), sehingga ketika fungsi dipanggil dengan ubahNilai(x), variabel x diakses langsung melalui reference tersebut. Di dalam fungsi, nilai ref diubah menjadi 20, yang otomatis juga mengubah nilai x karena reference menunjuk langsung ke variabel aslinya. Setelah fungsi dijalankan, nilai x berubah menjadi 20 dan ditampilkan ke layar.

## Unguided 

### 1. Soal unguided 1
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan;
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case.

```C++
#include<iostream>
using namespace std;

void tampilHasil(int arr [3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr [i][j] << " ";
        }
        cout << endl;
    }

}

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = arrA[i][j] + arrB[i][j];
        }

    }
}
void kurangMatriks(int arrA[3][3], int arrB[3][3], int hasil[3][3]){
    for (int i = 0;i <3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
}

void kaliMatriks(int arrA[3][3], int arrB[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                hasil[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
}

int main(){
    int arrA [3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB [3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int hasil[3][3] = {0};

    int pilihan;
    cout << " --- Menu Program Matriks --- " << endl;
    cout << " 1. Penjumlahan matriks " << endl;
    cout << " 2. Pengurangan matriks " << endl;
    cout << " 3. Perkalian matriks " << endl;
    cout << " 4. Keluar " << endl;
    cout << " Masukan angka : " << endl;
    cin >>  pilihan ;

    switch (pilihan){
        case 1 :
        jumlahMatriks(arrA, arrB, hasil);
        cout << "Hasil penjumlahan matriks : " << endl;
        tampilHasil(hasil);
        break;
        case 2 :
        kurangMatriks(arrA, arrB, hasil);
        cout << "Hasil pengurangan matriks : " << endl;
        tampilHasil(hasil);
        break;
        case 3 :
        kaliMatriks(arrA, arrB, hasil);
        cout << "Hasil perkalian matriks : " << endl;
        tampilHasil(hasil);
        break;
        case 4 :
        cout << "Keluar " << endl;
        break;
        default :
        cout << " pilihan salah " << endl;
    }
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan2_modul2/Output1_unguided1_modul2.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan2_modul2/Output2_unguided1_modul2.png)

Program ini untuk melakukan penjumlahan, pengurangan dan perkalian matriks 3x3 dengan prosedur. Kemudian user akan memilih menu dengan memasukan angka sesuai yang ada sesuai dengan keinginan user, satu untuk menampilkan penjumlhan, dua untuk menampilkan pengurangan,tiga unutk menampilkan perkalian, dan empat untuk keluar dari program.

### 2. Soal unguided 2
Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan
dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.

```C++
#include<iostream>
using namespace std;

int main(){
    int panjang = 10, lebar = 5 ;
    int *ptrPanjang, *ptrLebar;

    cout << " --- Nilai Awal --- " << endl;
    cout << " Panjang : " << panjang << endl;
    cout << " Lebar : " << lebar << endl;

    ptrPanjang = &panjang;
    ptrLebar = &lebar;

    int luas = (*ptrPanjang) * (*ptrLebar);
    int keliling = 2 * (*ptrPanjang + *ptrLebar);

    cout << " --- Hasil Perhitungan --- " << endl;
    cout << " Luas Persegi Panjang : " << luas << endl;
    cout << " Keliling Persegi Panjang : " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

   luas = (*ptrPanjang) * (*ptrLebar);
   keliling = 2 * (*ptrPanjang + *ptrLebar);

   cout << " --- Nilai Setelah Diubah Melalui Pointer --- " << endl;
   cout << " Panjang Baru : " << *ptrPanjang << endl;
   cout << " Lebar Baru : " << *ptrLebar << endl;
   cout << " Luas  Baru : " << luas << endl;
   cout << " Keliling Baru : " << keliling << endl;
    


    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan2_modul2/Output_unguided2_modul2.png)

Program ini berfungsi untuk menghitung luas dan keliling persegi panjang dengan menngunakan pointer. Variabel panjang bernilai 10 dan lebar bernilai 5. *ptrPanjang merujuk pada variabel panjang dan *ptrLebar merujuk pada variabel lebar. Kemudian dihitung, lalu hasilnya ditampilkan. Setelah ditampilkan nilai panjang dan lebar diubah menjadi 12 dan 6, lalu dicetak nilai baru dengan pointer.



## Kesimpulan
Struktur data mendefinisikan cara pengorganisasian data, yang jika digunakan secara tepat akan menghasilkan algoritma yang lebih efisien. 
Salah satu struktur dasar adalah Array, yang merupakan koleksi data homogen dengan tipe sama yang disimpan secara berurutan di memori dan ukurannya ditentukan di awal. 
Berbeda dengan data biasa, Pointer adalah variabel penunjuk yang menyimpan alamat lokasi memori tertentu, memungkinkan program untuk mengakses dan memanipulasi data secara langsung. 
Sementara itu, Fungsi berfungsi sebagai blok program modular yang melakukan aksi spesifik berdasarkan input, yang dapat mengembalikan nilai hasil atau sekadar menjalankan suatu proses.

## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.<br>
[2] Putra, M. T. D., Munawir, M., & Yuniarti, A. R. (2023). BELAJAR PEMROGRAMAN LANJUT DENGAN C++.<br>
[3] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Umsida Press, 1-146.<br>

