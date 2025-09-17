#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}


void displayList() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int countAndDeleteKey(int key) {
    int count = 0;


    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }


    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

int main() {

    int values[] = {1, 2, 1, 2, 1, 3, 1};
    for (int val : values) insertAtEnd(val);

    cout << "Original List: ";
    displayList();

    int key = 1;
    int count = countAndDeleteKey(key);

    cout << "Count of " << key << ": " << count << "\n";
    cout << "Updated List: ";
    displayList();

    return 0;
}
