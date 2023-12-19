#include <iostream>
using namespace std;

class ArrayRotation {
private:
    int *arr;
    int size;

public:
    // Constructor untuk inisialisasi array
    ArrayRotation(int inputArray[], int arraySize) {
        arr = new int[arraySize];
        size = arraySize;
        for (int i = 0; i < arraySize; ++i) {
            arr[i] = inputArray[i];
        }
    }

    ~ArrayRotation() {
        delete[] arr;
    }

    void leftRotate(int d) {
        d = d % size;
        reverseArray(0, d - 1);
        reverseArray(d, size - 1);
        reverseArray(0, size - 1);
    }

    void rightRotate(int d) {
        d = d % size;
        reverseArray(0, size - d - 1);
        reverseArray(size - d, size - 1);
        reverseArray(0, size - 1);
    }

    void leftRightRotate(int left, int right) {
        leftRotate(left);
        rightRotate(right);
    }


    void rightLeftRotate(int right, int left) {
        rightRotate(right);
        leftRotate(left);
    }

    void reverseArray(int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            ++start;
            --end;
        }
    }

    void displayArray() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);

    ArrayRotation rotation(array, size);

    int leftRotation = 3;
    int rightRotation = 2;
    int leftRight = 2;
    int rightLeft = 3;

    cout << "Array awal: ";
    rotation.displayArray();

    // Rotasi kiri
    rotation.leftRotate(leftRotation);
    cout << "Setelah rotasi kiri " << leftRotation << " kali: ";
    rotation.displayArray();

    // Rotasi kanan
    rotation.rightRotate(rightRotation);
    cout << "Setelah rotasi kanan " << rightRotation << " kali: ";
    rotation.displayArray();

    // Left-right rotation
    rotation.leftRightRotate(leftRight, rightLeft);
    cout << "Setelah left-right rotation: ";
    rotation.displayArray();

    // Right-left rotation
    rotation.rightLeftRotate(rightLeft, leftRight);
    cout << "Setelah right-left rotation: ";
    rotation.displayArray();

    return 0;
}