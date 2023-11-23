#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Stack {
private:
    int size;
    int stack[MAX_SIZE];
    int top;

public:
    Stack() {
        size = MAX_SIZE;
        top = -1;
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == size - 1;
    }

    void push(int item) {
        if (is_full()) {
            cout << "Stack penuh" << endl;
        } else {
            top++;
            stack[top] = item;
        }
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack kosong" << endl;
            return -1;
        } else {
            int item = stack[top];
            top--;
            return item;
        }
    }

    int peek() {
        if (is_empty()) {
            cout << "Stack kosong" << endl;
            return -1;
        } else {
            return stack[top];
        }
    }

    void display() {
        cout << "Isi stack:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
};

// Contoh penggunaan
int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    cout << "Elemen teratas: " << stack.peek() << endl;
    stack.pop();
    stack.display();

    return 0;
}