#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* rear; // Pointer yang menunjuk elemen terakhir

public:
    CircularLinkedList() {
        rear = nullptr;
    }

    // Menambahkan data di depan
    void addFront(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
        }
    }

    // Menambahkan data di belakang
    void addRear(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Menyisipkan data antara data 1 dan 6
    void insertBetween(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            cout << "Circular linked list kosong." << endl;
            return;
        }

        Node* current = rear->next;
        while (current->data != 1) {
            current = current->next;
            if (current == rear->next) {
                cout << "Elemen 1 tidak ditemukan." << endl;
                return;
            }
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Mencetak semua elemen dua kali secara berurutan
    void printTwice() {
        if (rear == nullptr) {
            cout << "Circular linked list kosong." << endl;
            return;
        }

        Node* current = rear->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);

        current = rear->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);

        cout << endl;
    }

    // Mencetak semua elemen maju dan mundur
    void printForwardAndBackward() {
        if (rear == nullptr) {
            cout << "Circular linked list kosong." << endl;
            return;
        }

        Node* current = rear->next;
        cout << "Maju: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);

        cout << endl;

        cout << "Mundur: ";
        current = rear;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear);

        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.addFront(3);
    cll.addFront(2);
    cll.addFront(1);

    cll.addRear(6);
    cll.addRear(7);
    cll.addRear(8);

    cll.insertBetween(4);

    cll.printTwice();
    cll.printForwardAndBackward();

    return 0;
}