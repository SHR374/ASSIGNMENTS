#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}


void displayWithHeadRepeat(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << temp->data << " ";

    temp = temp->next;
    while (temp != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << head->data << "\n";
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 20);
    insertEnd(head, 100);
    insertEnd(head, 40);
    insertEnd(head, 80);
    insertEnd(head, 60);


    cout << "Circular Linked List with head repeated:\n";
    displayWithHeadRepeat(head);

    return 0;
}
