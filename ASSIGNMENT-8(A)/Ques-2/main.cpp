#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}


Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}


Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}


Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != nullptr)
        return findMin(target->right);

    Node* successor = nullptr;
    while (root != nullptr) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}


Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != nullptr)
        return findMax(target->left);

    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}


Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}


int main() {
    Node* root = nullptr;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int val : values)
        root = insert(root, val);

    int key = 15;
    Node* foundRec = searchRecursive(root, key);
    Node* foundIter = searchIterative(root, key);
    cout << "Recursive Search: " << (foundRec ? "Found" : "Not Found") << endl;
    cout << "Iterative Search: " << (foundIter ? "Found" : "Not Found") << endl;

    cout << "Maximum Element: " << findMax(root)->data << endl;
    cout << "Minimum Element: " << findMin(root)->data << endl;

    Node* target = searchRecursive(root, 20);
    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);
    cout << "In-order Successor of 20: " << (succ ? succ->data : -1) << endl;
    cout << "In-order Predecessor of 20: " << (pred ? pred->data : -1) << endl;

    return 0;
}
