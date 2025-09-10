#include <iostream>
using namespace std;

#define SIZE 50

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int val) {
        if(rear == SIZE-1) {
            cout << "Queue Full\n";
        } else {
            if(front == -1) front = 0;
            rear++;
            arr[rear] = val;
            cout << val << " inserted\n";
        }
    }
    void dequeue() {
        if(front == -1 || front > rear) {
            cout << "Queue Empty\n";
        } else {
            cout << "Deleted: " << arr[front] << endl;
            front++;
        }
    }
    void peek() {
        if(front == -1 || front > rear) cout << "Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }
    void display() {
        if(front == -1 || front > rear) cout << "Empty\n";
        else {
            cout << "Queue: ";
            for(int i=front; i<=rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
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
