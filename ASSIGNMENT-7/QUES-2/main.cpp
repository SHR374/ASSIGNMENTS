#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIdx = start;
        int maxIdx = start;


        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIdx])
                minIdx = i;
            if (arr[i] > arr[maxIdx])
                maxIdx = i;
        }


        swap(arr[start], arr[minIdx]);


        if (maxIdx == start)
            maxIdx = minIdx;


        swap(arr[end], arr[maxIdx]);

        start++;
        end--;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


int main() {
    int arr[] = {29, 10, 14, 37, 13, 5, 42, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
