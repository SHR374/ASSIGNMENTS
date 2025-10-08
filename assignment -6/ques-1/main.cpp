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

// Doubly Linked List Operations
class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        DNode* newNode = new DNode{val, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertLast(int val) {
        DNode* newNode = new DNode{val, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        DNode* newNode = new DNode{val, temp, temp->next};
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        DNode* newNode = new DNode{val, temp->prev, temp};
        if (temp->prev) temp->prev->next = newNode;
        else head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int val) {
        DNode* temp = head;
        while (temp && temp->data != val) temp = temp->next;
        if (!temp) {
            cout << "Node " << val << " not found.\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << val << " deleted.\n";
    }

    void search(int val) {
        DNode* temp = head;
        while (temp) {
            if (temp->data == val) {
                cout << "Node " << val << " found.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << val << " not found.\n";
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

// Circular Linked List Operations
class CircularLinkedList {
    CNode* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertLast(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode{val, temp->next};
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int val) {
        if (!head) return;
        CNode *curr = head, *prev = nullptr;
        do {
            if (curr->data == val) {
                if (curr == head && curr->next == head) {
                    delete curr;
                    head = nullptr;
                    return;
                }
                if (curr == head) {
                    CNode* temp = head;
                    while (temp->next != head) temp = temp->next;
                    head = head->next;
                    temp->next = head;
                    delete curr;
                    return;
                }
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node " << val << " not found.\n";
    }

    void search(int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << val << " not found.\n";
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

// Main Menu
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, val, key;

    while (true) {
        cout << "\nChoose List Type:\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nChoice: ";
        cin >> listType;
        if (listType == 3) break;

        cout << "\nOperations:\n1. Insert First\n2. Insert Last\n3. Insert After\n4. Insert Before (DLL only)\n5. Delete Node\n6. Search Node\n7. Display\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? dll.insertFirst(val) : cll.insertFirst(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                (listType == 1) ? dll.insertLast(val) : cll.insertLast(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                (listType == 1) ? dll.insertAfter(key, val) : cll.insertAfter(key, val);
                break;
            case 4:
                if (listType == 1) {
                    cout << "Enter key and value: ";
                    cin >> key >> val;
                    dll.insertBefore(key, val);
                } else {
                    cout << "Insert Before not supported in Circular List.\n";
                }
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                (listType == 1) ? dll.deleteNode(val) : cll.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                (listType == 1) ? dll.search(val) : cll.search(val);
                break;
            case 7:
                (listType == 1) ? dll.display() : cll.display();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
