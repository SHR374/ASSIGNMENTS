#include <iostream>
using namespace std;


struct Node {
    char data;
    Node* prev;
    Node* next;
};


class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}


    void insertEnd(char ch) {
        Node* newNode = new Node{ch, nullptr, nullptr};
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    bool isPalindrome() {
        Node* left = head;
        Node* right = tail;

        while (left && right && left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }


    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    string input;

    cout << "Enter characters (no spaces): ";
    cin >> input;

    for (char ch : input)
        dll.insertEnd(ch);

    dll.display();

    if (dll.isPalindrome())
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is NOT a palindrome.\n";

    return 0;
}
