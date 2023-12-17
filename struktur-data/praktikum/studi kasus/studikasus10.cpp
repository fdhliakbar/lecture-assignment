#include <bits/stdc++.h>

using namespace std;

int main(){
    short int choose;

    cout << "Masukkan pilihan: ";
    cin >> choose;

    if (choose > 0) {
        short int i = 1, N = 2;

        while (i <= N) {
            int panjang,lebar,result;

            cout << "Masukkan data ke-" << i << " : \n";
            cout << "Panjang: ";
            cin >> panjang;
            cout << "Lebar  : ";
            cin >> lebar;

            if (panjang > lebar) {
                result = panjang * lebar;
            } else if (panjang < lebar) {
                cout << "\nNilai panjang harus lebih besar dari lebar.\n";
                i--;
            } else {
                cout << "Data tidak valid.";
                break;
            }

            i++;
        }
    }
    return 0;
}