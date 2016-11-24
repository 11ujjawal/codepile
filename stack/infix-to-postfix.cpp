/* Convert the given expression from infix to postfix */

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

string infixToPostfix(string exp);
bool isOperand(char ch);
int precedence(char ch);

int main(void) {
    string exp("((a+b-c)*d/e)+f*(g+h)");
    cout << infixToPostfix(exp) << endl;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> Stack;
    string postfixExp;

    for(string::iterator iter = exp.begin(); iter != exp.end(); ++iter) {
        if(isOperand(*iter))
            postfixExp.push_back(*iter);
        else if(*iter == '(')
            Stack.push(*iter);
        else if(*iter == ')') {
            while(!Stack.empty() && Stack.top() != '(') {
                postfixExp.push_back(Stack.top());
                Stack.pop();
            }
            Stack.pop();
        } else {
            while(!Stack.empty() && precedence(Stack.top()) >= precedence(*iter)) {
                postfixExp.push_back(Stack.top());
                Stack.pop();
            }
            Stack.push(*iter);
        }
    }

    while(!Stack.empty()) {
        postfixExp.push_back(Stack.top());
        Stack.pop();
    }

    return postfixExp;
}

bool isOperand(char ch) {
    return isalpha(ch);
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
