#include "bstree.h"

void createTree(address &root) {
    root = NULL;
}

bool isEmpty(address root) {
    return root == NULL;
}

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x.beratBadan < root->info.beratBadan) {
        insertNode(root->left, x);
    } else {
        insertNode(root->right, x);
    }
}

void inOrder(address root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info.beratBadan << " - ";
        inOrder(root->right);
    }
}

address mostLeft(address root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

address mostRight(address root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

void searchByBeratBadan(address root, float berat) {
    address current = root;
    address parent = NULL;

    while (current != NULL && current->info.beratBadan != berat) {
        parent = current;
        if (berat < current->info.beratBadan)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    
    cout << "Data ditemukan!" << endl;
    cout << "--- Data Node ---" << endl;
    cout << "Nama  : " << current->info.namaMember << endl;
    cout << "Berat : " << current->info.beratBadan << endl;
    cout << "Tier  : " << current->info.tierMember << endl;

    
    cout << "-----------------" << endl;
    cout << "--- Parent ---" << endl;
    if (parent != NULL) {
        cout << "Nama  : " << parent->info.namaMember << endl;
        cout << "Berat : " << parent->info.beratBadan << endl;
        cout << "Tier  : " << parent->info.tierMember << endl;
    } else {
        cout << "Tidak memiliki parent (root)" << endl;
    }

  
    cout << "-----------------" << endl;
    cout << "--- Sibling ---" << endl;
    if (parent != NULL) {
        if (parent->left == current && parent->right != NULL) {
            cout << "Nama  : " << parent->right->info.namaMember << endl;
            cout << "Berat : " << parent->right->info.beratBadan << endl;
            cout << "Tier  : " << parent->right->info.tierMember << endl;
        }
        else if (parent->right == current && parent->left != NULL) {
            cout << "Nama  : " << parent->left->info.namaMember << endl;
            cout << "Berat : " << parent->left->info.beratBadan << endl;
            cout << "Tier  : " << parent->left->info.tierMember << endl;
        }
        else {
            cout << "Tidak memiliki sibling" << endl;
        }
    } else {
        cout << "Tidak memiliki sibling" << endl;
    }

    
    cout << "-----------------" << endl;
    cout << "--- Child Kiri ---" << endl;
    if (current->left != NULL) {
        cout << "Nama  : " << current->left->info.namaMember << endl;
        cout << "Berat : " << current->left->info.beratBadan << endl;
        cout << "Tier  : " << current->left->info.tierMember << endl;
    } else {
        cout << "NULL" << endl;
    }

    
    cout << "-----------------" << endl;
    cout << "--- Child Kanan ---" << endl;
    if (current->right != NULL) {
        cout << "Nama  : " << current->right->info.namaMember << endl;
        cout << "Berat : " << current->right->info.beratBadan << endl;
        cout << "Tier  : " << current->right->info.tierMember << endl;
    } else {
        cout << "NULL" << endl;
    }
}

