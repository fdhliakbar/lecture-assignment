#include <iostream>
#include <string>

using namespace std;

struct Mobil {
    string nama;
    double hargaPerhari;
    Mobil* next;
    Mobil* prev;

    Mobil(const string& n, double harga) : nama(n), hargaPerhari(harga), next(nullptr), prev(nullptr) {}
};

class DaftarMobil {
public:
    DaftarMobil() : head(nullptr), tail(nullptr) {
        // Initialize the linked list with sample data
        tambahkanMobil("Toyota Avanza", 100.0);
        tambahkanMobil("Honda Civic", 120.0);
        tambahkanMobil("Nissan X-Trail", 150.0);
        tambahkanMobil("Ford Mustang", 200.0);
        tambahkanMobil("Mitsubishi Pajero", 180.0);
    }

    void tambahkanMobil(const string& nama, double harga) {
        Mobil* mobilBaru = new Mobil(nama, harga);

        if (!head) {
            head = mobilBaru;
            tail = mobilBaru;
        } else {
            tail->next = mobilBaru;
            mobilBaru->prev = tail;
            tail = mobilBaru;
        }
    }

    void tampilkanDaftarMobil() {
        cout << "=========================================\n";
        cout << "\tDAFTAR MOBIL YANG TERSEDIA " << '\n';
        cout << "=========================================\n";

        int i = 1;
        Mobil* current = head;

        while (current) {
            cout << i << ". " << current->nama << " - Harga per hari: " << current->hargaPerhari << "k" << '\n';
            current = current->next;
            i++;
        }
    }

private:
    Mobil* head;
    Mobil* tail;
};

int main() {
    DaftarMobil daftarMobil;

    daftarMobil.tampilkanDaftarMobil();

    return 0;
}
