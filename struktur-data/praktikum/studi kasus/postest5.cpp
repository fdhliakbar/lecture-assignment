#include <iostream>
#include <string>
using namespace std;

struct KTP
{
    string NIK, alamat, agama, status, pekerjaan, kewarganegaraan;
    string nama, tempat_lahir, jenis_kelamin, gol, Kel, kec;
    short int RT, RW;
    string tanggal_lahir;
};

class Node
{
public:1
    KTP data;
    Node* next;
    Node* prev;

    Node(const KTP& ktp) : data(ktp), next(nullptr), prev(nullptr) {}
};

class KTPManager
{
public:
    Node* head;
    Node* tail;

    KTPManager()
        : head(nullptr), tail(nullptr) {}

    void inputData(KTP& ktp)
    {
        cout << "Masukkan NIK: ";
        cin.ignore();
        getline(cin, ktp.NIK);

        cout << "Masukkan Nama: ";
        getline(cin, ktp.nama);

        cout << "Masukkan Tempat Lahir: ";
        getline(cin, ktp.tempat_lahir);

        cout << "Masukkan Tanggal Lahir: ";
        cin >> ktp.tanggal_lahir;

        cout << "Masukkan Jenis Kelamin: ";
        cin.ignore();
        getline(cin, ktp.jenis_kelamin);

        cout << "Masukkan Gol darah :";
        cin >> ktp.gol;

        cout << "Masukkan alamat : ";
        cin.ignore();
        getline(cin, ktp.alamat);

        cout << "Masukkan RT : ";
        cin >> ktp.RT;

        cout << "Masukkan RW : ";
        cin >> ktp.RW;

        cout << "Maukkan Kel/Desa : ";
        cin.ignore();
        getline(cin, ktp.Kel);

        cout << "Masukkan Kecamatan : ";
        getline(cin, ktp.kec);

        cout << "Masukkan Agama : ";
        cin.ignore();
        getline(cin, ktp.agama);

        cout << "Masukkan status pekerjaan : ";
        getline(cin, ktp.status);

        cout << "Masukkan Kewarganegaraan : ";
        getline(cin, ktp.kewarganegaraan);
    }

    void displayData(const KTP& ktp)
    {
        cout << "Nama                       : " << ktp.nama << endl;
        cout << "Tempat Lahir / Tgl lahir   : " << ktp.tempat_lahir << ", " << ktp.tanggal_lahir << endl;
        cout << "Alamat                     : " << ktp.alamat << endl;
        cout << "\tRT/RW              : " << ktp.RT << "/" << ktp.RW << endl;
        cout << "\tKel/Desa           : " << ktp.Kel << endl;
        cout << "\tKecamatan          : " << ktp.kec << endl;
        cout << "Agama                      : " << ktp.agama << endl;
        cout << "Status Perkawinan          : " << ktp.status << endl;
        cout << "Kewarganegaraan            : " << ktp.kewarganegaraan << endl;
        cout << "Beralaku Hingga           : SEUMUR HIDUP" << endl;
        cout << "============================================" << endl;
    }

    void addToBack(const KTP& ktp)
    {
        Node* newNode = new Node(ktp);
        if (!tail)
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
            Node* current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete current->next;
            tail = current;
            tail->next = nullptr;
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
        KTP ktp;
        cout << "\n\n";
        cout << "Data KTP ke-" << i + 1 << ":" << endl;
        ktpManager.inputData(ktp);
        ktpManager.addToBack(ktp);
    }

    cout << endl << endl;

    cout << "Data sebelum menghapus Node terakhir:\n\n";

    Node* current = ktpManager.head;
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
    cout << "Data setelah menghapus Node terakhir:\n\n";

    current = ktpManager.head;
    i = 0;
    while (current != nullptr)
    {
        cout << "\tData KTP ke- " << i + 1 << ":" << endl;
        ktpManager.displayData(current->data);
        current = current->next;
        i++;
    }

    while (ktpManager.head != nullptr)
    {
        Node* temp = ktpManager.head;
        ktpManager.head = ktpManager.head->next;
        delete temp;
    }

    return 0;
}