#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root;
    createTree(root);

    insertNode(root, {"Rizkina Azizah", 60, "Basic"});
    insertNode(root, {"Hakan Ismail", 50, "Bronze"});
    insertNode(root, {"Olivia Saevali", 65, "Silver"});
    insertNode(root, {"Felix Pedrosa", 47, "Gold"});
    insertNode(root, {"Gamel Al Ghifari", 56, "Platinum"});
    insertNode(root, {"Hanif Al Faiz", 70, "Basic"});
    insertNode(root, {"Mutiara Fauziah", 52, "Bronze"});
    insertNode(root, {"Davi Ilyas", 68, "Silver"});
    insertNode(root, {"Abdad Mubarok", 81, "Gold"});

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl << endl;

    address minNode = mostLeft(root);
    address maxNode = mostRight(root);

    cout << "Node MostLeft  : " << minNode->info.beratBadan << endl;
    cout << "Node MostRight : " << maxNode->info.beratBadan << endl;

    cout << endl;
    cout << "=== Search By Berat Badan (70 kg) ===" << endl;
    searchByBeratBadan(root, 70);

    return 0;
}
