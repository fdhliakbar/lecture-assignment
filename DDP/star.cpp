#include <iostream>
using namespace std;

int main() {
    int i = 0;
    
    for (i; i < 5; i++) {
        cout << i << '\n';
        for (int j = 0; j < i; j++) {
            cout << j << '\n';
        }
    }
}