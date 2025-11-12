#include <iostream>
using namespace std;

const int MAX = 100;
int heap[MAX];
int size = 0;


void insert(int value) {
    heap[size] = value;
    int i = size;
    size++;

    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void removeMax() {
    if (size == 0) {
        cout << "Priority Queue is empty.\n";
        return;
    }

    heap[0] = heap[size - 1];
    size--;


    int i = 0;
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(heap[i], heap[largest]);
        i = largest;
    }
}


int getMax() {
    if (size == 0) return -1;
    return heap[0];
}


void printHeap() {
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}


int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(10);

    cout << "Priority Queue: ";
    printHeap();

    cout << "Top element: " << getMax() << endl;

    removeMax();
    cout << "After removing top: ";
    printHeap();

    return 0;
}
