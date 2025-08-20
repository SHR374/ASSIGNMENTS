#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int A[] = {2, 4, 1, 3, 5};
    int n = sizeof(A) / sizeof(A[0]);

    int result = countInversions(A, n);
    cout << "Number of inversions: " << result << endl;

    return 0;
}
