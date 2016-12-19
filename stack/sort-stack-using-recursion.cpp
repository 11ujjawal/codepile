/* Sort a stack using recursion */

#include <iostream>
#include <stack>

using namespace std;

void sort(stack<int>& Stack);
void insert(stack<int>& Stack, int item);

int main(void) {
    stack<int> Stack;

    Stack.push(5);
    Stack.push(8);
    Stack.push(1);
    Stack.push(9);
    Stack.push(3);
    Stack.push(7);

    sort(Stack);

    while(!Stack.empty()) {
        cout << Stack.top() << ' ';
        Stack.pop();
    }

    cout << endl;

    return 0;
}

/* Sort stack using a recursive approach */
void sort(stack<int>& Stack) {
    if(Stack.empty())
        return;

    int topElem = Stack.top();
    Stack.pop();

    sort(Stack);
    insert(Stack, topElem);
}

/* Inserts the given item in the stack in ascending order */
void insert(stack<int>& Stack, int item) {
    if(Stack.empty() || item < Stack.top())
        Stack.push(item);
    else {
        int topElem = Stack.top();
        Stack.pop();

        insert(Stack, item);
        Stack.push(topElem);
    }
}
