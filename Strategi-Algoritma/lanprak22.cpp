#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <math.h>
using namespace std;

int isPrime(int p);

int main () {
    for (int n = 0; n < 20; n++) {
        if (isPrime(n)) {
            cout << n << " ";
        }
        getch();
        cout << endl;
    }
}

int isPrime(int p) {
    float sqrtp = sqrt(p);
    if (p < 2) return 0; // false
    if (p == 2) return 1; // true, output berupa nilai 2
    if (p % 2 == 0) return 0; // false
    
    for (int d = 3; d <= sqrtp; d+= 2) {
        // false, dan mengulang kembali ke perulangan
        if (p % d == 0) return 0;
    }
    return 1; // jika benar, maka di cetak di output platform
}