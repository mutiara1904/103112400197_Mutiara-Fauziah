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