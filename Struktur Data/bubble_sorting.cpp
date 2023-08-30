#include <iostream>
using namespace std;

void bubbleSorting(int arr[], int size) {
    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < size; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[5] = {5, 3, 1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSorting(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}