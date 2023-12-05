#include <bits/stdc++.h>
using namespace std;

struct DataKTP {
    string nama;
    string nik;
    string tanggalLahir;
    string alamat;
    string jenisKelamin;
    string status;
    string agama;
    string golDarah;

    DataKTP* next;
    DataKTP* prev;
};

class AntrianKTP {
private:
    DataKTP* head;
    DataKTP* tail;

public:
    AntrianKTP() : head(nullptr), tail(nullptr) {}

    void tambahDataKTP(const DataKTP& data) {
        DataKTP* newData = new DataKTP(data);

        if (!head) {
            head = tail = newData;
        } else {
            tail->next = newData;
            newData->prev = tail;
            tail = newData;
        }
    }

    void tampilkanAntrian() {
        DataKTP* current = head;

        while (current) {
            tampilkanDataKTP(current);
            current = current->next;
        }
    }

private:
    void tampilkanDataKTP(const DataKTP* data) {
        cout << "Nama: " << data->nama << endl;
        cout << "NIK: " << data->nik << endl;
        cout << "Tanggal Lahir: " << data->tanggalLahir << endl;
        cout << "Alamat: " << data->alamat << endl;
        cout << "Jenis Kelamin: " << data->jenisKelamin << endl;
        cout << "Status: " << data->status << endl;
        cout << "Agama: " << data->agama << endl;
        cout << "Golongan Darah: " << data->golDarah << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    AntrianKTP antrian;

    // Meminta pengguna untuk memasukkan data KTP pertama
    DataKTP data1;
    cout << "Masukkan data KTP pertama:" << endl;
    cout << "Nama: ";
    getline(cin, data1.nama);
    cout << "NIK: ";
    getline(cin, data1.nik);
    cout << "Tanggal Lahir: ";
    getline(cin, data1.tanggalLahir);
    cout << "Alamat: ";
    getline(cin, data1.alamat);
    cout << "Jenis Kelamin: ";
    getline(cin, data1.jenisKelamin);
    cout << "Status: ";
    getline(cin, data1.status);
    cout << "Agama: ";
    getline(cin, data1.agama);
    cout << "Golongan Darah: ";
    getline(cin, data1.golDarah);

    antrian.tambahDataKTP(data1);

    // Meminta pengguna untuk memasukkan data KTP kedua
    DataKTP data2;
    cout << "Masukkan data KTP kedua:" << endl;
    cout << "Nama: ";
    getline(cin, data2.nama);
    cout << "NIK: ";
    getline(cin, data2.nik);
    cout << "Tanggal Lahir: ";
    getline(cin, data2.tanggalLahir);
    cout << "Alamat: ";
    getline(cin, data2.alamat);
    cout << "Jenis Kelamin: ";
    getline(cin, data2.jenisKelamin);
    cout << "Status: ";
    getline(cin, data2.status);
    cout << "Agama: ";
    getline(cin, data2.agama);
    cout << "Golongan Darah: ";
    getline(cin, data2.golDarah);

    antrian.tambahDataKTP(data2);

    // Menampilkan antrian
    antrian.tampilkanAntrian();

    return 0;
}
