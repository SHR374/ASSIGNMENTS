#include <iostream>
using namespace std;

#define SIZE 5

class CQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    void enqueue(int val) {
        if(count == SIZE) {
            cout << "Circular Queue Full\n";
        } else {
            rear = (rear + 1) % SIZE;
            arr[rear] = val;
            count++;
            cout << val << " inserted\n";
        }
    }
    void dequeue() {
        if(count == 0) {
            cout << "Circular Queue Empty\n";
        } else {
            cout << "Deleted: " << arr[front] << endl;
            front = (front + 1) % SIZE;
            count--;
        }
    }
    void peek() {
        if(count == 0) cout << "Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }
    void display() {
        if(count == 0) cout << "Empty\n";
        else {
            cout << "Circular Queue: ";
            for(int i=0; i<count; i++) {
                cout << arr[(front+i)%SIZE] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    CQueue q;
    int ch, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> ch;
        switch(ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    } while(ch != 5);
}
