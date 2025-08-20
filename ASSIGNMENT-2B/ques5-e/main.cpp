#include <iostream>
using namespace std;

int getIndex(int i, int j, int n) {

    if (i >= j)
        return i * (i + 1) / 2 + j;
    else
        return j * (j + 1) / 2 + i;
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int* symMatrix = new int[size];

    cout << "Enter symmetric matrix elements:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) {
            int val;
            cin >> val;
            symMatrix[getIndex(i, j, n)] = val;
        }

    cout << "\nReconstructed Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << symMatrix[getIndex(i, j, n)] << " ";
        cout << endl;
    }

    delete[] symMatrix;
    return 0;
}
