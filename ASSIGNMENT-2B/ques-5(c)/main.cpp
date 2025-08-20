#include <iostream>
#define MAX 4

int main() {
    int size = (MAX * (MAX + 1)) / 2;
    int a[size];
    int k = 0;

    std::cout << "\nEnter " << size << " elements (row major):\n";
    for (int i = 0; i < size; ++i)
        std::cin >> a[i];

    std::cout << "\nThe upper triangular matrix is...\n";
    k = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (i <= j)
                std::cout << a[k++] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << "\n";
    }

    std::cout << "\nThe lower triangular matrix is...\n";
    k = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (i >= j)
                std::cout << a[k++] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << "\n";
    }

    return 0;
}
