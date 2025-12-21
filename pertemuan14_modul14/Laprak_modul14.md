# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Mutiara Fauziah - 103112400197</p>

## Dasar Teori
Linked List adalah jenis struktur data linier di mana setiap elemen tidak disimpan di tempat yang berdekatan, melainkan dihubungkan melalui pointer. Linked List terdiri dari rangkaian node yang saling terhubung, di mana setiap node berisi data dan alamat node berikutnya [1].


### A. Graph <br/>
Graph adalah jenis struktur data umum yang data dalam graph tidak terletak secara berdekatan satu sama lain, artinya data disusun secara non-linier. Graph terdiri dari sekelompok simpul yang digunakan untuk menyimpan data, dan antara dua simpul terdapat hubungan yang saling terkait. Berdasarkan arah penjelajahan, graph dibagi menjadi dua jenis yaitu graph tak berarah dan graph berarah [2].

## Guided 

### 1. Soal guided 1
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
  adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);
#endif
```
graph_edge.cpp
```C++
#include "graph.h"
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL){
        if(P->info == X){
            P = P -> next;
        }
        return NULL;
    }
}
void connectNode(Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if(pStart != NULL && pEnd != NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;//insert first di list edge
        pStart->firstEdge = newEdge;
    }
    
}

```
graph_init.cpp
```C++
#include "graph.h"
void createGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;

    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node" << P->info << "Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

```
main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph G;
    createGraph(G);

    insertNode(G, 'A');//nambah node A,B,C,D
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    //hub8ngkan node gd edge
    connectNode(G,'A','B'); // A ke B
    connectNode(G,'A','C'); // A ke C
    connectNode(G, 'B','D'); // B ke D
    connectNode(G, 'C','D'); // C ke D

    cout << "Isi graph :" << endl;
    printGraph(G);

}
```
Program ini merupakan implementasi struktur data graph berarah menggunakan linked list, di mana setiap node menyimpan informasi berupa karakter serta daftar edge yang menunjukkan hubungan ke node lain. Graph diawali dalam keadaan kosong, kemudian ditambahkan node A, B, C, dan D, setelah itu dibuat hubungan A ke B, A ke C, B ke D, dan C ke D menggunakan edge satu arah. Setiap node menyimpan daftar node tujuan yang terhubung dengannya dalam bentuk adjacency list. Terakhir, isi graph ditampilkan dengan mencetak setiap node beserta node-node yang terhubung, sehingga terlihat jelas struktur hubungan antar node dalam graph tersebut.


## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Graph tidak berarah file “graph.h”.Buatlah implementasi ADT Graph pada file“graph.cpp” dan cobalah hasil implementasi ADT
pada file “main.cpp”.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
#endif           
```
graph.cpp
```C++
#include "graph.h"
void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
```
main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);
    PrintInfoGraph(G);
    return 0;

}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/mutiara1904/10311240197_Mutiara-Fauziah/blob/main/pertemuan14_modul14/Output_unguided1_modul14.png)

Program tersebut merupakan implementasi struktur data graph tak berarah (undirected graph) menggunakan linked list dalam bahasa C++. Graph dibangun dari node-node yang menyimpan informasi berupa karakter dan daftar edge sebagai adjacency list. Program diawali dengan membuat graph kosong, kemudian menambahkan node A hingga H. Setiap node dihubungkan menggunakan fungsi ConnectNode yang membuat dua edge sekaligus sehingga hubungan bersifat dua arah. Setelah seluruh hubungan antar node terbentuk, fungsi PrintInfoGraph digunakan untuk menampilkan setiap node beserta node-node lain yang terhubung dengannya. Program ini menunjukkan cara membangun, menghubungkan, dan menampilkan graph tak berarah menggunakan struktur data linked list.

### 2. Soal unguided 2
Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
void printDFS(Graph G, adrNode N);                     
void Visited(Graph &G);
#endif           
```
graph.cpp
```C++
#include "graph.h"
void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void Visited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = 0;
        P = P->next;
    }
}

void printDFS(Graph G, adrNode N){
    if(N != NULL && N->visited == 0){
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while(E != NULL){
            if(E->node->visited == 0){
                printDFS(G, E->node);
            }
            E = E->next;
        }
    }
}
```
main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);

    Visited(G);
    cout << "Hasil penulusuran DFS : " ;
    printDFS(G, a);
    cout << endl ;
    //PrintInfoGraph(G);
    return 0;

}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan14_modul14/Output_unguided2_modul14.png)

Program ini merupakan implementasi graph tak berarah (undirected graph) menggunakan linked  dengan penelusuran Depth First Search (DFS). Graph dibangun dengan menambahkan node A hingga H, lalu menghubungkannya secara dua arah menggunakan fungsi ConnectNode, sehingga setiap hubungan antar node dapat ditelusuri bolak-balik. Setiap node memiliki penanda visited untuk menghindari kunjungan berulang saat proses DFS. Fungsi Visited digunakan untuk menginisialisasi semua node agar belum dikunjungi, kemudian fungsi printDFS melakukan penelusuran graph secara mendalam mulai dari node A dengan mencetak urutan node yang dikunjungi.

### 3. Soal unguided 3
Buatlah prosedur untuk menampilkan hasil penelusuran BFS.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
void printBFS(Graph G, adrNode N);                     
void Visited(Graph &G);
#endif           
```
graph.cpp
```C++
#include "graph.h"
#include<queue>

void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void Visited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = 0;
        P = P->next;
    }
}
void printBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    queue<adrNode> Q;

    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```
main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);

    Visited(G);
    cout << "Hasil penulusuran BFS : " ;
    printBFS(G, a);
    cout << endl ;
    
    return 0;

}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/mutiara1904/103112400197_Mutiara-Fauziah/blob/main/pertemuan14_modul14/Output_unguided3_modul14.png)

Program ini merupakan implementasi graph tak berarah (undirected graph) menggunakan linked list dengan algoritma Breadth First Search (BFS). Graph dibentuk dengan menambahkan node A hingga H dan menghubungkannya secara dua arah menggunakan fungsi ConnectNode, sehingga setiap node memiliki daftar tetangga (adjacency list). Setiap node memiliki atribut visited untuk menandai apakah node sudah dikunjungi atau belum. Sebelum BFS dijalankan, fungsi Visited digunakan untuk menginisialisasi semua node menjadi belum dikunjungi. Fungsi printBFS kemudian melakukan penelusuran graph secara melebar menggunakan struktur data queue, dimulai dari node A, dan mencetak urutan node yang dikunjungi.

## Kesimpulan
Linked List dan graph merupakan struktur data yang digunakan untuk mengelola data secara fleksibel. Linked List adalah struktur data linier yang tersusun dari rangkaian node yang saling terhubung melalui pointer, di mana setiap node berisi data dan alamat node berikutnya sehingga elemen tidak disimpan secara berdekatan. Sementara itu, graph merupakan struktur data non-linier yang terdiri dari simpul-simpul (node) dan hubungan antar simpul (edge) untuk merepresentasikan keterkaitan data, serta berdasarkan arah hubungan tersebut, graph dibedakan menjadi graph berarah dan graph tak berarah.

## Referensi
[1]Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).<br>
[2]Trivusi. (2022, September 16). Struktur data graph: Pengertian, jenis, dan kegunaannya. Trivusi.https://share.google/xNcFPXyImy8vf9ReB
