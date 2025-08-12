#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int size = 0;

void createArray() {
    cout << "Enter number of elements: ";
    cin >> size;
    if (size > MAX_SIZE) {
        cout << "Size exceeds maximum limit.\n";
        size = 0;
        return;
    }
    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}

void displayArray() {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert (0-based index): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;
    if (pos < 0 || pos > size) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;
    cout << "Element inserted.\n";
}

void deleteElement() {
    if (size == 0) {
        cout << "Array is empty. Cannot delete.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;
    if (pos < 0 || pos >= size) {
        cout << "Invalid position.\n";
        return;
    }
    int removed = arr[pos];
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element " << removed << " deleted.\n";
}

void linearSearch() {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n  MENU  \n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
