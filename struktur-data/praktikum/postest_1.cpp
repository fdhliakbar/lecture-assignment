#include <iostream>
using namespace std;

class Reverse {
public:
    int values[5];
    int size;

    void iterativeValue() {
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int temp = values[left];
            values[left] = values[right];
            values[right] = temp;
            left++;
            right--;
        }
    }

    void recursiveValues(int left, int right) {
        if (left < right) {
            int temp = values[left];
            values[left] = values[right];
            values[right] = temp;
            
            recursiveValues(left + 1, right - 1);
        }
    }
};

int main() {
    // int values[5] = {1, 2, 3, 4, 5};
    // int sizeValues = sizeof(values) / sizeof(values[0]);

    // Reverse reverseObject;
    // reverseObject.size = sizeValues;

    // // Menggunakan fungsi iteratif untuk membalikkan array
    // for (int i = 0; i < sizeValues; i++) {
    //     reverseObject.values[i] = values[i];
    // }
    // reverseObject.iterativeValue();

    // // Mencetak nilai yang sudah dibalikkan
    // for (int i = 0; i < sizeValues; i++) {
    //     cout << reverseObject.values[i] << " ";
    // }
    // cout << endl;

    // // Menggunakan fungsi rekursif untuk membalikkan array kembali ke aslinya
    // reverseObject.recursiveValues(0, sizeValues - 1);

    // // Mencetak nilai yang sudah dibalikkan kembali ke aslinya
    // for (int i = 0; i < sizeValues; i++) {
    //     cout << reverseObject.values[i] << " ";
    // }
    // cout << endl;

    struct KTP {
    string NIK, alamat, agama, status, pekerjaan, kewarganegaraan;
    string nama, tempat_lahir, jenis_kelamin, gol;
    short int RT, RW;
    int tanggal_lahir;
    }ktp_fadhli, ktp_bintang, ktp_kemas;

    short int count = 0;
    while(true) {
        cout << "Masukkan NIK anda: ";
        getline(cin, ktp_fadhli.NIK);

        cout << "Masukkan Nama andda: ";
        getline(cin, ktp_fadhli.nama);

        cout << "Masukkan Tempat Lahir: ";
        cin >> ktp_fadhli.tempat_lahir;
        cin.ignore();

        cout << "Masukkan Tanggal Lahir: ";
        cin >> ktp_fadhli.tanggal_lahir;
        cin.ignore();
        
        char choose;
        cout << "Mau lanjut(y/n): ";
        cin >> choose;

        if (choose != 'y') {
            cout << endl;
            break;
        }
        count++;
    }
    for (int i = 0; i < 4; i++) {
        cout << ktp_fadhli.NIK << '\n';
        cout << ktp_fadhli.nama << '\n';
        cout << ktp_fadhli.tempat_lahir << '\n';
        cout << ktp_fadhli.tanggal_lahir << '\n';
    }

    return 0;
}
