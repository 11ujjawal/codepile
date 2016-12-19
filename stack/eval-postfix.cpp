/* Evaluate a postfix expression */

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int evalPostfix(string exp) {
    stack<int> Stack;

    for(string::iterator iter = exp.begin(); iter != exp.end(); ++iter) {
        if(isdigit(*iter)) {
            Stack.push(*iter);
        }
        else {
            int num1 = Stack.top() - '0';
            Stack.pop();
            int num2 = Stack.top() - '0';
            Stack.pop();

            switch(*iter) {
                case '+': Stack.push('0' + (num2 + num1)); break;
                case '-': Stack.push('0' + (num2 - num1)); break;
                case '*': Stack.push('0' + (num2 * num1)); break;
                case '/': Stack.push('0' + (num2 / num1)); break;
            }
        }
    }
    return Stack.top() - '0';
}

int main(void) {
    string exp("123*+5-");
    cout << evalPostfix(exp) << endl;
    return 0;
}
