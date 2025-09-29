# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Mutiara Fauziah  - 103112400197</p>

## Dasar Teori

Algoritma adalah langkah-langkah untuk memecahkan masalah. Algoritma dibutuhkan untuk memerintah komputer mengembil langkah-langkah tertentu dalam menyelesaikan masalah.[1]

### A. Dasar pemprograman <br/>

...

#### 1. Struktur C++

Perintah #include <iostream> adalah oerintah untuk memanggil library, maksudnya kita akan memanggil dan menggunakan isi library.
Fungsi main adalah titik awal program dijalankan.[2]

#### 2. Tipe data

Tipe data adalah jenis tempat penyimpanan data.[2]

#### 3. Variabel

Variabel adalah tempat menyimpan data. Variabel dapat diisi angka, huruf, karakter lain tergantung tipe datanya.[2]

#### 4. Konstanta

konstanta adalah jenis identifier yang bersifat konstan yang artinya nilai dalam variabel tidak dapat diubah.[2]

### B. Input dan output<br/>

...

#### 1. Fungsi cout

Fungsi cout adalah perintah untuk menampilkan teks dilayar.[3]

#### 2. Fungsi cin

Fungsi cin untuk menerima masukan dari user.[4]

### C. Operator <br/>

...

#### 1. Operator Aritmatika

Operator artimatika digunakan untuk perhitungan aritmatika yang terdiri dari beberapa jenis antara lain pembagian, pemjumlahan, perkalian, pengurangan, dan sisa pembagian.[5]

#### 2. Operator Logika

Operator logika adalah operasi yang hanya memberikan hasil benar atau salah. Operator logika terdiri dari "dan/end"(&&), "atau/or",(||), dan !(not).[5]

### D. Kondisional <br/>

...

#### 1. If - else

if-else adalah salah satu bentuk conditional statement paling dasar dalam C++. Ini memungkinkan program untuk memilih di antara dua blok kode yang akan dieksekusi berdasarkan kondisi yang dievaluasi.[6]

#### 2. Switch - case

Switch memungkinkan Anda mengeksekusi kode yang berbeda berdasarkan nilai yang Anda berikan. Switch biasanya digunakan untuk menangani situasi yang memerulukan tindakan berbeda dari beberapa kondisi.[6]

### E. Perulangan

...

#### 1. For loop

For adalah jenis loop yang umum untuk mengulang kode program sejumlah kali dengan menggunakan variabel yang diinisialisasi, kondisi loop dan perubahan variabel iterasi.Variabel iterasi dimulai dengan nilai awal pada awal loop. Kemudian kondisi loop diperiksa, dan jika kondisi terpenuhi, kode program akan dieksekusi. Setelah setiap iterasi, variabel iterasi diubah dengan perubahan yang telah ditentukan sebelumnya. Selama kondisi loop tidak terpenuhi, loop For akan berlanjut.[6]

#### 2. While loop

Loop while dapat digunakan untuk mengulang kode program dengan kondisi yang diuji setiap loop.Loop while trerdiri dari tiga bagian utama, yaitu deklarasi loop, kondisi loop, perubahan variabel.[6]

## Guided

### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukan angka 1 : ";
    cin >> angka1;
    cout << "angka yang dimasukan 2 ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian :  " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    return 0;

}
```

Guided 1 membahas operasi aritmatika

### 2. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukan angka 1 : ";
    cin >> angka1;
    cout << "masukan angka 2 : ";
    cin >> angka2;

    if (angka1 < angka2){
        cout << angka1 << " kurang dari " << angka2 << endl;
    }else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    }else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "masukan pilhan : " << endl;
    cin >> pilihan ;

    switch(pilihan){
        case 1:
        cout << "penjumlahan : " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2 :
        cout << "pengurangan : " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default :
        cout << "pilihan salah" << endl;


    }
    return 0;

}
```

Guided 2 membahas percabangan

### 3. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukan angka 1 : ";
    cin >> angka1;

    for(int i = 0; i < angka1; i++ ){
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while(j > angka1){
        cout << j << " - ";
        j--;
    }
    cout << endl;

    int k = 10;
    do{
        cout << k << " - ";
    }while(k < angka1);

    return 0;

}
```

Guided 3 membahas perulangan

## Unguided

### 1. soal unguided 1

Buatkah program yang menerima input an dua buah bilangan bertipe float, kemudian memberikan output hasil
penjumlahan, perkalian, pengurangan, dan pembagian dari dua buah bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main(){
    float x, y;
    cout << "Masukan bilangan pertama : ";
    cin >> x;
    cout << "Masukan bilangan kedua : ";
    cin >> y;

    cout << "Penjumlahan : ";
    cout  << x + y << endl;
    cout << "Pengurangan : " ;
    cout << x - y << endl;
    cout << "Perkalian : ";
    cout  << x * y << endl;
    cout << "Pembagian : ";
    cout << x / y << endl;
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan1_modul1/Output-unguide1-modul1.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini meminta user menginputkan dua buah bilangan, lalu program memproses dengan melakukan operasi penjumlahan, pengurangan, perkalian, dan pembagian. Kemudian hasil ditampilkan dari masing-masing operasi aritmatika.

### 2. Soal unguided 2

Buat program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. angka yang diinputkan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;


string ratus [] = {"", "seratus", "dua ratus", "tiga ratus", "empat ratus", "lima ratus", "enam ratus", "tujuh ratus", "delapan ratus", "sembilan ratus"};
string puluh [] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
string satuan [] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan [] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};

int main(){
    int angka;
    cout << "Masukan angka : ";
    cin >> angka;

    if(angka < 1 || angka > 999){
        cout << "Angka diluar jangkauan" << endl;
        return 0;
    }

    if(angka / 100 > 0){
        cout << ratus[angka /100 ] << " ";
    }

    if( (angka %100)/10 == 1){
        cout << belasan[(angka %100)/10] << " ";
    } else {
        if((angka %100)/10 > 1){
            cout << puluh[(angka %100)/10] << " ";
        }
        if(angka % 10 > 0){
            cout << satuan[angka % 10] << " ";
        }
    }

    cout << endl;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan1_modul1/Output-unguided2-modul1.png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguzaided2-1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini meninta user menginputkan sebuah bilangan lalu program akan memproses, lalu output yang dihasilkan berupa nilai yang di inputkan tetapi berupa tulisan.

### 3. Soal unguided 3

Buatlah program yang memberikan input dan output sbb

```C++
#include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Masukan angka : ";
    cin >> x;

    for(int i = x; i >= 1; i--){
        for(int k = 0; k < x - i;k++){
            cout << " ";
        }
        for(int j = i; j >= 1; j--){
           cout << j;
        }
        cout << "*";


        for(int j = 1; j <= i; j++){
            cout << j;
        }
        cout << endl;

    }
    for (int sp = 0 ; sp < x; sp++){
        cout << " ";
    }
    cout << "*" << endl;
    return 0;

}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan1_modul1/Output-unguided3-modul1.png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini meminta user menginputkan sebuah bilangna lalu program akan melakukan perulangan sesuai dengan inputan user dan ooutput yang dihasilkanya berupa pola segitiga terbalik dengan bintang ditengahnya

## Kesimpulan

Algoritma merupakan dasar penyusunan langkah-langkah untuk memecahkan masalah dengan komputer. Dalam C++, program dijalankan melalui fungsi main dengan dukungan library seperti #include <iostream>. Data dalam program diatur menggunakan tipe data, variabel, dan konstanta. Interaksi dengan pengguna dilakukan melalui cin (input) dan cout (output). Operasi dalam program dapat memanfaatkan operator aritmatika maupun logika untuk melakukan perhitungan dan pengambilan keputusan. Struktur kontrol seperti if-else dan switch memungkinkan pemilihan alur eksekusi program berdasarkan kondisi tertentu. Sementara itu, perulangan (for dan while) digunakan untuk mengulang eksekusi kode secara efisien dengan syarat dan perubahan variabel yang ditentukan. Dengan memahami konsep-konsep dasar ini, pemrogram dapat menulis program C++ yang terstruktur, logis, dan mampu menyelesaikan berbagai permasalahan komputasi.

## Referensi

[1] Esabella dan Haq. (2021). "Dasar-Dasar Pemprograman". Olat Maras Publishing.<br>
[2] Nugraha,Muhammad. (2021)."Dasar Pemrograman Dengan C++ Materi Paling Dasar Untuk Menjadi Programmer Berbagai Platform".Deepublish.<br>
[3] Hanief, Shofwan, dan I Wayan Jepriana.(2020). "Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++". Penerbit Andi. <br>
[4] Sianipar, Rismon Hasiholan.(2012)."Pemrograman C++ : Dasar Pemrograman Berorientasi Objek".Penerbit Andi. <br>
[5] Anam, Syaiful, Indah Yanti, Zuraidah Fitriah, dan Ummu Habibah.(2021)."Cara Mudah Belajar Bahasa Pemrograman C++".Universitas Brawijaya Press<br>
[6] Harnadi, Bernardinus, Antonius Eldy Putra, Wilibrordus Endra Bima, dkk.(2025)."Dasar Pemrograman Logika Dengan C++". Semarang: Siega Publisher.
