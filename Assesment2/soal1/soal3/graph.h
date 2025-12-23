#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

struct Node;
struct Edge;

struct Edge {
    Node* to;
    Edge* next;
};

struct Node {
    char nama;
    Edge* edge;
    Node* next;
    bool visited;
};


struct Graph {
    Node* head;
};

void createGraph(Graph &G);
Node* createNode(char x);
void addNode(Graph &G, char x);
Node* findNode(Graph G, char x);
void addEdge(Graph &G, char a, char b);

void Visited(Graph &G);
void DFS(Node* start, Node* ignored);
bool isConnected(Graph &G, Node* ignored);

void analyze(Graph &G);
void printGraph(Graph G);

#endif
