#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;


        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            count++;
        }
    }

    cout << "Total distinct elements: " << count << endl;
    return 0;
}
