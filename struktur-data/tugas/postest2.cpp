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
        cout << "Nama: " << ktp.nama << endl;
        cout << "Tanggal Lahir: " << ktp.tanggalLahir << endl;
        cout << "Jenis Kelamin: " << ktp.jenisKelamin << endl;
        cout << "Alamat: " << ktp.alamat << endl;
        cout << "Agama: " << ktp.agama << endl;
        cout << "Status: " << ktp.status << endl;
        cout << "Pekerjaan: " << ktp.pekerjaan << endl;
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
        cout << "Data KTP ke-" << i + 1 << ":" << endl;
        ktpManager.displayData(ktpArray[i]);
    }

    return 0;
}
