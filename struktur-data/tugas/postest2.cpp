#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan data KTP
struct KTP {
    string nama;
    string alamat;
    string nomorKTP;
    int umur;
};

// Class untuk mengelola input dan output KTP
class KTPManager {
public:
    // Konstruktor untuk menginisialisasi array KTP
    KTPManager(int jumlahKTP) {
        dataKTP = new KTP[jumlahKTP];
        jumlahDataKTP = jumlahKTP;
    }

    // Destruktor untuk membersihkan memori
    ~KTPManager() {
        delete[] dataKTP;
    }

    // Fungsi untuk memasukkan data KTP ke dalam array
    void inputKTP(int index) {
        if (index >= 0 && index < jumlahDataKTP) {
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, dataKTP[index].nama);
            cout << "Masukkan Alamat: ";
            getline(cin, dataKTP[index].alamat);
            cout << "Masukkan Nomor KTP: ";
            cin >> dataKTP[index].nomorKTP;
            cout << "Masukkan Umur: ";
            cin >> dataKTP[index].umur;
        } else {
            cout << "Indeks KTP tidak valid." << endl;
        }
    }

    // Fungsi untuk menampilkan data KTP dari array
    void tampilKTP(int index) {
        if (index >= 0 && index < jumlahDataKTP) {
            cout << "Nama: " << dataKTP[index].nama << endl;
            cout << "Alamat: " << dataKTP[index].alamat << endl;
            cout << "Nomor KTP: " << dataKTP[index].nomorKTP << endl;
            cout << "Umur: " << dataKTP[index].umur << endl;
        } else {
            cout << "Indeks KTP tidak valid." << endl;
        }
    }

private:
    KTP* dataKTP;
    int jumlahDataKTP;
};

int main() {
    const int jumlahKTP = 3; // Ubah sesuai dengan jumlah KTP yang ingin Anda kelola
    KTPManager manager(jumlahKTP);

    // Input data KTP
    for (int i = 0; i < jumlahKTP; ++i) {
        cout << "Masukkan Data KTP ke-" << (i + 1) << endl;
        manager.inputKTP(i);
    }

    // Tampilkan data KTP
    for (int i = 0; i < jumlahKTP; ++i) {
        cout << "Data KTP ke-" << (i + 1) << endl;
        manager.tampilKTP(i);
        cout << endl;
    }

    return 0;
}
