#include <iostream>
using namespace std;

// Fungsi untuk menghapus elemen dengan nilai tertentu dari array
void deleteValue(int values[], int &size, int keyValue) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (values[i] != keyValue) {
            values[index] = values[i];
            index++;
        }
    }
    size = index;
}

// Fungsi untuk menyisipkan nilai-nilai baru ke dalam array
void insertValues(int values[], int &size, int newValues[], int newSize) {
    // Geser elemen-elemen ke kanan untuk memberi ruang pada nilai-nilai baru
    for (int i = size - 1; i >= 0; i--) {
        values[i + newSize] = values[i];
    }
    // Sisipkan nilai-nilai baru
    for (int i = 0; i < newSize; i++) {
        values[i] = newValues[i];
    }
    size += newSize;
}

int main() {
    int values[5] = {72, 110, 12, 66, 90};
    int sizeValues = sizeof(values) / sizeof(values[0]);

    // Hapus elemen dengan nilai 110 dari array
    deleteValue(values, sizeValues, 110);

    // Menyisipkan nilai-nilai baru ke dalam array
    int newValues[2] = {5, 8};
    insertValues(values, sizeValues, newValues, 2);

    // Cetak array setelah perubahan
    for (int i = 0; i < sizeValues; i++) {
        cout << values[i] << " ";
    }

    return 0;
}
