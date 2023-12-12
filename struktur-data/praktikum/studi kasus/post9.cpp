#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

void inorder(Node* root) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node* root) {
  if (root == nullptr) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void preorder(Node* root) {
  if (root == nullptr) {
    return;
  }

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

int main() {
  // MEmbaut pohon(tree)
  Node* root = createNode(1);
  root->left = createNode(8);
  root->right = createNode(4);
  root->left->left = createNode(5);
  root->right->right = createNode(97);

  // Cetak inorder
  cout << "Inorder: ";
  inorder(root);
  cout << endl;

  // Cetak postorder
  cout << "Postorder: ";
  postorder(root);
  cout << endl;

  // Cetak preorder
  cout << "Preorder: ";
  preorder(root);
  cout << endl;

  return 0;
}
