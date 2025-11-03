#include <iostream>
#include <algorithm>
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


Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}


Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {

        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}


int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int minDepth(Node* root) {
    if (root == nullptr)
        return 0;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = nullptr;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int val : values)
        root = insert(root, val);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 10);
    cout << "After deleting 10: ";
    inorder(root);
    cout << "\n";

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
