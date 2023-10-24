#include <iostream>
using namespace std;

class IntegerReverser {
private:
    int* numbers;
    int size;

public:
    IntegerReverser(int arr[], int arrSize) : numbers(arr), size(arrSize) {
        if (size > 5) {
            cerr << "Array harus memiliki maksimal 5 elemen" << '\n';
            exit(1);
        }
    }

    void reverseIterative() {
        for (int i = size - 1; i >= 0; --i) {
            cout << numbers[i];
        }
        cout << '\n';
    }

    void reverseRecursive(int index = 0) {
        if (index == size) {
            cout << '\n';
            return;
        }

        cout << numbers[size - 1 - index];
        reverseRecursive(index + 1);
    }
};

int main() {
    int inputArray[5] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(inputArray) / sizeof(inputArray[0]);

    cout << "Input: ";
    for (int i = 0; i < arraySize; i++) {
        cout << inputArray[i] << " ";
    }

    cout << '\n';

    IntegerReverser reverser(inputArray, arraySize);

    cout << "Output Iteratif: ";
    reverser.reverseIterative();

    cout << "Output Rekursif: ";
    reverser.reverseRecursive();

    return 0;
}
