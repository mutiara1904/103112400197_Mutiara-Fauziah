#include "bstree.h"
#include <iostream>
using namespace std;
address alokasi(infotype x){
    address P = new Node;
    P -> info = x;
    P -> left = NULL;
    P -> right = NULL;
    return P;
}
void insertNode(address &root, infotype x){
    if(root == NULL){
        root = alokasi(x);
    }else if(x < root -> info){
        insertNode(root -> left, x);
    }else{
        insertNode(root -> right, x);
    }
}
address findNode(address root, infotype x){
    if(root == NULL){
        return NULL;
    }
    if(root -> info == x){
        return root;
    }
    if(x < root -> info){
        return findNode(root -> left, x);
    }else{
        return findNode(root -> right, x);
    }
}
void printInOrder(address root){
    if (root == nullptr) return;

    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}