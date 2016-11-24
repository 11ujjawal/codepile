/* Reverse a string using stack */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseString(string str);

int main(void) {
    string str("Hello World!!!");
    cout << reverseString(str) << endl;
    return 0;
}

string reverseString(string str) {
    stack<char> Stack;
    string revStr;

    for(string::iterator iter = str.begin(); iter != str.end(); ++iter)
        Stack.push(*iter);

    while(!Stack.empty()) {
        revStr.push_back(Stack.top());
        Stack.pop();
    }

    return revStr;
}
