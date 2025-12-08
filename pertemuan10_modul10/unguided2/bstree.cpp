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

int hitungJumlahNode(address root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + hitungJumlahNode(root -> left) + hitungJumlahNode(root -> right);
    }
}
int hitungTotalInfo(address root){
    if(root == NULL){
        return 0;
    }else{
        return root -> info + hitungTotalInfo(root -> left) + hitungTotalInfo(root -> right);
    }
}
int hitungKedalaman(address root, int start){
    if(root == NULL){
        return start;
    }else{
        int leftDepth = hitungKedalaman(root -> left, start );
        int rightDepth = hitungKedalaman(root -> right, start );
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}