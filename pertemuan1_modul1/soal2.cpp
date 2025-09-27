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