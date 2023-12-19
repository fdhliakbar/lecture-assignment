#include <bits/stdc++.h>
#include <fstream>
#include <queue>
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
    int nomorPesanan; // Tambahkan nomor pesanan
    string bank;
    double amount;
    int pesananCounter;
    ATMTransaction* next;

    ATMTransaction(int nomorPesanan, const string& b, double amt) : pesananCounter(nomorPesanan), bank(b), amount(amt), next(nullptr) {}
};

struct Struk
{
    string mobilDipesan;
    double totalHarga;
    Struk* next;

    Struk(const string& mobil, double harga) : mobilDipesan(mobil), totalHarga(harga), next(nullptr) {}
};

struct Pesanan {
    string namaMobil;
    Pesanan* prev;
    Pesanan* next;

    Pesanan(const string& mobil) : namaMobil(mobil), prev(nullptr), next(nullptr) {}
};

int hargaBelumSelesai;

struct Node {
    string mobil;
    Node* left;
    Node* right;

    Node(const string& m) : mobil(m), left(nullptr), right(nullptr) {}
};

class TreeManagement {
public:
    TreeManagement() : root(nullptr) {}

    void tambahMobilKeTree(const string& mobil) {
        root = tambahMobil(root, mobil);
    }

    void tampilkanDaftarMobilTree() {
        cout << "Daftar Mobil yang Telah Dipesan (dengan tree):" << '\n';
        tampilkanMobilTree(root);
    }

private:
    Node* root;

    Node* tambahMobil(Node* node, const string& mobil) {
        if (node == nullptr) {
            return new Node(mobil);
        }

        if (mobil < node->mobil) {
            node->left = tambahMobil(node->left, mobil);
        } else if (mobil > node->mobil) {
            node->right = tambahMobil(node->right, mobil);
        }

        return node;
    }

    void tampilkanMobilTree(Node* node) {
        if (node != nullptr) {
            tampilkanMobilTree(node->left);
            cout << node->mobil << '\n';
            tampilkanMobilTree(node->right);
        }
    }
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

    // PERTEMUAN 7 QUEUE WITH ARRAY CIRCULAR


    void kekuranganBayar(const string& mobil, double denda)
    {
        DendaTransaction* newTransaction = new DendaTransaction(mobil, denda);
        overdueTransactions.push(newTransaction);
    }

    // PERTEMUAN 8 DOUBLY LINK LIST
    Pesanan* pesananHead;
    Pesanan* pesananTail;

    void tambahPesanan(const string& mobil){
        Pesanan* newPesanan = new Pesanan(mobil);
        if (pesananHead == nullptr){
            pesananHead = newPesanan;
            pesananTail = newPesanan;
        }else{
            pesananTail->next = newPesanan;
            newPesanan->prev = pesananTail;
            pesananTail = newPesanan;
        }
    }

    void tampilkanDaftarMobilDipesan(){
        cout << "Daftar Mobil yang Telah Dipesan:" << '\n';
        Pesanan* currentPesanan = pesananHead;
        while (currentPesanan != nullptr)
        {
            cout << currentPesanan->namaMobil << '\n';
            currentPesanan = currentPesanan->next;
        }
    }




    // PERTEMUAN 9 POHON(TREE)


    // PERTEMUAN 10 SEKUEN


    void tampilkanDaftarTransaksiStack(){
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
            cout <<"Kode Pesanan||Jenis Transaksi||Total\n";
            while (!transaksiStack.empty())
            {
                ATMTransaction transaksi = transaksiStack.top();
                cout <<transaksi.nomorPesanan<<" 	- 	" <<transaksi.bank << " 	-	 " << transaksi.amount << "\n\n";
                transaksiStack.pop();
            }
        }
        else
        {
            cout << "Tidak ada transaksi ATM." << "\n";
            system("pause");
            system("cls");
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
        //system("cls");

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

    double hitungBiayaTotal(){
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

            system("pause");
            system("cls");
            tampilkanStruk(); // Tampilkan struk setelah pembayaran tunai
        }
        else {
            string jenisMobil;
            hargaBelumSelesai = hitungBiayaTotal() - totalAmount;
            cout << "Total pembayaran anda kurang: " << hargaBelumSelesai << "\n\n";

            // Cicil Mobil
            int cicilSewaMobil;
            cout << "Apakah anda ingin mencicil sewa mobil? (1. Ya / 2. Tidak): ";
            cin >> cicilSewaMobil;

            if (cicilSewaMobil == 1) {
                int periodeCicilan;
                cout << "Tambah Cicilan berhasil dimasukkan" << "\n";

                kekuranganBayar(jenisMobil, periodeCicilan);


            }
            system("pause");
            system("cls");
            //tampilkanStruk();
        }
    }

    void bayarDenganATM(int nomorPesanan,const string& bank, double amount)
    {
        
        // Tambahkan informasi transaksi ke dalam stack
    ATMTransaction* newTransaction = new ATMTransaction(nomorPesanan++, bank, amount); // pesananCounter merupakan variabel global yang mendeklarasikan nomor pesanan
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

        cout << "Transaksi ATM sebesar " << amount << " dengan bank " << bank <<" kode pembayaran "<< nomorPesanan<<" berhasil." << '\n';
        //system("pause");
        //system("cls");
        tampilkanStruk();
     }

    
 void tampilkanDaftarTransaksiATM()
{
    cout << "Daftar Transaksi ATM:" << '\n';
    ATMTransaction* currentTransaction = atmTransactionsHead;
    int index = 1;
    while (currentTransaction != nullptr)
    {
        cout <<"kode pesanan : "<< currentTransaction->nomorPesanan << ". Bank: " << currentTransaction->bank << ", Jumlah: " << currentTransaction->amount << '\n';
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
    
    simpanStrukKeFile("struk.txt"); // Simpan struk ke dalam berkas "struk.txt"
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
    struct DendaTransaction {
        string mobil;
        double denda;
        
        DendaTransaction* next;

        DendaTransaction(const string& m, double d) : mobil(m), denda(d), next(nullptr) {}
    };

    queue<DendaTransaction*> overdueTransactions;
    vector<Mobil> daftarMobil;
    vector<Mobil> mobilDipesan;
    ATMTransaction* atmTransactionsHead;
    ATMTransaction* atmTransactionsTail;
    Struk* strukHead;
    Struk* strukTail;
};
int pesananCounter = 1;
int main()
{
    PenyewaanMobil rentalCar;
    short int pilihan;
    int nomorPesan = 0;
    double totalAmount, batasWaktu;
    bool selesai = false;

    do {
        // MENU PROGRAM
        cout << "~~ Program Pembayaran ~~~" << '\n';
        cout << "1. Tampilkan Daftar Mobil" << '\n';
        cout << "2. Pesan Sewa Mobil" << '\n';
        cout << "3. Riwayat Transaksi" << '\n';
        cout << "4. Kekurangan pembayaran" << '\n';
        cout << "5. Keluar(Exit)" << '\n';
        cout << "Masukkan Pilihan Anda : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            rentalCar.tampilkanDaftarMobil();

            cout << endl;

        }
        else if (pilihan == 2) {
            rentalCar.tampilkanDaftarMobil();
            string bank;

            cout << "\nPilih mobil yang ingin di sewa(masukkan nomor): ";
            cin >> pilihan;

            rentalCar.pesanMobil(pilihan - 1);

            double total = rentalCar.hitungBiayaTotal();

            cout << "Pembayaran yang harus anda lakukan: " << total << "\n\n";

            cout << "~~~ Metode pembayaran ~~~" << "\n";
            cout << "1. Pembayaran Tunai" << "\n";
            cout << "2. Pembayaran dengan ATM" << "\n";
            cout << "Pilihan metode pembayaran(1/2): ";

            short int userInput;
            cin >> userInput;

            if (userInput == 1) {
                cout << "Daftar mobil yang telah di pesan : " << '\n';
                rentalCar.tampDafMobilDiPesan();
                cout << "Total harga : " << total << "\n\n";
                cout << "Masukkan total pembayaran tunai: ";
                cin >> totalAmount;

                rentalCar.tunai(totalAmount);

                system("pause");
                system("cls");
            }
            if (userInput == 2) {
                cout << "Daftar mobil yang telah di pesan : " << '\n';
                rentalCar.tampDafMobilDiPesan();

                cout << "Total harga : " << total << "\n\n";
                cout << "Pilih bank ATM (Contoh: BCA, Mandiri, BRI): ";
                cin >> bank;
                
                cout << "Masukkan total pembayaran dengan ATM: ";
                cin >> totalAmount;
                rentalCar.bayarDenganATM(nomorPesan,bank, totalAmount);

                cout << "Apakah Anda ingin melihat daftar transaksi ATM? (1. Ya / 2. Tidak): ";
                int viewTransaksi;
                cin >> viewTransaksi;

                if (viewTransaksi == 1) {
                    rentalCar.tampilkanDaftarTransaksiATM();
                }
                system("pause");
                system("cls");
            }

        }
        else if (pilihan == 3) {
            cout << "\nRiwayat Transaksi User" << '\n';
            rentalCar.tampilkanDaftarTransaksiStack();
            rentalCar.tampilkanDaftarMobilDipesan();
        }
        else if (pilihan == 4) {
            cout << "\n~~~ Riwayat Denda Mobil ~~~" << '\n';
            cout << "Denda : " << hargaBelumSelesai << '\n';

            system("pause");
            system("cls");
        }
        else if (pilihan == 5) {
            selesai = true; // iterasi berakhir
        } else {
            cout << "Inputan yang anda masukkan salah!!!." << '\n';
            system("pause");
            system("cls");
        }
    } while (!selesai);

    return 0;

}