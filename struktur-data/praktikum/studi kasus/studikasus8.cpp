#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
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

struct PriorityQueueElement
{
    string mobil;
    double totalHarga;
    int priority;
    PriorityQueueElement* next;
    PriorityQueueElement* prev;

    PriorityQueueElement(const string& m, double harga, int pri) : mobil(m), totalHarga(harga), priority(pri), next(nullptr), prev(nullptr) {}
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
        priorityQueueHead = nullptr;
        priorityQueueTail = nullptr;
    }

    void tampilkanDaftarTransaksiStack()
    {
        stack<ATMTransaction> transaksiStack;

        ATMTransaction* currentTransaction = atmTransactionsHead;
        while (currentTransaction != nullptr)
        {
            transaksiStack.push(*currentTransaction);
            currentTransaction = currentTransaction->next;
        }

        if (!transaksiStack.empty())
        {
            cout << "Daftar Transaksi Stack: " << "\n";
            while (!transaksiStack.empty())
            {
                ATMTransaction transaksi = transaksiStack.top();
                cout << transaksi.bank << " - " << transaksi.amount << "\n\n";
                transaksiStack.pop();
            }
        }
        else
        {
            cout << "Tidak ada transaksi ATM." << "\n";
        }
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
            tampilkanStruk();
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
        tampilkanStruk();
    }

    void tambahAntrianBerprioritas(const string& mobil, double totalHarga, int priority)
    {
        PriorityQueueElement* newElement = new PriorityQueueElement(mobil, totalHarga, priority);

        if (priorityQueueHead == nullptr)
        {
            priorityQueueHead = newElement;
            priorityQueueTail = newElement;
        }
        else
        {
            PriorityQueueElement* currentElement = priorityQueueHead;

            while (currentElement != nullptr && priority > currentElement->priority)
            {
                currentElement = currentElement->next;
            }

            if (currentElement == nullptr)
            {
                newElement->prev = priorityQueueTail;
                priorityQueueTail->next = newElement;
                priorityQueueTail = newElement;
            }
            else
            {
                newElement->next = currentElement;
                newElement->prev = currentElement->prev;

                if (currentElement->prev != nullptr)
                {
                    currentElement->prev->next = newElement;
                }
                else
                {
                    priorityQueueHead = newElement;
                }

                currentElement->prev = newElement;
            }
        }
    }

    void tampilkanAntrianBerprioritas()
    {
        cout << "Antrian Berprioritas:" << '\n';
        PriorityQueueElement* currentElement = priorityQueueHead;
        int index = 1;

        while (currentElement != nullptr)
        {
            cout << index << ". Mobil: " << currentElement->mobil << ", Total Harga: " << currentElement->totalHarga << ", Prioritas: " << currentElement->priority << '\n';
            currentElement = currentElement->next;
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
            newStruk->next = newStruk;
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
        cout << "Mobil yang disewa: " << mobilDipesan.back().nama << "\n";
        cout << "Total harga: " << hitungBiayaTotal() << "\n\n";

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

        simpanStrukKeFile("struk.txt");
    }

    void simpanStrukKeFile(const string& filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << "~~~ Struk Pembayaran ~~~" << "\n";
            file << "Mobil yang disewa: " << mobilDipesan.back().nama << "\n";
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
    PriorityQueueElement* priorityQueueHead;
    PriorityQueueElement* priorityQueueTail;
};

int main()
{
    PenyewaanMobil rentalCar;
    int pilihan;
    int totalAmount;
    bool selesai = false;

    while (!selesai)
    {
        rentalCar.tampilkanDaftarMobil();

        cout << '\n' << "Pilih mobil yang ingin disewa (masukkan nomor): ";
        cin >> pilihan;

        rentalCar.pesanMobil(pilihan - 1);
        int total = rentalCar.hitungBiayaTotal();
        cout << "Pembayaran yang harus Anda lakukan: " << total << "\n\n";

        cout << "~~~ Metode pembayaran ~~~" << "\n";
        cout << "1. Pembayaran Tunai" << "\n";
        cout << "2. Pembayaran dengan ATM" << "\n";
        cout << "3. Tampilkan Daftar Transaksi Stack" << "\n";
        cout << "4. Tampilkan Antrian Berprioritas" << "\n";
        cout << "5. Keluar" << "\n\n";
        cout << "Pilihan metode pembayaran (1/2/3/4/5): ";

        int choose;
        cin >> choose;

        string bank;

        cout << '\n';

        switch (choose)
        {
        case 1:
            cout << "Daftar mobil yang telah di pesan : " << '\n';
            rentalCar.tampDafMobilDiPesan();
            cout << "Total harga : " << total << "\n\n";
            cout << "Masukkan total pembayaran tunai: ";
            cin >> totalAmount;
            rentalCar.tunai(totalAmount);
            break;
        case 2:
            cout << "Daftar mobil yang telah di pesan : " << '\n';
            rentalCar.tampDafMobilDiPesan();
            cout << "Total harga : " << total << "\n\n";
            cout << "Pilih bank ATM (Contoh: BCA, Mandiri, BRI): ";
            cin >> bank;
            cout << "Masukkan total pembayaran dengan ATM: ";
            cin >> totalAmount;
            rentalCar.bayarDenganATM(bank, totalAmount);

            cout << "Apakah Anda ingin melihat daftar transaksi ATM? (1. Ya / 2. Tidak): ";
            int viewTransaksi;
            cin >> viewTransaksi;

            if (viewTransaksi == 1) {
                rentalCar.tampilkanDaftarTransaksiATM();
            }
            break;
        case 3:
            cout << "Daftar Transaksi Stack: " << "\n";
            rentalCar.tampilkanDaftarTransaksiStack();
            break;
        case 4:
            cout << "Antrian Berprioritas: " << "\n";
            rentalCar.tampilkanAntrianBerprioritas();
            break;
        case 5:
            selesai = true;
            break;
        default:
            cout << "Pilihan tidak valid." << '\n';
        }
    }

    return 0;
}
