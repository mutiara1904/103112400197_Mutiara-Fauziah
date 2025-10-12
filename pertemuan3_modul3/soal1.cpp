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
        cout << "Masukan nama : ";
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