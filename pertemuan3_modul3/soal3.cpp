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