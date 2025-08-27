#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char ch) {
        if (top < MAX - 1) {
            arr[++top] = ch;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    string input;

    cout << "Enter a string: ";
    cin >> input;


    for (char ch : input) {
        s.push(ch);
    }

    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
