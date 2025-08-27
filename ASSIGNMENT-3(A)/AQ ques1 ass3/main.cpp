#include <iostream>
#include <stack>
using namespace std;

int main() {
    int A[] = {4, 5, 2, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    stack<int> s;

    cout << "Nearest smaller to left:\n";

    for (int i = 0; i < n; i++) {

        while (!s.empty() && s.top() >= A[i]) {
            s.pop();
        }


        if (s.empty()) {
            cout << -1 << " ";
        } else {
            cout << s.top() << " ";
        }


        s.push(A[i]);
    }

    cout << endl;
    return 0;
}
