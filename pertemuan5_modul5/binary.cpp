#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node* next; // pointer ke node berikutnya
};

// Fungsi untuk menampilkan linked list
void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Implementasi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    // Hitung ukuran linked list
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        // Pindah ke node tengah
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        // Cek apakah data ditemukan
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        // Jika data midNode lebih kecil dari key, cari di bagian kanan
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) {
                    return lastNode;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            start = midNode->next;
            size = newSize;
        }
        // Jika data midNode lebih besar dari key, cari di bagian kiri
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            if (mid == 1) {
                if (start->data == key) {
                    return start;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            size = mid;
        }
        
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}

// Prosedur untuk menambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk membersihkan memori
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int searchKey;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    // Data linked list sudah ditentukan dari awal
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Tampilkan isi linked list
    displayList(head);
    
    // 🔹 Pencarian pertama (otomatis mencari 40)
    searchKey = 40;
    cout << "\nMencari nilai: " << searchKey << endl;
    
    Node* result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // 🔹 Pencarian kedua (otomatis mencari 25)
    searchKey = 25;
    cout << "\nMencari nilai: " << searchKey << endl;
    
    result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // Bersihkan memori
    deleteList(head);
    
    return 0;
}
