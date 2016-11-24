/* Implement stack using one queue */

#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> Q;
public:
    void push(int key);
    void pop();
    int top();
    bool empty();
    int size();
};

int main(void) {
    Stack s;
    s.push(5);
    s.push(7);
    s.push(2);
    s.push(8);
    s.pop();
    s.push(9);
    cout << "Top: " << s.top() << "\tSize: " << s.size() << "\tEmpty " << s.empty() << endl;

    return 0;
}

void Stack::push(int key) {
    int size = Q.size();
    Q.push(key);

    for(queue<int>::size_type ix = 0; ix != size; ix++) {
        Q.push(Q.front());
        Q.pop();
    }
}

void Stack::pop() {
    Q.pop();
}

int Stack::top() {
    return Q.front();
}

bool Stack::empty() {
    return Q.empty();
}

int Stack::size() {
    return Q.size();
}
