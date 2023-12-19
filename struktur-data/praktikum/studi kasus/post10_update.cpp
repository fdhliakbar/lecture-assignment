#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}


void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    int N;

    cout << "Masukkan jumlah data (N): ";
    cin >> N;

    cout << "Masukkan " << N << " data integer:\n";
    for (int i = 0; i < N; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    cout << "Data dalam urutan inorder: ";
    inorderTraversal(root);
    cout << endl;

    // Membersihkan memory tree
    deleteTree(root);

    return 0;
}
