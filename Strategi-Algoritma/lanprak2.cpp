#include <iostream>
using namespace std;

int main() {
    int  a = 0;
    int i;
    int sum = 0, max = 0, min = 0;

    cout << "Banyaknya elemen yang akan di input :  ";
    cin >> a;

    int data[a];

    for (int i = 0; i < a; i++) {
        cout << "Input elemen ke-" << i+1 << " : ";
        cin >> data[i];
    }

    cout << "\nPake Array : ";
    cout << "\nData yang anda masukkan adalah : ";
    max = min = data[0];
    for (i = 0; i < a; i++) {
        cout << data[i] << ", ";
        sum+= data[i];
        if (max < data[i]) {
            max = data[i];
        }
        if (min > data[i]) {
            cout << "\nPake Array : ";
            cout << "\nData yang anda masukkan adalah : ";
            max = min = data[0];
            for (i = 0; i < a; i++) {
                cout << data[i] << ", ";
                sum+= data[i];

                if (max < data[i]) {
                    max = data[i];
                }

                if (min > data[i]) {
                    min = data[i];
                }
            }
        }
    }
    cout << "\n============================" << endl;
    cout << "Jumlah Data : " << sum << endl;
    cout << "Rata-Rata : " << sum << endl;
    cout << "Terkecil : " << sum << endl;
    cout << "Terbesar : " << sum << endl;
    cout << "============================" << endl;
}