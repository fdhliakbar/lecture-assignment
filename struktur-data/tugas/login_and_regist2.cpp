#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace  std;

class userAuthentication {
  public:
  int count;
  string username, password, userId, passId;

  private:
  void registration(string userId, string passId) {
    
  }

  void login(string userId, string passId) {
    char choose;

    // Note : mau login pake cara apa:
    // Gmail, 
    
    if (username != userId && password != passId) {
      cout << "Username atau Password yang anda masukkan salah!";
      cout << "is your the forgot about password" << '\n';
      cin >> choose;
      if (choose == 'y' || choose == 'Y') {
        forgot();
      }
    }
  }

  void forgot() {
    
  }

};


int main() {
    system("cls");

    for (int i = 0; i < 25; i++) {
        cout << "=";
    }

    cout << "\t\tSelamat Datang Di Aplikasi UAD\t\t" << '\n';

    for (int i = 0; i < 25; i++) {
        cout << "=";
    }

    cout << "\t\t1. Registrasi\t\t" << '\n';
    cout << "\t\t2. Login\t\t" << '\n';

    char choose;

    if (choose == 1) {


    } else if (choose = 2) {
        
    }
  return 0;
}