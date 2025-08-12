#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[5][20] = {"banana", "apple", "cherry", "mango", "grape"};

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (strcmp(str[i], str[j]) > 0) {
                char temp[20];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "Sorted strings:\n";
    for (int i = 0; i < 5; ++i)
        cout << str[i] << endl;

    return 0;
}
