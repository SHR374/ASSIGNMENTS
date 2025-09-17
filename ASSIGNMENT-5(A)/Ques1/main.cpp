#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}


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


void insertRelativeToValue(int target, int value, bool insertBefore) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    if (insertBefore) {
        if (head->data == target) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != target) {
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            prev->next = newNode;
            newNode->next = curr;
        } else {
            cout << "Target not found.\n";
        }
    } else {
        Node* curr = head;
        while (curr && curr->data != target) {
            curr = curr->next;
        }
        if (curr) {
            newNode->next = curr->next;
            curr->next = newNode;
        } else {
            cout << "Target not found.\n";
        }
    }
}


void deleteFromBeginning() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}


void deleteFromEnd() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}


void deleteSpecific(int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        delete curr;
    } else {
        cout << "Node not found.\n";
    }
}


void searchNode(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Node found at position: " << pos << "\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found.\n";
}


void displayList() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Menu
void menu() {
    int choice, value, target;
    bool insertBefore;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After Specific Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                cout << "Insert before (1) or after (0)? ";
                cin >> insertBefore;
                insertRelativeToValue(target, value, insertBefore);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteSpecific(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 8:
                displayList();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 9);
}

int main() {
    menu();
    return 0;
}
