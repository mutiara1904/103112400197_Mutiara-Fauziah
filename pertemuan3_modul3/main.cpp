#include "pelajaran.h"
#include "pelajaran.cpp"

using namespace std;
int main(){
    string namapel = "Struktur data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;

}