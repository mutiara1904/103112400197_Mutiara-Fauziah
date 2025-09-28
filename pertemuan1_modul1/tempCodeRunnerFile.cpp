#include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Masukan angka : ";
    cin >> x;

    for(int i = x; i >= 1; i--){
        for(int k = 0; k < x - i;k++){
            cout << " ";
        }
        for(int j = i; j >= 1; j--){
           cout << j; 
        }
        cout << "*";
        

        for(int j = 1; j <= i; j++){
            cout << j;
        }
        cout << endl;
        
    }
    for (int sp = 0 ; sp < x; sp++){
        cout << " ";
    }
    cout << "*" << endl;
    return 0;

}