#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <string>
using namespace std;

struct Member {
    string namaMember;
    float beratBadan;
    string tierMember;
};
typedef Member infotype;
struct Node {
    infotype info;
    Node* left;
    Node* right;
};
typedef Node* address;
void createTree(address &root);
bool isEmpty(address root);
address alokasi(infotype x);
void insertNode(address &root, infotype x);
void searchByBeratBadan(address root, float berat);
void inOrder(address root);
address mostLeft(address root);
address mostRight(address root);

#endif
