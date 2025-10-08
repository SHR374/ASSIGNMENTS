#include <iostream>
using namespace std;

// Doubly Linked List Node
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Circular Linked List Node
struct CNode {
    int data;
    CNode* next;
};

// Doubly Linked List Class
class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertEnd(int val) {
        DNode* newNode = new DNode{val, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        DNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        DNode* temp = head;
        cout << "DLL: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Circular Linked List Class
class CircularLinkedList {
    CNode* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int getSize() {
        if (!head) return 0;
        int count = 1;
        CNode* temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (!head) {
            cout << "CLL is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "CLL: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;


    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);

    cll.insertEnd(100);
    cll.insertEnd(200);
    cll.insertEnd(300);
    cll.insertEnd(400);


    dll.display();
    cll.display();


    cout << "Size of Doubly Linked List: " << dll.getSize() << "\n";
    cout << "Size of Circular Linked List: " << cll.getSize() << "\n";

    return 0;
}
