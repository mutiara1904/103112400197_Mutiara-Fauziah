#include "graph.h"

void createGraph(Graph &G) {
    G.head = NULL;
}

Node* createNode(char x) {
    Node* p = new Node;
    p->nama = x;
    p->edge = NULL;
    p->next = NULL;
    p->visited = false;
    return p;
}


void addNode(Graph &G, char x) {
    if (G.head == NULL)
        G.head = createNode(x);
    else {
        Node* temp = G.head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = createNode(x);
    }
}

Node* findNode(Graph G, char x) {
    Node* temp = G.head;
    while (temp != NULL) {
        if (temp->nama == x)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void addEdge(Graph &G, char a, char b) {
    Node* A = findNode(G, a);
    Node* B = findNode(G, b);

    if (A == NULL || B == NULL) return;

    Edge* e1 = new Edge{B, A->edge};
    A->edge = e1;

    Edge* e2 = new Edge{A, B->edge};
    B->edge = e2;
}

void Visited(Graph &G) {
    Node* p = G.head;
    while (p != NULL) {
        p->visited = false;
        p = p->next;
    }
}

void DFS(Node* start, Node* ignored) {
    if (start == NULL || start == ignored) return;

    start->visited = true;
    Edge* e = start->edge;

    while (e != NULL) {
        if (!e->to->visited && e->to != ignored)
            DFS(e->to, ignored);
        e = e->next;
    }
}

bool isConnected(Graph &G, Node* ignored) {
    Visited(G);

    Node* start = G.head;
    while (start != NULL && start == ignored)
        start = start->next;

    if (start == NULL) return true;

    DFS(start, ignored);

    Node* p = G.head;
    while (p != NULL) {
        if (!p->visited && p != ignored)
            return false;
        p = p->next;
    }
    return true;
}


void analyze(Graph &G) {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";

    Node* p = G.head;
    while (p != NULL) {
        if (!isConnected(G, p)) {
            cout << "[PERINGATAN] Kota " << p->nama
                 << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << p->nama
                 << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << p->nama
                 << " aman (redundansi oke).\n";
        }
        p = p->next;
    }
}

void printGraph(Graph G) {
    Node* p = G.head;
    while (p != NULL) {
        cout << "Node " << p->nama << " terhubung ke: ";
        Edge* e = p->edge;
        while (e != NULL) {
            cout << e->to->nama << " ";
            e = e->next;
        }
        cout << endl;
        p = p->next;
    }
}
