#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    queue<int> first;
    for(int i=0; i<n/2; i++) {
        first.push(q.front());
        q.pop();
    }
    while(!first.empty()) {
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    int n, x;
    cin >> n;
    queue<int> q;
    for(int i=0; i<n; i++) {
        cin >> x;
        q.push(x);
    }
    interleave(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
