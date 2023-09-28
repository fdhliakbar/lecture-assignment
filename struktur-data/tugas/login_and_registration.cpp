#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class UserAuthentication {
    public:
        int count;
        string username, password;
        string userId, passwordId;
    private:
        void registration() {

        }

        void login() {
            cout << "\t\tMasukan usename dan password\t\t" << '\n';
            cout << "\t\tUsername : "; cin >> username;
            cout << "\t\tPassword : "; cin >> password;

            if (username == userId && password == passwordId) {
                cout << "Authentication successful" << endl;
            }

            // Masukkan username dan password ke dalam file "record.txt"
            ifstream input("record_login.txt");

        }
        // fitur lupa sandi
        void forgot() {

        }
};


int main(){
    system("cls");

    cout << "\t\tREGLAB INFOR<ATIKA \t\t" << endl;

    for (int i = 0; i < 40; i++) {
        cout << "=";
    }

    cout << "\n\n";

    cout << "\t\t1. Registration\t\t" << '\n';
    cout << "\t\t2. Login\t\t" << "\n\n";

    for (int i = 0; i < 40; i++) {
        cout << "=";
    }
    cout << "\n\n";

    int choose;

    cout << "Masukkan pilihan anda: ";
    cin >> choose;

    if (choose == 1) 

    return 0;
}