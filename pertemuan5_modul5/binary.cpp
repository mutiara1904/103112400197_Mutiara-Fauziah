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
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Implementasi Binary Search pada Linked List
Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    // Hitung ukuran linked list
    int size = 0;
    for (Node* current = head; current; current = current->next)
        size++;
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        // Pindah ke node tengah
        for (int i = 0; i < mid; i++)
            midNode = midNode->next;
        
        // Jika ketemu
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        // Jika mid lebih kecil dari key → cari di kanan
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) return lastNode;
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            start = midNode->next;
            size = newSize;
        }
        // Jika mid lebih besar dari key → cari di kiri
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            if (mid == 1) {
                if (start->data == key) return start;
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

// Tambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Hapus semua node (bebaskan memori)
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main program
int main() {
    Node* head = nullptr;
    int searchKey;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    // Membuat linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    // Tampilkan list
    displayList(head);
    
    // 🔹 Pencarian pertama
    searchKey = 40;
    cout << "Mencari nilai: " << searchKey << "\n";
    
    Node* result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    // 🔹 Pencarian kedua
    searchKey = 25;
    cout << "Mencari nilai: " << searchKey << "\n";
    
    result = binarySearch(head, searchKey);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << searchKey << " TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    deleteList(head);
    return 0;
}
