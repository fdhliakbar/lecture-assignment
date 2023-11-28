#include <iostream>
#include <string>
using namespace std;

struct KTPData
{
    string nama;
    string tanggalLahir;
    string nik;
    string jenisKelamin;
    string agama;
    string status;
    string pekerjaan;
};

class node
{
public:
    KTPData data;
    node *next;
    node *prev;

    node(const KTPData &ktp) : data(ktp), next(nullptr), prev(nullptr) {}
};

class KTPManager
{
public:
    node *head;
    node *tail;

    KTPManager() : head(nullptr), tail(nullptr) {}

    void inputData(KTPData &ktp)
    {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, ktp.nama);

        cout << "Masukkan Tanggal Lahir: ";
        getline(cin, ktp.tanggalLahir);

        cout << "Masukkan NIK: ";
        getline(cin, ktp.nik);

        cout << "Masukkan Jenis Kelamin: ";
        getline(cin, ktp.jenisKelamin);

        cout << "Masukkan Agama: ";
        getline(cin, ktp.agama);

        cout << "Masukkan Status: ";
        getline(cin, ktp.status);

        cout << "Masukkan Pekerjaan: ";
        getline(cin, ktp.pekerjaan);
    }

    void displayData(const KTPData &ktp)
    {
        cout << "Nama: " << ktp.nama << endl;
        cout << "Tanggal Lahir: " << ktp.tanggalLahir << endl;
        cout << "NIK: " << ktp.nik << endl;
        cout << "Jenis Kelamin: " << ktp.jenisKelamin << endl;
        cout << "Agama: " << ktp.agama << endl;
        cout << "Status: " << ktp.status << endl;
        cout << "Pekerjaan: " << ktp.pekerjaan << endl;
    }

    void tambahDataBelakang(const KTPData &ktp)
    {
        node *newNode = new node(ktp);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void hapusDataBelakang()
    {
        if (head == nullptr)
        {
            cout << "Linked List kosong. Tidak ada yang bisa dihapus." << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            node *temp = tail;
            tail = tail->prev;
            delete temp;
            if (tail != nullptr)
                tail->next = nullptr;
        }
    }

    ~KTPManager()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    KTPManager ktpManager;

    int maxData = 0;

    cout << "Masukkan jumlah maksimal data KTP yang ingin Anda tampung: ";
    cin >> maxData;

    for (int i = 0; i < maxData; i++)
    {
        KTPData ktp;
        cout << "\n\n";
        cout << "Data KTP ke-" << i + 1 << ":" << endl;
        ktpManager.inputData(ktp);
        ktpManager.tambahDataBelakang(ktp);
    }

    cout << endl
         << endl;

    cout << "Data sebelum menghapus node terakhir:\n\n";

    node *current = ktpManager.head;
    int i = 0;
    while (current != nullptr)
    {
        cout << "\tData KTP ke- " << i + 1 << ":" << endl;
        ktpManager.displayData(current->data);
        current = current->next;
        i++;
    }

    ktpManager.hapusDataBelakang();

    cout << "\n\n";
    cout << "Data setelah menghapus node terakhir:\n\n";

    current = ktpManager.head;
    i = 0;
    while (current != nullptr)
    {
        cout << "\tData KTP ke- " << i + 1 << ":" << endl;
        ktpManager.displayData(current->data);
        current = current->next;
        i++;
    }

    return 0;
}
