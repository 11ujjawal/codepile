/* Given an array of integers, print the next greater element for the
 * current element, if present, else -1
 *
 * Example -
 * Array -      [13, 7, 6, 12]
 * Output -     [-1, 12, 12, -1]
 *
 * Explanation
 * No element greater than 13 and 12 exists to their right, and hence -1
 * For numbers 7 and 6, 12 exists (which is greater than 7 and 6) to their right
 *
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void printNextGreater(vector<int> ivec);

int main(void) {
    vector<int> ivec{13, 7, 6, 12, 4, 3, 9};
    printNextGreater(ivec);

    return 0;
}

void printNextGreater(vector<int> ivec) {
    stack<int> Stack;

    Stack.push(ivec.front());

    for(vector<int>::const_iterator iter = next(ivec.begin()); iter != ivec.end(); ++iter) {
        if(!Stack.empty()) {
            int elem = Stack.top();
            Stack.pop();

            while(elem < *iter) {
                cout << elem << " -> " << *iter << endl;
                if(Stack.empty())
                    break;
                elem = Stack.top();
                Stack.pop();
            }

            if(elem > *iter)
                Stack.push(elem);
        }
        Stack.push(*iter);
    }

    while(!Stack.empty()) {
        cout << Stack.top() << " -> " << -1 << endl;
        Stack.pop();
    }
}
