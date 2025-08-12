#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];

    cout << "Enter a word or sentence in uppercase: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }

    cout << "Lowercase version: " << str << endl;

    return 0;
}
