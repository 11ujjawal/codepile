/* Revserse a stack using recursion
 *
 * Method - First, all the elements are removed from the stack. Then elements
 * are inserted, but each element is inserted at the bottom in the stack.
 */

#include <iostream>
#include <stack>

using namespace std;

void reverse(stack<int> Stack);
void insertTopElem(stack<int> Stack, int topElem);

int main(void) {
    stack<int> Stack;

    for(stack<int>::size_type ix = 0; ix != 10; ++ix)
        Stack.push(ix);

    reverse(Stack);

    while(!Stack.empty()) {
        cout << Stack.top() << ' ';
        Stack.pop();
    }

    return 0;
}

void reverse(stack<int> Stack) {
    if(Stack.empty())
        return;

    int topElem = Stack.top();
    Stack.pop();

    reverse(Stack);
    insertTopElem(Stack, topElem);
}

void insertTopElem(stack<int> Stack, int item) {
    if(Stack.empty())
        Stack.push(item);
    else {
        int topElem = Stack.top();
        Stack.pop();

        insertTopElem(Stack, item);
        Stack.push(topElem);
    }
}
