#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent &LParent){
    return(LParent.first == nullptr && LParent.last == nullptr);
}

bool isEmptyChild(listChild &LChild){
    return(LChild.first == nullptr && LChild.last == nullptr);
}

void createListParent(listParent &LParent){
    LParent.first =  LParent.last = nullptr; 
}
void createListChild(listChild &LChild){
    LChild.first = LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idGolongan = idGol;
    nodeBaruParent->isidata.namaGolongan = namaGol;
    nodeBaruParent->next = nullptr;
    nodeBaruParent->prev = nullptr;
    createListChild(nodeBaruParent->L_Child);
    return nodeBaruParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idHewan = idHwn;
    nodeBaruChild->isidata.namaHewan = namaHwn;
    nodeBaruChild->isidata.habitat = habitat;
    nodeBaruChild->isidata.ekor = tail;
    nodeBaruChild->isidata.bobot = weight;
    nodeBaruChild->next = nullptr;
    nodeBaruChild->prev = nullptr;
    return nodeBaruChild;
}
void deallocNodeParent(NodeParent &NParent){
    if(NParent != nullptr){
        NParent -> next = NParent -> prev = nullptr;
        delete NParent;
        NParent = nullptr;
    }
}
void deallocNodeChild(NodeChild &NChild){
    if(NChild != nullptr){
        NChild -> next = NChild -> prev = nullptr;
        delete NChild;
        NChild = nullptr;
    }
}
void insertFirstParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent){
    if(isEmptyParent(LParent)){
        LParent.first = LParent.last = newNParent;
    }else{
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent){
    if(!isEmptyParent(LParent)){
        NodeParent nodeBantu = LParent.first;
        if(LParent.first == LParent.last){
            LParent.first = LParent.last = nullptr;
        }else{
            LParent.first = nodeBantu->next;
            LParent.first->prev = nullptr;
        }
        deleteListChild(nodeBantu->L_Child);
        deallocNodeParent(nodeBantu);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev){
    if(LParent.first == nullptr){
        cout <<"List parent kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeParent nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LParent.last = NPrev;
            }
            deleteListChild(nodeHapus -> L_Child);
            deallocNodeParent(nodeHapus);
        }
        
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        newNChild->next =LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild){
    if(isEmptyChild(LChild)){
        LChild.first = LChild.last = newNChild;
    }else{
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild){
    if(!isEmptyChild(LChild)){
        NodeChild nodeBantu = LChild.first;
        if(LChild.first == LChild.last){
            LChild.first = LChild.last = nullptr;
        }else{
            LChild.first = nodeBantu->next;
            LChild.first->prev = nullptr;
        }
        deallocNodeChild(nodeBantu);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev){
    if(LChild.first == nullptr){
        cout <<"List child kosong" << endl;
    }else{
        if(NPrev != nullptr && NPrev ->next != nullptr){
            NodeChild nodeHapus = NPrev -> next;  
            NPrev -> next = nodeHapus -> next;
            if(nodeHapus->next != nullptr){
                (nodeHapus-> next)->prev = NPrev;
            }else{
                LChild.last = NPrev;
            }
            nodeHapus->next = nullptr;
            deallocNodeChild(nodeHapus);
        } 
    }
}
void printMLLStructure(listParent &LParent) {
    NodeParent P = LParent.first;
    int noParent = 1;

    while (P != nullptr) {
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;

        if (C == nullptr) {
            cout << "(tidak ada child)" << endl;
        } else {
            int noChild = 1;
            while (C != nullptr) {
                cout << " - Child " << noChild << " :" << endl;
                cout << "    ID Hewan : " << C->isidata.idHewan << endl;
                cout << "    Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "    Habitat : " << C->isidata.habitat << endl;
                cout << "    Ekor : " << C->isidata.ekor << endl;
                cout << "    Bobot : " << C->isidata.bobot << endl;

                C = C->next;
                noChild++;
            }
        }

        cout << "-----------------------------" << endl;
        P = P->next;
        noParent++;
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)){
        deleteFirstChild(LChild);
    }
}
    
    


    