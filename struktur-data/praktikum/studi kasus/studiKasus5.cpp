#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Mobil
{
    string nama;
    double hargaPerhari;
    double totalHarga;
    int jumlahHari;
};

struct ATMTransaction
{
    string bank;
    double amount;
    ATMTransaction* next;

    ATMTransaction(const string& b, double amt) : bank(b), amount(amt), next(nullptr) {}
};

struct Struk
{
    string mobilDipesan;
    double totalHarga;
    Struk* next;

    Struk(const string& mobil, double harga) : mobilDipesan(mobil), totalHarga(harga), next(nullptr) {}
};

class PenyewaanMobil
{
public:
    PenyewaanMobil()
    {
        daftarMobil = {
            {"Toyota Avanza", 100.0},
            {"Honda Civic", 120.0},
            {"Nissan X-Trail", 150.0},
            {"Ford Mustang", 200.0},
            {"Mitsubishi Pajero", 180.0}};
        atmTransactionsHead = nullptr;
        atmTransactionsTail = nullptr;
        strukHead = nullptr;
        strukTail = nullptr;
    }

    void tampilkanDaftarMobil()
    {
        cout << "=========================================\n";
        cout << "\tDAFTAR MOBIL YANG TERSEDIA " << '\n';
        cout << "=========================================\n";

        for (int i = 0; i < daftarMobil.size(); i++)
        {
            cout << i + 1 << ". " << daftarMobil[i].nama << " - Harga per hari: " << daftarMobil[i].hargaPerhari << "k" << '\n';
        }
    }

    void pesanMobil(int indeksMobil)
    {
        system("cls");

        if (indeksMobil >= 0 && indeksMobil < daftarMobil.size())
        {
            mobilDipesan.push_back(daftarMobil[indeksMobil]);
            cout << "Anda telah memesan mobil " << daftarMobil[indeksMobil].nama << "." << '\n';
        }
        else
        {
            cout << "Pilihan mobil tidak valid." << '\n';
        }
    }

    void tampDafMobilDiPesan()
    {
        cout << "Mobil yang dipesan : " << '\n';
        for (int i = 0; i < mobilDipesan.size(); i++)
        {
            cout << i + 1 << ". " << mobilDipesan[i].nama;
        }
    }

    double hitungBiayaTotal()
    {
        double totalBiaya = 0.0;
        for (const auto& mobil : mobilDipesan)
        {
            totalBiaya += mobil.hargaPerhari;
        }

        return totalBiaya;
    }

    void tunai(int totalAmount)
    {
        if (totalAmount >= hitungBiayaTotal())
        {
            cout << "Pembayaran tunai sebesar " << totalAmount << " berhasil." << '\n';
            int kembalian = totalAmount - hitungBiayaTotal();
            cout << "Kembalian : " << kembalian << '\n';
            tampilkanStruk(); // Tampilkan struk setelah pembayaran tunai
        }
        else
        {
            cout << "Total pembayaran tidak valid." << '\n';
        }
    }

    void bayarDenganATM(const string& bank, double amount)
    {
        ATMTransaction* newTransaction = new ATMTransaction(bank, amount);
        if (atmTransactionsHead == nullptr)
        {
            atmTransactionsHead = newTransaction;
            atmTransactionsTail = newTransaction;
        }
        else
        {
            atmTransactionsTail->next = newTransaction;
            atmTransactionsTail = newTransaction;
        }
        cout << "Transaksi ATM sebesar " << amount << " dengan bank " << bank << " berhasil." << '\n';
        tampilkanStruk(); // Tampilkan struk setelah pembayaran dengan ATM
    }

    void tampilkanDaftarTransaksiATM()
    {
        cout << "Daftar Transaksi ATM:" << '\n';
        ATMTransaction* currentTransaction = atmTransactionsHead;
        int index = 1;
        while (currentTransaction != nullptr)
        {
            cout << index << ". Bank: " << currentTransaction->bank << ", Jumlah: " << currentTransaction->amount << '\n';
            currentTransaction = currentTransaction->next;
            index++;
        }
    }

    void buatStruk(const string& mobil, double totalHarga)
    {
        Struk* newStruk = new Struk(mobil, totalHarga);
        if (strukHead == nullptr)
        {
            strukHead = newStruk;
            strukTail = newStruk;
            newStruk->next = newStruk;  // Membuat linked list menjadi circular
        }
        else
        {
            newStruk->next = strukHead;
            strukTail->next = newStruk;
            strukTail = newStruk;
        }
    }

    void tampilkanStruk()
    {
        buatStruk(mobilDipesan.back().nama, hitungBiayaTotal());

        cout << "~~~ Struk Pembayaran ~~~" << "\n";
        cout << "Mobil yang telah disewa: " << mobilDipesan.back().nama << "\n";
        cout << "Total harga: " << hitungBiayaTotal() << "\n";

        Struk* currentStruk = strukHead;
        if (currentStruk)
        {
            cout << "Transaksi Sebelumnya:" << "\n";
            do
            {
                cout << "Mobil: " << currentStruk->mobilDipesan << ", Total Harga: " << currentStruk->totalHarga << "\n";
                currentStruk = currentStruk->next;
            } while (currentStruk != strukHead);
        }
        
        simpanStrukKeFile("struk.txt"); // Simpan struk ke dalam berkas "struk.txt"
    }

    void simpanStrukKeFile(const string& filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << "~~~ Struk Pembayaran ~~~" << "\n";
            file << "Mobil yang telah disewa: " << mobilDipesan.back().nama << "\n";
            file << "Total harga: " << hitungBiayaTotal() << "\n";

            Struk* currentStruk = strukHead;
            if (currentStruk)
            {
                file << "Transaksi Sebelumnya:" << "\n";
                do
                {
                    file << "Mobil: " << currentStruk->mobilDipesan << ", Total Harga: " << currentStruk->totalHarga << "\n";
                    currentStruk = currentStruk->next;
                } while (currentStruk != strukHead);
            }
            file.close();
            cout << "Struk telah disimpan ke dalam file " << filename << "\n";
        }
        else
        {
            cout << "Gagal membuka berkas " << filename << " untuk penyimpanan struk." << "\n";
        }
    }

private:
    vector<Mobil> daftarMobil;
    vector<Mobil> mobilDipesan;
    ATMTransaction* atmTransactionsHead;
    ATMTransaction* atmTransactionsTail;
    Struk* strukHead;
    Struk* strukTail;
};

int main()
{
    PenyewaanMobil rentalCar;
    int pilihan;
    int totalAmount;

    rentalCar.tampilkanDaftarMobil();
    cout << '\n' << "Pilih mobil yang ingin disewa (masukkan nomor): ";
    cin >> pilihan;
    system("pause");

    rentalCar.pesanMobil(pilihan - 1);
    int total = rentalCar.hitungBiayaTotal();
    cout << "Pembayaran yang harus Anda lakukan: " << total << "\n\n";

    cout << "~~~ Metode pembayaran ~~~" << "\n";
    cout << "1. Pembayaran Tunai" << "\n";
    cout << "2. Pembayaran dengan ATM" << "\n\n";
    cout << "Pilihan metode pembayaran (1/2): ";

    short int choose;
    cin >> choose;

    string bank;

    cout << '\n';

    switch (choose)
    {
    case 1:
        cout << "Daftar mobil yang telah di pesan : " << '\n';
        rentalCar.tampDafMobilDiPesan();
        cout << "Total harga : " << total << '\n';
        cout << "Masukkan total pembayaran tunai: ";
        cin >> totalAmount;
        rentalCar.tunai(totalAmount);
        break;
    case 2:
        cout << "Daftar mobil yang telah di pesan : " << '\n';
        rentalCar.tampDafMobilDiPesan();
        cout << "Total harga : " << total << '\n';
        cout << "Pilih bank ATM (Contoh: BCA, Mandiri, BRI): ";
        cin >> bank;
        cout << "Masukkan total pembayaran dengan ATM: ";
        cin >> totalAmount;
        rentalCar.bayarDenganATM(bank, totalAmount);
        rentalCar.tampilkanDaftarTransaksiATM();
        break;
    default:
        cout << "Metode pembayaran tidak valid." << '\n';
    }

    return 0;
}
