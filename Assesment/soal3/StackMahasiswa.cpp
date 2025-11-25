#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

// Check if the stack is empty
bool isEmpty(StackMahasiswa &StackMHS) {
    return (StackMHS.Top == -1);
}

// Check if the stack is full
bool isFull(StackMahasiswa &StackMHS) {
    return (StackMHS.Top == MAX - 1);
}

// Initialize the stack
void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
}

// Insert data (push) into the stack
void push(StackMahasiswa &StackMHS, Mahasiswa m) {
    if (isFull(StackMHS)) {
        cout << "Stack is full!" << endl;
    } else {
        StackMHS.Top++;
        StackMHS.dataMahasiswa[StackMHS.Top] = m;
    }
}

// Remove data (pop) from the stack
void pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack is empty!" << endl;
    } else {
        StackMHS.Top--;
    }
}

// View all data in the stack
void view(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack is empty!" << endl;
    } else {
        for (int i = 0; i <= StackMHS.Top; i++) {
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << ", NIM: " << StackMHS.dataMahasiswa[i].NIM 
                 << ", Nilai Tugas: " << StackMHS.dataMahasiswa[i].NilaiTugas << ", Nilai UTS: " 
                 << StackMHS.dataMahasiswa[i].NilaiUTS << ", Nilai UAS: " << StackMHS.dataMahasiswa[i].NilaiUAS << endl;
        }
    }
}

// Update student data at a specific position
void update(StackMahasiswa &StackMHS, int posisi, Mahasiswa m) {
    if (posisi < 0 || posisi > StackMHS.Top) {
        cout << "Invalid position!" << endl;
    } else {
        StackMHS.dataMahasiswa[posisi] = m;
    }
}

// Search and display students with NilaiAkhir within the range [min, max]
void searchNilaiAkhir(StackMahasiswa& StackMHS, float NilaiAKhirMin, float NilaiAkhirMax) {
    for (int i = 0; i <= StackMHS.Top; i++) {
        float nilaiAkhir = (StackMHS.dataMahasiswa[i].NilaiTugas * 0.2) + (StackMHS.dataMahasiswa[i].NilaiUTS * 0.4) + (StackMHS.dataMahasiswa[i].NilaiUAS * 0.4);
        if (nilaiAkhir >= NilaiAKhirMin && nilaiAkhir <= NilaiAkhirMax) {
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << ", NIM: " << StackMHS.dataMahasiswa[i].NIM
                 << ", Nilai Akhir: " << nilaiAkhir << endl;
        }
    }
}