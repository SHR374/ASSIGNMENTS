#include <iostream>
using namespace std;


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int original[] = {64, 25, 12, 22, 11};
    int size = sizeof(original) / sizeof(original[0]);

    int arr1[size], arr2[size], arr3[size], arr4[size], arr5[size];
    copy(original, original + size, arr1);
    copy(original, original + size, arr2);
    copy(original, original + size, arr3);
    copy(original, original + size, arr4);
    copy(original, original + size, arr5);

    cout << "Original Array: ";
    printArray(original, size);

    selectionSort(arr1, size);
    cout << "Selection Sort: ";
    printArray(arr1, size);

    insertionSort(arr2, size);
    cout << "Insertion Sort: ";
    printArray(arr2, size);

    bubbleSort(arr3, size);
    cout << "Bubble Sort: ";
    printArray(arr3, size);

    mergeSort(arr4, 0, size - 1);
    cout << "Merge Sort: ";
    printArray(arr4, size);

    quickSort(arr5, 0, size - 1);
    cout << "Quick Sort: ";
    printArray(arr5, size);

    return 0;
}
