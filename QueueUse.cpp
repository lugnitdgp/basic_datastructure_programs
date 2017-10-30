#include <iostream>
using namespace std;
#include "Queue.h"

int main() {
    Queue<int> q;
    cout << q.getSize() << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;

    while(!q.isEmpty()) {
        cout << q.dequeue() << endl;
    }
}

