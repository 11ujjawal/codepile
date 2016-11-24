/* Minimum number of bracket reversals needed to make an expression balanced */

#include <iostream>
#include <stack>
#include <string>
#include <climits>

using namespace std;

int getReversalCount(string exp);

int main(void) {
    string exp1("}}{}}{");
    string exp2("}}{{{}{{");

    cout << "Bracket reversal for expression '" << exp1 << "': " << getReversalCount(exp1) << endl;
    cout << "Bracket reversal for expression '" << exp2 << "': " << getReversalCount(exp2) << endl;

    return 0;
}

int getReversalCount(string exp) {
    int length = exp.size();
    if(length % 2 != 0)
        return INT_MIN;

    int count = 0;
    stack<char> Stack;

    for(string::size_type ix = 0; ix != length; ix++) {
        if(exp[ix] == '}') {
            if(!Stack.empty()) {
                char top = Stack.top();

                if(top == '{') {
                    Stack.pop();
                    continue;
                }
            }
        }
        Stack.push(exp[ix]);
    }

    while(!Stack.empty()) {
        char ch1 = Stack.top();
        Stack.pop();
        char ch2 = Stack.top();
        Stack.pop();

        if(ch2 == '}' && ch1 == '{')
            count += 2;
        else
            count++;
    }

    return count;
}
