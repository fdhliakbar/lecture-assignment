#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addToFront(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addToBack(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(int value, int afterValue) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            while (current) {
                if (current->data == afterValue) {
                    newNode->next = current->next;
                    newNode->prev = current;
                    if (current->next) {
                        current->next->prev = newNode;
                    } else {
                        tail = newNode;
                    }
                    current->next = newNode;
                    break;
                }
                current = current->next;
            }
        }
    }

    void printForward() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printBackward() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;

    // Tambahkan elemen di depan
    myList.addToFront(3);
    myList.addToFront(2);
    myList.addToFront(1);

    // Tambahkan elemen di belakang
    myList.addToBack(6);
    myList.addToBack(7);
    myList.addToBack(8);

    // Sisipkan data 4 antara 1 dan 6
    myList.insertAfter(4, 1);

    // Cetak elemen maju dan mundur
    std::cout << "Maju: ";
    myList.printForward();
    std::cout << "Mundur: ";
    myList.printBackward();

    return 0;
}
