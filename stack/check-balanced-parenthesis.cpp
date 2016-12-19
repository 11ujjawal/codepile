/* Check for balanced parenthesis */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBalance(const string& exp);
bool openParen(const char& ch);
bool closeParen(const char& ch);

int main(void) {
    string expOne("(a+b)*(c-d)");
    cout << expOne << " : " << checkBalance(expOne) << endl;

    string expTwo("}[(){}]");
    cout << expTwo << " : " << checkBalance(expTwo) << endl;

    return 0;
}

/* Check whether the given expression has balances parenthesis or not */
bool checkBalance(const string& expr) {
    stack<char> Stack;

    for(string::const_iterator ix = expr.begin(); ix != expr.end(); ++ix) {
        if(openParen(*ix))
            Stack.push(*ix);
        else if(closeParen(*ix)) {
            if(Stack.empty())
                return false;

            char parenValue = Stack.top();
            Stack.pop();

            if(!openParen(parenValue))
                return false;
        }
    }

    if(Stack.empty())
        return true;

    return false;
}

/* Check whether the given character has open parenthesis */
bool openParen(const char& ch) {
    if(ch == '(' || ch == '{' || ch == '[')
        return true;

    return false;
}

/* Check whether the given character has close parenthesis */
bool closeParen(const char& ch) {
    if(ch == ')' || ch == '}' || ch == ']')
        return true;

    return false;
}
