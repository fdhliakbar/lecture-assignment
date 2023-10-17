#include <iostream>
#include <string>
using namespace std;

struct KTPData {
    string nama;
    int tanggalLahir;
    string jenisKelamin;
    string alamat;
    string agama;
    string status;
    string pekerjaan;
};

class KTPManager {
public:
    void inputData(KTPData& ktp) {
        cout << "Nama: ";
        getline(cin, ktp.nama);
        
        cout << "Tanggal Lahir: ";
        cin >> ktp.tanggalLahir;
        cin.ignore();
        
        cout << "Jenis Kelamin: ";
        getline(cin, ktp.jenisKelamin);
        
        cout << "Alamat: ";
        getline(cin, ktp.alamat);
        
        cout << "Agama: ";
        getline(cin, ktp.agama);
        
        cout << "Status: ";
        getline(cin, ktp.status);
        
        cout << "Pekerjaan: ";
        getline(cin, ktp.pekerjaan);
    }

    void displayData(const KTPData& ktp) {
        cout << "Nama: " << ktp.nama << "\n";
        cout << "Tanggal Lahir: " << ktp.tanggalLahir << "\n";
        cout << "Jenis Kelamin: " << ktp.jenisKelamin << "\n";
        cout << "Alamat: " << ktp.alamat << "\n";
        cout << "Agama: " << ktp.agama << "\n";
        cout << "Status: " << ktp.status << "\n";
        cout << "Pekerjaan: " << ktp.pekerjaan << "\n";
        cout << "==========================\n\n";
    }
};

int main() {
    KTPManager ktpManager;
    KTPData ktpArray[3];


    for (int i = 0; i < 3; i++) {
        cout << "\n\n";
        cout << "Data KTP ke-" << i + 1 << ":" << endl;
        ktpManager.inputData(ktpArray[i]);
    }

    system("cls");

    for (int i = 0; i < 3; i++) {
        cout << "\tData KTP ke-" << i + 1 << ":" << endl;
        ktpManager.displayData(ktpArray[i]);
    }

    return 0;
}
