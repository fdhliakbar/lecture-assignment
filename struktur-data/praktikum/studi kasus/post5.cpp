#include <iostream>
#include <string>
using namespace std;

struct KTPData
{
    string nama;
    int tanggalLahir;
    string jenisKelamin;
    string alamat;
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
        // ... (unchanged)
    }

    void displayData(const KTPData &ktp)
    {
        // ... (unchanged)
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
