#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}


Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Вузол з одним або без дітей
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Вузол з двома дітьми
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void printTree(Node* root, int space = 0, int COUNT = 10) {
    if (root == nullptr) return;

    space += COUNT;

    printTree(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++) cout << " ";
    cout << root->data << endl;

    printTree(root->left, space);
}


int main() {
    Node* root = nullptr;

    // Додавання елементів
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printTree(root);


    cout << "Inorder: ";
    inOrder(root);
    cout << endl;

    // Пошук
    int key = 60;
    cout << "Search " << key << ": " << (search(root, key) ? "Found" : "Not Found") << endl;

    // Видалення
    root = deleteNode(root, 70);
    cout << "Inorder after deleting 70: ";
    inOrder(root);
    cout << endl;



    return 0;
}
