#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

const int MAX = 6;

// Define struct for student data
struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top = -1;
};

// Function Prototypes
bool isEmpty(StackMahasiswa& StackMHS);
bool isFull(StackMahasiswa& StackMHS);
void createStack(StackMahasiswa& StackMHS);
void push(StackMahasiswa& StackMHS, Mahasiswa m);
void pop(StackMahasiswa& StackMHS);
void view(StackMahasiswa& StackMHS);
void update(StackMahasiswa& StackMHS, int posisi, Mahasiswa m);
void searchNilaiAkhir(StackMahasiswa& StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);

#endif