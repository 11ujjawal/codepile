/* Implement queue using two stacks */

#include <iostream>
#include <stack>

using namespace std;

class Queue {
    stack<int> sOne;
    stack<int> sTwo;
    void transferData();

public:
    void enqueue(int key);
    void dequeue();
    int front();
    int rear();
    int size();
    bool isempty();
};

void Queue::transferData(void) {
    while(!sOne.empty()) {
        sTwo.push(sOne.top());
        sOne.pop();
    }
}

void Queue::enqueue(int key) {
    sOne.push(key);
}

void Queue::dequeue() {
    if(isempty())
        return;

    if(sTwo.empty())
        transferData();
    sTwo.pop();
}

int Queue::front() {
    if(isempty())
        return INT_MIN;

    if(sTwo.empty())
        transferData();

    return sTwo.top();
}

int Queue::rear() {
    if(isempty())
        return INT_MIN;

    return sOne.top();
}

bool Queue::isempty() {
    return sOne.empty() && sTwo.empty();
}

int Queue::size() {
    return sOne.size() + sTwo.size();
}

int main(void) {
    Queue Q;

    Q.enqueue(5);
    Q.enqueue(7);
    Q.enqueue(9);
    Q.dequeue();
    Q.enqueue(1);
    Q.enqueue(0);

    cout << "Queue front: " << Q.front() << "\tQueue rear: " << Q.rear() << "\tSize: " << Q.size() << endl;

    return 0;
}
