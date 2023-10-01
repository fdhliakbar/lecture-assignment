#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "validation.h"

using namespace std;

/*******************************
    ~~~ KELOMPOK 2 ~~~

    Kemas Khairunsyah (150)
    Bintang Toar Dondok ()
    Muhamad Fadhli Akbar_197

*******************************/

class userAuthentication {
    public:
        string username, password, userId, passId,userTampil;
        string email;

    private:
        bool loggedIn;

        void registration() {
            short int count = 1;
            
            system("cls");

            while(true){
            cout << "Masukkan email anda: ";
            cin >> email;

            if(isValidEmail(email)){
                break;
            } else {
                cout << "Email anda tidak valid, silahkan coba lagi!!!\n\n";
            }

            if (count == 3) {
                cout << "Anda salah memasukkan email sebanyak " << count << " kali dan program telah berakhir.\n";
                system("pause");
                handleUser();
            }
            count++;
            }

            system("cls");
            cout << "Masukkan username anda: ";
            cin.ignore();
            getline(cin, username);

            do {
                cout << "Masukkan password anda: ";
                cin >> password;

                /* Memeriksa password yang dimasukkan dengan
                    fungsi isValidPassword dalam header check_pass.h
                */
                if (isPasswordValid(password)) {
                    break;
                } else {
                    cout << "Password harus berisi minimal 8 kata dengan huruf besar, huruf kecil dan angka.\n\n";
                }

                if (count == 3) {
                    cout << "Anda salah memasukkan password sebanyak " << count << " kali dan program telah berhenti.\n";
                    system("pause");
                    handleUser();
                }

                count++;
            } while(true);

            string confirmPassword;

            cout << '\n';

            while(true){
                cout << "Masukkan ulang password anda: ";
                cin >> confirmPassword;

                if (confirmPassword == password) {
                    cout << "\n~~~ Registrasi berhasil ~~~\n";
                    passId = password;
                    userId = username;
                    break;
                } else {
                    cout << "Password tidak cocok!!!\n";
                    if(count == 3){
                        cout << "Anda telah memasukkan password yang salah sebanyak "<< count << " kali.\n";
                        cout << "Silahkan coba lagi\n";
                        break;
                    }
                char choise;
                cout << "Lanjut?";
                cin >> choise;
                }
                
                count++;
            }
            
        }

        void login() {
            cout << "\nMasukkan username: ";
            cin.ignore();
            getline(cin, username);

            cout << "Masukkan password: ";
            cin >> password;
            
            if (username == userId && password == passId) {

                loggedIn = true;

                cout << "Login berhasil\n\n";
                userTampil = userId;
            } else {
                cout << "Login gagal! Periksa kembali username dan password Anda.\n";

                char answer;

                cout << "\nApakah anda lupa password?(Y/N)\n";
                cin >> answer;

                if (answer == 'y' || answer == 'Y'){
                    forgot();
                }
            }
        }

        void forgot() {
            string checkEmail;

            system("cls");

            cout << "Masukkan email anda : ";
            cin >> checkEmail;

            if (isValidEmail(checkEmail)) {
            cout << "Email Valid\n";
            system("cls");
            changePassword();
            } else {
            cout << "Email tidak valid" << '\n';
            }
        }

        void changePassword(){
        string newPass;
        string confirmPass;
        short int count;

        system("cls");

        cout << "Masukkan password lama anda : ";
        cin >> password;

        if(password == passId){
            do {
                cout << "Masukkan password baru: ";
                cin >> newPass;

                /* Memeriksa password yang dimasukkan dengan
                    fungsi isValidPassword dalam header check_pass.h
                */
                if (isPasswordValid(newPass)) {
                    break;
                } else {
                    cout << "\nPassword harus berisi minimal 8 kata dengan huruf besar, huruf kecil dan angka.\n\n";
                }

                if (count == 3) {
                    cout << "Anda salah memasukkan password sebanyak " << count << " kali dan program telah berhenti.\n";
                    system("pause");
                    handleUser();
                }

                count++;
            } while(true);



	        while(true){
	            cout <<"Masukkan ulang password baru anda : ";
	            cin >> confirmPass;

	            if(newPass == confirmPass){
	                cout << "Ubah password berhasil!\n";

	                passId = newPass;

                    system("pause");
					login();
	            }else{
	                cout << "Password tidak sesuai!\n";
	            }

                if (count == 3) {
                    cout << "Anda salah memasukkan password sebanyak " << count << " kali dan program telah berhenti.\n";
                    system("pause");
                    handleUser();
                }
                count++;
			}
        }
    }

    public:
    userAuthentication() {
            loggedIn = false; // Saat program dimulai, pengguna belum login.
        }
        void handleUser() {
            int choice;

            system("cls");

            if (loggedIn) {
                cout << "Username saat ini: " << userTampil << "\n";
            } else {
                cout << "Username saat ini: (belum login)\n";
            }
            cout << endl;
            for (int i = 1; i <= 20; i++) {
                cout << "=";
            }
            cout << '\n';

            cout << "1. Registrasi\n";
            cout << "2. Login\n";
            cout << "3. Ganti password\n";
            cout << "4. Keluar\n";
            
            for (int i = 1; i <= 20; i++) {
                cout << "=";
            }
            cout << "\n\n";
            

            cout << "Masukkan pilihan anda: ";
            cin >> choice;


            switch (choice) {
                case 1:
                    registration();
                    break;
                case 2:
                    login();
                    break;
                case 3:
                    changePassword();
                    break;
                case 4:
                    cout << "\nAnda telah keluar dari program." << endl;
                    exit(0);
                default:
                    cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3." << endl;
            }
        }
    };




int main() {
    userAuthentication User;


    while (true) {
        User.handleUser();
    }

    return 0;
}