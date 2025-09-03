#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(int val) {
        if (top < MAX - 1) arr[++top] = val;
    }

    int pop() {
        return (top >= 0) ? arr[top--] : 0;
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int evaluatePostfix(const std::string& expr) {
    Stack s;

    for (char ch : expr) {
        if (std::isdigit(ch)) {
            s.push(ch - '0');  // Convert char digit to int
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    std::string postfix;
    std::cout << "Enter postfix expression (single-digit operands): ";
    std::getline(std::cin, postfix);

    int result = evaluatePostfix(postfix);
    std::cout << "Evaluated result: " << result << "\n";

    return 0;
}
