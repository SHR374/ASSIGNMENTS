#include <iostream>
#define MAX 4

int main() {
    int size = 3 * MAX - 2;  // Total non-zero elements in the band
    int a[size];
    int k = 0;

    std::cout << "\nEnter " << size << " elements (row major):\n";
    for (int i = 0; i < size; ++i)
        std::cin >> a[i];

    std::cout << "\nThe matrix is...\n";
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (j == i - 1 || j == i || j == i + 1) {
                std::cout << a[k++] << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
