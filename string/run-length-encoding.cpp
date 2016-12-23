/* Find the run length encoding of a string */

#include <iostream>
#include <string>

using namespace std;

string getRunLenEncoding(const string& text);

int main(void) {
    string textOne("sdeefffffkkk");
    cout << getRunLenEncoding(textOne) << endl;

    return 0;
}

string getRunLenEncoding(const string& text) {
    string str;
    string::const_iterator ch = text.cbegin();
    char currChar = *ch++;
    int charCount = 1;

    while(ch <= text.end()) {
        if(currChar == *ch) {
            charCount++;
        } else {
            str = str + currChar + to_string(charCount);
            currChar = *ch;
            charCount = 1;
        }

        ch++;
    }

    return str;
}
