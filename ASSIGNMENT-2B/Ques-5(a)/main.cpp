#include <iostream>
#define MAX 4

int main() {
    int a[MAX];

    std::cout << "\nEnter " << MAX << " elements (row major):\n";
    for (int i = 0; i < MAX; ++i)
        std::cin >> a[i];

    std::cout << "\nThe matrix is...\n";
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (i == j)
                std::cout << a[i] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << "\n";
    }

    return 0;
}
