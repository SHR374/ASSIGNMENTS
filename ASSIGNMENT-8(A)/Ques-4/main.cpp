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


bool isBSTUtil(Node* root, Node*& prev) {
    if (root == nullptr)
        return true;


    if (!isBSTUtil(root->left, prev))
        return false;


    if (prev != nullptr && root->data <= prev->data)
        return false;

    prev = root;


    return isBSTUtil(root->right, prev);
}


bool isBST(Node* root) {
    Node* prev = nullptr;
    return isBSTUtil(root, prev);
}


int main() {

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    if (isBST(root))
        cout << "The tree is a Binary Search Tree." << endl;
    else
        cout << "The tree is NOT a Binary Search Tree." << endl;

    return 0;
}
