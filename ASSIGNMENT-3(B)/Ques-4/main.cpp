#include <iostream>
#include <string>
#include <cctype>

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(char ch) {
        if (top < MAX - 1) arr[++top] = ch;
    }

    char pop() {
        return (top >= 0) ? arr[top--] : '\0';
    }

    char peek() const {
        return (top >= 0) ? arr[top] : '\0';
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

std::string infixToPostfix(const std::string& infix) {
    Stack s;
    std::string postfix;

    for (char ch : infix) {
        if (std::isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        } else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
                postfix += s.pop();
            s.push(ch);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int main() {
    std::string infix;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infix);

    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << "\n";

    return 0;
}
